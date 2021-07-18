Search in a Rotated Sorted Array 
Easy 
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A.
==========================================================
Example 1:

Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
Output:
5
Explanation: 10 is found at index 5.


===============================================================
in the before approach we do two traversals one for pivot element and the other for target
=====================================================================================
by avoiding that 
===================
Very easy approach :- O(LOGN) ( 1 TRAVERSAL FOR FINDING THE ELEMENT)

=================================================================================
 int search(int a[], int l, int h, int key){
    int mid = (l + h)/2;
    while(l<=h) {
    if(a[mid] == key)
    return mid;

else if(a[mid] >= a[low] ) {
    if(key <= a[mid] and key >= a[low])
    h=mid-1;
    else
    l=mid+1;
    }
    
    else {
    if(key <= a[high] and key >= a[mid])
    l = mid+1;
    else
    r = mid - 1;}
    
    }
    return -1;
    }
};
