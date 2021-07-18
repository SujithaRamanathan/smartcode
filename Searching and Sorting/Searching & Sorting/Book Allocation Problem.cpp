Allocate minimum number of pages  (BOOK ALLOCATION PROBLEM)
====================================

You are given N number of books. Every ith book has Ai number of pages. 
You have to allocate books to M number of students. There can be many ways or permutations to do so. In each permutation, one of the M students will be allocated the maximum number of pages. Out of all these permutations, the task is to find that particular permutation in which the maximum number of pages allocated to a student is minimum of those in all the other permutations and print this minimum value. 

Each book will be allocated to exactly one student. Each student has to be allocated at least one book.

Note: Return -1 if a valid assignment is not possible, and allotment should be in contiguous order (see the explanation for better understanding).


Example 1:

Input:
N = 4
A[] = {12,34,67,90}
M = 2
Output:
113
Explanation: 
Allocation can be done in following ways:
{12} and {34, 67, 90} Maximum Pages = 191
{12, 34} and {67, 90} Maximum Pages = 157
{12, 34, 67} and {90}  Maximum Pages =113
Therefore, the minimum of these cases is 
113, which is selected as the output.


==========================================
Earlier Approaches:-
-------------------------------

Recursion,               Dynamic Programming
    |                                                |
O(Exponential)                   O(n2)

--------------------------------------------------------------------------

Efficient one:-  BINARY SEARCH - O(NLOGN)
============ -----------------------------------------------------
                                                                       |
n - for ispossible traversal
doing logn times as we are doing while each search

class Solution 
{
    public:
    //Function to find minimum number of pages.
    bool CanAllocate(int a[], int n, int m,int dist){
        int sum = 0;
        int count = 1;                    // indicating we are start to allocate for 1st student
        
        for(int i = 0;i<n;i++){
            if(a[i] > dist)                        // firstly,will check whether any element in the array itself greater than barrier ,simply                                                                  return false
            return false;
            if(a[i] + sum > dist) {            // case 1: if exceeds barrier then allocate to next student so count++; then allocate him with                                                             current book with a[i] pages 
                count++;
                sum = a[i];
                if (count > m)                  // see here only when we are allocating more than given students return false
                return false;
            }
            
            else
            sum = sum + a[i];                      // if not exceeds barrier then continue allocating with the current student.
            
        }
        
        return true;                                     // here its true only if count== all students or count < student and here we need to                                                                   return true so that search space decresed and barrier decreased so that we can assign                                                                      some more students
    
    }

========
    int findPages(int arr[], int n, int m)            // this function usual binary search
    {
        int l = arr[0];                                                   // minimum would be first element given array sorted
        
        int sum = 0;
        for(int i = 0;i<n;i++)
        sum += arr[i];
        int h = sum;                                           vvvvimp initialize high with sum value
        int res = -1;
        
        while(l<=h){
            int mid = (l+h)/2;
            if(CanAllocate(arr,n,m,mid)){                 // check can allocate
              res = mid;
              h = mid-1;                                                // check for lower values
            }
            else
            l = mid + 1;                              // if not possible to allocate increase barrier
        }
        
        return res;                         // VVVVimp return res
    }
    
    