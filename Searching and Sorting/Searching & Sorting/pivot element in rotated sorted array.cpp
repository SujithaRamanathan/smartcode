Find minimum / pivot element in a sorted rotated array
================================================================
Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

[4,5,6,7,0,1,2] if it was rotated 4 times.
[0,1,2,4,5,6,7] if it was rotated 7 times.
Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

Given the sorted rotated array nums of unique elements, return the minimum element of this array.

You must write an algorithm that runs in O(log n) time.

 

Example 1:

Input: nums = [3,4,5,1,2]
Output: 1
Explanation: The original array was [1,2,3,4,5] rotated 3 times.


==================================================================

Pivot element :-
--------------------------
Fact:-
Pivot element is the only element which is smaller than the previous element.

Approach 1:- O(N)
----------------------

Traverse the array one by one.
check if(a[i] > a[i+1])
return a[i+1]
else
i++; till i<n;
====================================================

Approach 2:O(LOGN)
Binary Search:
=============
class Solution {
public:
    int findMin(vector<int>& a) {
        
        int n = a.size();
       
        int start = 0;
        int end = n-1;
         if(a[0] <= a[n-1])
            return a[0]; 
        
  while(start <= end){
            
            int mid =  (end + start)/2;
           
            if(a[mid] > a[mid + 1]) {
                return a[mid+1];  }
           
            else if(a[mid] >= a[start]) {
                    start = mid+1;  }
            else  {
                end = mid - 1;
            }
                
                }
        
        return 0;
        
    }
};