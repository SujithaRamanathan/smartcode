Given an array of n distinct elements. Find the minimum number of swaps required to sort the array in strictly increasing order.
Example 1:

Input:
nums = {2, 8, 5, 4}
Output:
1
Explaination:
swap 8 with 4.
==================================================

  4     3     2    1

Efficient approach:-
think of cycles and make count:-  O(NLOGN)
============================================


           int minSwaps(vector<int>&nums)
	{
	    int n = nums.size();
	    pair<int,int>arrpos[n];             // make an array which store pair
	    
	    for(int i=0;i<n;i++) {
	    arrpos[i].first = nums[i];          // first - the element itself
	    arrpos[i].second = i;                   // second - the index in which originally appearing i the given array
	    }
	    
	    sort(arrpos,arrpos+n);              // sort arrpos according to first value (here,please note the second values not                                                                                   change for those first values.
	    
	    vector<bool>v(n, false);            // created one visited array make all indexes as FALSE
	    int ans = 0;
	    for(int i=0;i<n;i++){             // traverse
	        
	        if(v[i] or arrpos[i].second == i)          // checking already visited or correctly placed inthe position
	        continue;                 
	        
	        int cycles = 0;
	        int j = i;
	        while(!v[j]){                               // we are cycling with j = arrpos.second values until already visited
	            v[j] = true;
	            j = arrpos[j].second;
	            cycles++;
	        }
	        
	        if(cycles >0)
	        ans += (cycles -1);                     // think of edges 2 edges need one swap( so reducing one)
	        
	    }
	    return ans;
	}