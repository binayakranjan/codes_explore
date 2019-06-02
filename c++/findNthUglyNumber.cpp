/*Ugly Number :    2 ^ a * 3 ^ b * 5 ^ c
 * The series is  1, 2, 3, 4, 5, 6, 8, 9, ......*/

#include<iostream>
using namespace std;

unsigned int findNthUglyNumber(unsigned int N)
{
    unsigned int *ugly = new unsigned int[N];
    ugly[0] = 1;
    unsigned int currPowerOf2 = 2, currPowerOf3 = 3, currPowerOf5 = 5;
    unsigned int currIndexOf2 = 0, currIndexOf3 = 0, currIndexOf5 = 0;
    unsigned int minimum = 1;

    unsigned int i=1;
    while( i < N)
    {
        minimum = min(currPowerOf2, min(currPowerOf3,currPowerOf5));
        ugly[i] = minimum;

        if(minimum ==  currPowerOf2)
        {
                currIndexOf2 += 1;
                currPowerOf2 = ugly[currIndexOf2] * 2;
        }
        if (minimum == currPowerOf3)
        {
                currIndexOf3 += 1;
                currPowerOf3 = ugly[currIndexOf3] * 3;
        }
        if(minimum == currPowerOf5)
        {
            currIndexOf5 += 1;
            currPowerOf5 = ugly[currIndexOf5] * 5;
        }

        i++;
    }

    return ugly[N-1];
}

int main()
{
    for(unsigned int i=1;i<10;i++)
    {
        cout <<  i << "-th Ugly Number : " << findNthUglyNumber(i) << endl;
    }
    return 0;
}
