Find repeating and missing
=============================
Given an unsorted array of size n. Array elements are in the range from 1 to n. One number from set {1, 2, …n} is missing and one number occurs twice in the array. Find these two numbers.

Examples: 

 Input: arr[] = {3, 1, 3}
Output: Missing = 2, Repeating = 3
Explanation: In the array, 
2 is missing and 3 occurs twice 

=============================================
several methods :- Refer note
==============================

Method 1 (Use Sorting)
Approach: 

Sort the input array.
Traverse the array and check for missing and repeating.
Time Complexity: O(nLogn)
============================================================
Method 2 (Use count array)
Approach: 

Create a temp array temp[] of size n with all initial values as 0.
Traverse the input array arr[], and do following for each arr[i] 
if(temp[arr[i]] == 0) temp[arr[i]] = 1;
if(temp[arr[i]] == 1) output “arr[i]” //repeating
Traverse temp[] and output the array element having value as 0 (This is the missing element)

Time Complexity: O(n)
Auxiliary Space: O(n)
=================================================================
Method 3:- Efficient
Traverse the array. While traversing, use the absolute value of every element as an index and make the value at this index as negative to mark it visited. If something is already marked negative then this is the repeating element. To find missing, traverse the array again and look for a positive value.
void printTwoElements(int arr[], int size)
{
    int i;
    cout << " The repeating element is ";
  
    for (i = 0; i < size; i++) {
        if (arr[abs(arr[i]) - 1] > 0)
            arr[abs(arr[i]) - 1] = -arr[abs(arr[i]) - 1];
        else
            cout << abs(arr[i]) << "\n";              // still negative is repeating
    }
  
    cout << "and the missing element is ";
    for (i = 0; i < size; i++) {
        if (arr[i] > 0)                                          // once again traverse and find positive then i+1 
            cout << (i + 1);
    }
}

==========================================================
Method 4:-
Equation method:-

we need to find sum of natural numbers upto N
then sum of squares of natural numbers upto N

then traverse the array and start decrementing both the values

after ,
missing element =  (a + b/a)/2;
repeating element = missing element - a;
======================================================================

vector<int>repeatedNumber(const vector<int> &A) {
    long long int len = A.size();
    long long int Sum_N = (len * (len+1) ) /2, Sum_NSq = (len * (len +1) *(2*len +1) )/6;
    long long int missingNumber=0, repeating=0;
      
    for(int i=0;i<A.size(); i++){
       Sum_N -= (long long int)A[i];
       Sum_NSq -= (long long int)A[i]*(long long int)A[i];
    }
      
    missingNumber = (Sum_N + Sum_NSq/Sum_N)/2;
    repeating= missingNumber - Sum_N;
    vector <int> ans;
    ans.push_back(repeating);
    ans.push_back(missingNumber);
    return ans;
      
}
  



