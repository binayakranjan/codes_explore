#include<iostream>
#include<vector>
#include<deque>
#include<climits>
using namespace std;

void findMaxInASlidingWindow(vector<int> &numVec, unsigned int windowSize)
{
    if(windowSize <= 0) return;

    if(windowSize >= numVec.size())
    {
        int max = INT_MIN;
	for(auto it = numVec.begin(); it != numVec.end(); it++)
	{
	    if(max < *it)
	    {
	        max = *it;
	    }
	}

	cout << " max : " << max << endl;
    }
    else
    {
	    deque<int> dq;

	    for(auto i = 0; i < windowSize; i++)
	    {
		    while(!dq.empty() && numVec[dq.back()] <= numVec[i])
		    {
			    dq.pop_back();
		    }
		    dq.push_back(i);
	    }

	    for(auto i= windowSize; i < numVec.size(); i++)
	    {
		    //Print the max of the previous window
		    cout << " max so far : " << numVec[dq.front()] << endl;

		    //Remove the elements which are not part of this window, ??
		    while(!dq.empty() && dq.front() <= i-windowSize)
		    {
			    dq.pop_front();
		    }

		    while(!dq.empty() && numVec[dq.back()] <= numVec[i])
		    {
			    dq.pop_back();
		    }

		    dq.push_back(i);
	    }

	    //Print the max of the last window
	    cout << " max so far : " << numVec[dq.front()] << endl;

    }
}

int main()
{
    //vector<int> numVec = {-4,2,-5,3,6};
    //vector<int> numVec = {9,8,7,6,5,4,3,2,1};
    vector<int> numVec = {1,2,3,4,5,6,7,8,9};

    unsigned int windowSize = 3;

    findMaxInASlidingWindow(numVec,windowSize);

    return 0;
}
