#include<iostream>
#include<array>
using namespace std;

/* This method does NOT work for arrays with duplicate elements
 * as it is not possible to find an element in a array with duplicates always in log(N) time
 * for ex : consider searching 0 in {2, 2, 2, 2, 2, 2, 2, 2, 0, 2} and {2, 0, 2, 2, 2, 2, 2, 2, 2, 2, 2, 2}.
 *          It doesn't look possible to decide whether to recur for left half or right half by doing constant
 *          number of comparisons at the middle.*/

int searchInARotatedArrUtil(const array<int,20> &rotArr, int low, int high, int key)
{
	if(low > high)
		return -1;

	int mid = low + (high-low)/2;

	/* Scenario 1: rotArr[mid] is key
	 * Scenario 2: first half is rotated eg : {7,10,1,4,6} 
	 *             Scenario 2-1 : key = 10 i.e key is first  half
	 *             Scenario 2-2 : key = 4  i.e key is second half
	 * Scenario 3: second half is rotated eg : {4,6,7,10,1} 
	 *             Scenario 3-1 : key = 6 i.e key is first  half
	 *             Scenario 3-2 : key = 10  i.e key is second half
	 * Scenario 4: NOT rotated eg : {1,4,6,7,10} 
	 *             Scenario 4-1 : key = 4 i.e key is first  half
	 *             Scenario 4-2 : key = 7  i.e key is second half
	 */
	if (rotArr[mid] == key)
	{
		return mid;
	}

	/* No duplicates, but = case will come when low == mid*/
	
	/* Either 2nd half is rotated or NO rotation at all & rotArr[low] <= key <= rotArr[mid]*/
	/* Scenario 3-1, 4-1*/
	if (rotArr[low] <= rotArr[mid] && key <= rotArr[mid] && key >= rotArr[low]) {
		return searchInARotatedArrUtil(rotArr, low, mid-1, key);
	}
	/* Either first half is rotated or NO rotation at all & rotArr[mid] <= key <= rotArr[high]*/
	/* Scenario 2-2, 4-2*/
	else if (rotArr[mid] <= rotArr[high] && rotArr[mid] <= key && key <= rotArr[high] ) {
		return searchInARotatedArrUtil(rotArr, mid+1, high, key);
	}
	/* first half is rotated  & rotArr[low] <= key <= rotArr[mid]*/
	/* Scenario 2-1*/
	else if (rotArr[low] >= rotArr[mid]) {
		return searchInARotatedArrUtil(rotArr, low, mid-1, key);
	}
	/* second half is rotated  & rotArr[mid] <= key <= rotArr[high]*/
	/* Scenario 3-1*/
	else if (rotArr[high] <= rotArr[mid]) {
		return searchInARotatedArrUtil(rotArr, mid+1, high, key);
	}

	return -1;
}

int searchInARotatedArr(const array<int,20> &rotArr, int key)
{
	return searchInARotatedArrUtil(rotArr,0,rotArr.size()-1, key);
}	

int main()
{
	array<int,20> rotArr = {176,188,199,200,210,222,1,10,20,47,59,63,75,88,99,107,120,133,155,162};

	int key = 163;
	int index = searchInARotatedArr(rotArr, key);
	index != -1 ? cout << key << " found at " << index << endl : cout << key << " NOT found" << endl;

	return 0;
}
