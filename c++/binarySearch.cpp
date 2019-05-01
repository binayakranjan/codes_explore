#include<iostream>
using namespace std;

int binarySearchUtil(int *arr, int key, int low, int high)
{
	while(low <= high)
	{
		int mid = low + (high - low)/2;
		if(arr[mid] == key)
			return mid;
		else if(arr[mid] > key)
		{
		    high = mid-1;
		}
		else
		{
		    low = mid+1;
		}
	}

	return -1;
}


int binarySearch(int *arr, int size, int key)
{
  return binarySearchUtil(arr,key,0,size-1);
}

int main()
{
   int arr[] = {1,10,20,47,59,63,75,88,99};
   int n = sizeof(arr)/sizeof(arr[0]);

   int key = 20;
   int index = binarySearch(arr, n, key);
   if (index != -1 )
	   cout << key << " is found at index : " << index << endl;
   
   key = 63;
   index = binarySearch(arr, n, key);
   if (index != -1 )
	   cout << key << " is found at index : " << index << endl;
   
   key = 99;
   index = binarySearch(arr, n, key);
   if (index != -1 )
	   cout << key << " is found at index : " << index << endl;
   
   key = 1;
   index = binarySearch(arr, n, key);
   if (index != -1 )
	   cout << key << " is found at index : " << index << endl;
   
   key = -1;
   index = binarySearch(arr, n, key);
   if (index == -1 )
	   cout << key << " is NOT found" << endl;

   return 0;
}
