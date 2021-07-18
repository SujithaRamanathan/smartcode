Merge array without xtra space:-
================================
Given two sorted arrays, we need to merge them in O((n+m)*log(n+m)) time with O(1) extra space into a sorted array, when n is the size of the first array, and m is the size of the second array.

=================================
Naive approach:- using xtra space:-
-------------------------------------------------
create a new array of size O(n+m)
put the elements from a1 to new array    O(N)
put the elements from a2 to new array   O(N)
now sort the array O(nlogn)
then now one by one transfer from new array to a1 and a2

===================================================
Appproach 2 :- INSERTION SORT TYPE
=============--------------------===============

traverse first array alone 
compare the elements of a1 with first element of a2
if smaller element in a2 then swap it
after swapping need to sort it. VVVVIMP***********
again compare
===================================================================
Approach 3:- Efficient Approach:- GAP method ( Shell sort)
=========================================================
first gap = ceil((n+m)/2) // 
if(gap <= 1)
retrun 0;
return gap/2 + gap%2; // equivalent to ceil value

Then for each gap,
we have three for loops for checking sequentiall after a1 , a1 & a2 combined and at last a2
when j >n-1, then need to update gap
when gap becomes 1,we sholud stop the outermost gap loop.
(see 1 can be returned once in that gap find function) 

======================================================
  First example: 
a1[] = {3 27 38 43}, 
a2[] = {9 10 82}
Start with 
gap =  ceiling of n/2 = 4 
[This gap is for whole merged array]
3 27 38 43   9 10 82 
3 27 38 43   9 10 82
3 10 38 43   9 27 82

gap = 2:
3 10 38 43   9 27 82
3 10 38 43   9 27 82
3 10 38 43   9 27 82 
3 10 9 43   38 27 82
3 10 9 27   38 43 82

gap = 1:
3 10 9 27   38 43 82
3 10 9 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
3 9 10 27   38 43 82
Output : 3 9 10 27 38 43 82

Second Example: 
a1[] = {10 27 38 43 82}, 
a2[] = {3 9}
Start with gap = ceiling of n/2 (4):
10 27 38 43 82   3 9 
10 27 38 43 82   3 9
10 3 38 43 82   27 9
10 3 9 43 82   27 38

gap = 2:
10 3 9 43 82   27 38
9 3 10 43 82   27 38
9 3 10 43 82   27 38
9 3 10 43 82   27 38
9 3 10 27 82   43 38
9 3 10 27 38   43 82

gap = 1
9 3 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82
3 9 10 27 38   43 82


Output : 3 9 10 27 38   43 82      

code:-
=======
int nextGap(int gap)
{
    if (gap <= 1)
        return 0;
    return (gap / 2) + (gap % 2);
}
 
void merge(int* arr1, int* arr2, int n, int m)
{
    int i, j, gap = n + m;
    for (gap = nextGap(gap);
         gap > 0; gap = nextGap(gap))
    {
        // comparing elements in the first array.
        for (i = 0; i + gap < n; i++)
            if (arr1[i] > arr1[i + gap])           // arr 1
                swap(arr1[i], arr1[i + gap]);
 
        // comparing elements in both arrays.
        for (j = gap > n ? gap - n : 0;
             i < n && j < m;
             i++, j++)
            if (arr1[i] > arr2[j])                    // arr1 and arr2
                swap(arr1[i], arr2[j]);
 
        if (j < m) {
            // comparing elements in the second array.
            for (j = 0; j + gap < m; j++)
                if (arr2[j] > arr2[j + gap])                 // arr2 alone
                    swap(arr2[j], arr2[j + gap]);
        }
    }
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       