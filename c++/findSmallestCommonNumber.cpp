#include<iostream>
#include<algorithm>
#include<iterator>
#include<vector>
using namespace std;

#if 0
int findSmallestCommonNum(int *arr1, int n1,
		          int *arr2, int n2,
			  int *arr3, int n3)
{
    int i=0,j=0,k=0;
    
    while(i < n1 && j < n2 && k < n3)
    {
	if(arr1[i] == arr2[j] && arr1[i] == arr3[k])
		return arr1[i];

	if(arr1[i] <= arr2[j] && arr1[i] <= arr3[k])
	{
		i++;
	}
	else if(arr2[j] <= arr1[i] && arr2[j] <= arr3[k])
	{
		j++;
	}
	else if(arr3[k] <= arr1[i] && arr3[k] <= arr1[i])
	{
		k++;
	}
    }

    return -1;
}
#endif

int findSmallestCommonNum(vector< vector<int> > &numVec)
{
    int numOfVecs = numVec.size();

    vector <int>   startOfVecs;
    vector <int>   endOfVecs;

    for(auto it = numVec.begin(); it != numVec.end(); it++)
    {
	    auto currVec = *it;
	    startOfVecs.push_back(0);
	    endOfVecs.push_back(currVec.size());
    }

    while(1)
    {
	    bool allSame = true;
	    
	    
	    //Find if all the count-th elements are same
	    int value = numVec[0][startOfVecs[0]];
	    
	    for(int count =0; count < numOfVecs; count++)
	    {
	        if(startOfVecs[count] == endOfVecs[count])
		{
		    return -1;
		}

		if(value != numVec[count][startOfVecs[count]])
		{
		    allSame = false;
		}
	    }

	    if(allSame == true)
	    {
		return value;
	    }

	    //Find the smallest amount the current considered elements
	    int smallest = numVec[0][startOfVecs[0]];
	    auto smallestItCount = 0;
	    
            for(int count =0; count < numOfVecs; count++)
	    {
	        if(startOfVecs[count] == endOfVecs[count])
		{
		    return -1;
		}

		if(smallest > numVec[count][startOfVecs[count]])
		{
		    smallestItCount = count;
		}
	    }

	    startOfVecs[smallestItCount]++;
    }
}

int main()
{
#if 0
	int arr1[] = {6,7,10,25,30,63,64};
	int arr2[] = {-1,4,5,6,7,8,50};
	int arr3[] = {1,6,10,14};

        int num = findSmallestCommonNum(arr1,sizeof(arr1)/sizeof(arr1[0]),
			      arr2,sizeof(arr2)/sizeof(arr2[0]),
			      arr3,sizeof(arr3)/sizeof(arr3[0])
			      );
#endif

	vector<int> numVec1= {6,7,10,25,30,63,64};
	vector<int> numVec2= {-1,4,5,7,8,10,50};
	vector<int> numVec3= {1,6,10,14};

	vector< vector<int> > numVec;
	numVec.push_back(numVec1);
	numVec.push_back(numVec2);
	numVec.push_back(numVec3);

        int num = findSmallestCommonNum(numVec);
	cout << " Smallest common num : " << num << endl;
	return 0;
}
