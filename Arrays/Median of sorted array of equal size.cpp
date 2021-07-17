#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int median(int[],int);


Median of Sorted arrays of equal size:-
===========================================

3 METHODS:-
-------------

1.By taking union w/o extra space) - O(NLOGN)
2.MERGE() OF MERGE SORT - O(N)
3.COMPARING MEDIANS (divide & conquer)- O(LOGN)

--------------------------------------------------------------



2).COMPARING MEDIANS (divide & conquer)- O(LOGN)
====================================================
int getMedian(int a[],int b[],int n) {

  if(n<=0)                    // BASE CASE 1
  return -1;

 if(n==1)                      // BASE CASE 2
 return (a[0] + b[0])/2;

 if(n==2)                       // BASE CASE 3
  return  (max(a[0],b[0]) + min(a[1] , b[1]))/2;

int m1 = median(a,n);
int m2 = median(b,n);
if(m1==m2)                    // BASE CASE 4
return m1;

if(m1 < m2) {            // IF M1<M2 (IGNORING LEFT PORTION OF M1 & RIGHT PORTION OF M2 )
 if(n%2 == 0)
      return getMedian(a + n/2 - 1,b, n - n/2 + 1); // EVEN MEANS FROM M1 AND ITS BEFORE
return getMedian(a+n/2,b,n-n/2);
}

if(m2 < m1) {           // IF M2<M1 (IGNORING LEFT PORTION OF M2 & RIGHT PORTION OF M1 )
 if(n%2 == 0)
      return getMedian(b + n/2 - 1,a, n - n/2 + 1);
return getMedian(b+n/2,a,n-n/2);
}

}


int median(int a[],int n) {
                   int n1 = n/2;
                   int ans;
                if(n%2 == 0) {
                ans = a[n1] + a[n1 -1];
                return ans/2 ;}
        else 
                return a[n1];

        }
==========================================================================================


2) MERGE METHOD:-

Approach:-

for eg:- a[] = (1,2,3)  b[]= (2,4,6) i=0;j=0;
	m1     -    m2
	
	-1     |   -1
1<2     m1 = m2
`	m2 = a[i]
	literally,m2 transfer its value to m1(to maintain prev element) and m2 takes current smaller value
         -1    |  1
i++
2 = 2     1    |  2
i++
3>2       2    |  2
j++  
3<4       2     |  3
i++ here i reached n 
	 m1=m2;
	 m2=b(0);
see,here we if i reached n first then the second arr is b .so we have to take its first ele as m2.
if j reached n first,then m2 = a[0];

=================================================================================================================   


   int i = 0;  /* Current index of i/p array ar1[] */
    int j = 0; /* Current index of i/p array ar2[] */
    int count;
    int m1 = -1, m2 = -1;
 
    /* Since there are 2n elements, median will be average
     of elements at index n-1 and n in the array obtained after
     merging ar1 and ar2 */
    for (count = 0; count <= n; count++)
    {
        /*Below is to handle case where all elements of ar1[] are
          smaller than smallest(or first) element of ar2[]*/
        if (i == n)
        {
            m1 = m2;
            m2 = ar2[0];
            break;
        }
 
        /*Below is to handle case where all elements of ar2[] are
          smaller than smallest(or first) element of ar1[]*/
        else if (j == n)
        {
            m1 = m2;
            m2 = ar1[0];
            break;
        }
         /* equals sign because if two
            arrays have some common elements */
        if (ar1[i] <= ar2[j])
        {
            m1 = m2;  /* Store the prev median */
            m2 = ar1[i];
            i++;
        }
        else
        {
            m1 = m2;  /* Store the prev median */
            m2 = ar2[j];
            j++;
        }
    }
 
    return (m1 + m2)/2;
}


===============================================================

3)UNION W/O XTRA SPACE

Approach:-
just swapping all the smaller elements to first arr (segregating thgem)
then sort it
find median as
 a[n-1] + b[0] / 2;

   int j = 0;
    int i = n - 1;
    while (ar1[i] > ar2[j] && j < n && i > -1)
        swap(ar1[i--], ar2[j++]);
    sort(ar1, ar1 + n);
    sort(ar2, ar2 + n);
    return (ar1[n - 1] + ar2[0]) / 2;

======================================================