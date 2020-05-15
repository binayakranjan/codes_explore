class Solution:
    def kadane(self,a): 
        n = len(a)
        max_so_far = 0
        max_ending_here = 0
        for i in range(n): 
            max_ending_here = max_ending_here + a[i]
            if (max_ending_here < 0): 
                max_ending_here = 0
            if (max_so_far < max_ending_here):
                max_so_far = max_ending_here
        return max_so_far
    def maxSubarraySumCircular(self, A: List[int]) -> int:
        #To Handle the case where all the elements are negative
        #Then return the max of those
        maxEl = -sys.maxsize-1;
        flag = True
        for a in A:
            if a >= 0:
                flag = False
                break
            else:
                maxEl = max(maxEl,a)
        if flag:
            return maxEl
        
        n = len(A)
        
        # Case 1:  Max sum using kadane's algorithm
        max_kadane = self.kadane(A)
        
        # Case 2: Wrap up case
        max_wrap = 0
        for i in range(n):
            max_wrap += A[i]
            A[i] = -A[i]
        
        # Max sum with wrap up will be array-sum - (max subarray sum of inverted array)
        max_wrap = max_wrap + self.kadane(A)
        
        # The maximum circular sum will be maximum of two sums
        if max_wrap > max_kadane:
            return max_wrap
        else:
            return max_kadane 
