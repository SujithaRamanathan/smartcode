First and last occurrences of x :-
================================
Given a sorted array arr containing n elements with possibly duplicate elements, the task is to find indexes of first and last occurrences of an element x in the given array.
Example 1:

Input:
n=9, x=5
arr[] = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }
Output:  2 5
Explanation: First occurrence of 5 is at index 2 and last
             occurrence of 5 is at index 5.

==============================================================

app 1:- O(N) 
int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (x != arr[i])
            continue;
        if (first == -1)    // update first for first occurence
            first = i;
        last = i;             // keep updating last so last occurence will get
    }

========================================================================

app 2:-O(LOGN):-

iterative binary search:-
==========================

int solve(int a[],int x,int n,int tog){
    int l = 0;                                   |- toggle value to decide for which either last / first
    int h = n-1;
    int res=-1;
    while(l<=h){
        int mid=  (h+l)/2;
        if(a[mid] > x)
        h = mid-1;
        
        else if(a[mid] < x)
        l=mid+1;
        
        else {
           res = mid;                   // VVVIMP (store mid value not a[mid]
            if(tog==-1) 
            h = mid+tog;           // decide here
             else
              l= mid+tog;
        }
    }
  return res; 
}
vector<int> find(int arr[], int n , int x )
{
    vector<int>find;
    int a = solve(arr,x,n,-1);
    int b = solve(arr,x,n,1);
    find.push_back(a);
    find.push_back(b);
    return find;
}
=============================================================
app 3 O(N):-
USING C++ STL:-

  first = lower_bound(arr, arr + n, x) - arr;
    // to store last occurrence
    last = upper_bound(arr, arr + n, x) - arr - 1;
 
    if (first == n) {
        first = -1;
        last = -1;
   }

============================================================================