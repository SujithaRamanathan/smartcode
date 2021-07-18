
Zero sum subarray
==========================

You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.
Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

subarray - part of array which is contiguous;
==========================================================
Naive approacgh :_

checking all subarray sum = 0;
unordered_set<int> sumSet;
 
    // Traverse through array
    // and store prefix sums
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
 
        // If prefix sum is 0 or
        // it is already present
        if (sum == 0
            || sumSet.find(sum)
            != sumSet.end())
            return true;
 
        sumSet.insert(sum);
    }
    return false;
}

==================================
 








ll findSubarray(vector<ll> arr, int n ) {
        unordered_map<int,int>mp;
        mp[0] = 1;
        int sum = 0;
        ll ans = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];    
            if(mp.find(sum) != mp.end())
            ans += mp[sum];
            
            mp[sum]++; vvv imp
        }
        
        return ans;