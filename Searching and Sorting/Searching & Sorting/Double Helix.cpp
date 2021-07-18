DOUBLE HELIX PROBLEM:-
------------------------------------------
Two ﬁnite, strictly increasing, integer sequences are given. Any common integer between the two sequences constitute an intersection point. Take for example the following two sequences where intersection points are
printed in bold:

First= 3 5 7 9 20 25 30 40 55 56 57 60 62
Second= 1 4 7 11 14 25 44 47 55 57 100

You can ‘walk” over these two sequences in the following way:

You may start at the beginning of any of the two sequences. Now start moving forward.
At each intersection point, you have the choice of either continuing with the same sequence you’re currently on, or switching to the other sequence.
The objective is ﬁnding a path that produces the maximum sum of data you walked over. In the above example, the largest possible sum is 450, which is the result of adding 3, 5, 7, 9, 20, 25, 44, 47, 55, 56, 57, 60, and 62

Input
Your program will be tested on a number of test cases. Each test case will be speciﬁed on two separate lines. Each line denotes a sequence and is speciﬁed using the following format:

n v1 v2 ... vn
Where n is the length of the sequence and vi is the ith element in that sequence. Each sequence will have at least one element but no more than 10,000. All elements are between -10,000 and 10,000 (inclusive).
The last line of the input includes a single zero, which is not part of the test cases.

Output
For each test case, write on a separate line, the largest possible sum that can be produced.

------------------------------------------------------------------------------------------------------------------------------------
We are having dynamic and binary search approaches too...
but two ptr approach seems very easy and efficient enough..
--------------------------------------------------------------------------------------------

Two ptr Approach:- O(M+N)
--------------------------------------------------
#include <iostream>
using namespace std;

int main() {
     int n,m;
     cout << " enter n and m" << endl;
     cin >> n >> m;
     int a[n];
     int b[m];
     for(int i =0;i<n;i++)
     cin >> a[i];
     for(int i =0;i<m;i++)
     cin >> b[i];
     
     int i = 0;
     int j = 0;
    
	 int sum1=0,sum2=0;                        // maintain two sum variables for each array
     
     while(i<n and j<m){
         if(a[i] < b[j])
         sum1 += a[i++];                                           // if 1st array element is smaller..add that into sum1 i++ alone
         
         else if(b[j] < a[i])
         sum2 += b[j++];                                          // if 2nd array element is smaller add that into sum2   j++ alone
         
         else {
             sum1 += a[i];                                             // if we encounter common intersection then add the elements into thier corresponding sums
                                                                                       and update sum variables  as max(sum1,sum2)
             sum2 += b[j];
             
             int tmp = max(sum1,sum2);
             sum1 = tmp;
             sum2 = tmp;
             
             i++;                                                    // increment both i and j
             j++;
         
         
            }
     }
     // see here the above while loop may break because of any one array got over ...but there may be elements in the other array


  while(i<n)
     sum1 +=a[i++];                               so adding if elements present in array a
     
     while(j<m)
     sum2 += b[j++];                              so adding if elements present in array b
         
     cout << max(sum1,sum2) << endl;                   hence,the final answer is max(sum1,sum2)

     
return 0;
}
