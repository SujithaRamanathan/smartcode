Count triplets with sum smaller than a given value:-

Given an array of distinct integers and a sum value. Find count of triplets with sum smaller than given sum value. The expected Time Complexity is O(n2).
------------------------------------------------------------------
Naive approach:- O(n3)

int countTriplets(int arr[], int n, int sum)
{
    // Initialize result
    int ans = 0;
 
    // Fix the first element as A[i]
    for (int i = 0; i < n-2; i++)            // loop goes upto n-2   vvvvimp
    {
       // Fix the second element as A[j]
       for (int j = i+1; j < n-1; j++)         // loop goes upto n-1
       {
           // Now look for the third number
           for (int k = j+1; k < n; k++)             // loop goes upto n
               if (arr[i] + arr[j] + arr[k] < sum)
                   ans++;
       }
    }
 
    return ans;
}
---------------------------------------------------------------------------------------------------------------------

Efficient Approach:- O(N2):-
========================

1) Sort the input array in increasing order.
2) Initialize result as 0.
3) Run a loop from i = 0 to n-2.  An iteration of this loop finds all
   triplets with arr[i] as first element.
     a) Initialize other two elements as corner elements of subarray
        arr[i+1..n-1], i.e., j = i+1 and k = n-1
     b) Move j and k toward each other until they meet, i.e., while (j<k),
            (i) If arr[i] + arr[j] + arr[k] >= sum
                then k--
            // Else for current i and j, there can (k-j) possible third elements
            // that satisfy the constraint.
            (ii) Else Do ans += (k - j) followed by j++ 


                    sort(arr,arr+n);
	    long long count = 0;
	    for(int i=0;i<n-2;i++){
	        int l = i+1;
	        int r = n-1;
	        while(l<r){
	            int x = arr[i] + arr[l] + arr[r];
	            if(x >= sum)
	            r--; 
	            else {
	           count += (r-l);          VVVIMP....VVVVIMP
	           l++;
	            }
	            
	    }
	    }
	    
	    return count;

===============================================================================