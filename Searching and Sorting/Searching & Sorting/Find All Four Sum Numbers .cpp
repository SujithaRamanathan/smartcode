Find All Four Sum Numbers 
Medium Accuracy: 41.1% Submissions: 24818 Points: 4
Given an array of integers and another number. Find all the unique quadruple from the given array that sums up to the given number.

Example 1:

Input:
N = 5, K = 3
A[] = {0,0,2,1,1}
Output: 0 0 1 2 $
Explanation: Sum of 0, 0, 1, 2 is equal
to K.
Example 2:

Input:
N = 7, K = 23
A[] = {10,2,3,4,5,7,8}
Output: 2 3 8 10 $2 4 7 10 $3 5 7 8 $
Explanation: Sum of 2, 3, 8, 10 = 23,
sum of 2, 4, 7, 10 = 23 and sum of 3,
5, 7, 8 = 23.
Your Task:
You don't need to read input or print anything. Your task is to complete the function fourSum() which takes the array arr[] and the integer k as its input and returns an array containing all the quadruples in a lexicographical manner. Also note that all the quadruples should be internally sorted, ie for any quadruple [q1, q2, q3, q4] the following should follow: q1 <= q2 <= q3 <= q4.  (In the output each quadruple is separate by $. The printing is done by the driver's code)

Expected Time Complexity: O(N3).
Expected Auxiliary Space: O(N2).

==============================================================

 vector<vector<int> > fourSum(vector<int> &arr, int k) {
        int n = arr.size();
        sort(arr.begin(),arr.end());         /// SORTING ...SORTING IMP IMP ************************
       
       vector<vector<int>>res;            // to return ans
       

 for(int i=0;i<n;i++){                           // fix 1st ele
            for(int j = i+1;j<n;j++){            // fix 2nd ele
                int target = k-arr[i]-arr[j];
                
                int l = j+1;
                int r = n-1;
                
                while(l<r){                                        // same as find pairs with given sum
                    int sum = arr[l] + arr[r];
                    if(sum < target)
                    l++;
                    else if(sum>target)
                    r--;
                    else {
                        vector<int>q(4,0);
                        q[0] = arr[i];
                        q[1] = arr[j];
                        q[2] = arr[l];
                        q[3] = arr[r];
                        
                        res.push_back(q);
                        while(l<r and arr[l]==q[2])              // jumping over duplicates VVVIMP
                        ++l;
                        while(l<r and arr[r]==q[3])           // jumping over duplicates VVVIMP
                        --r;
                        
                    }
                     
                    
                }
                while(j+1 < n and arr[j+1]==arr[j])          // jumping over duplicates VVVIMP { check the brackets and put this}
                ++j;
                
            }
           while(i+1 < n and arr[i+1]==arr[i])         // jumping over duplicates VVVIMP { check the brackets and put this}
                ++i; 
        }
        
        return res;
    }