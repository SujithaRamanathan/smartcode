Count pairs with given sum :-
==============================

1)Naive approach O(N2)
2)Using hash map O(N) | O(N)

===================================

Using hash map O(N)

 int getPairsCount(int arr[], int n, int k) {
        unordered_map<int,int>m;
        for(int i=0;i<n;i++) m[arr[i]]++; // storing cur element into map such that map key is the array element and  value is the frequency of that element and then                                           incrementing map position.
        int count =0;
        for(int i=0;i<n;i++) {
         count += m[k - arr[i]];    // if the complement of curr ele for given sum is present then we add its element's frequency to the count
         if(k-arr[i] == arr[i])    // if actually the curr ele is doubled to sum .then we cant add that since it's a single ele not a pair.so decrement it.
         count--;    
        }
        return count/2;          // for eg., sum =6 arr={1,5,6}
    }                                 here,if we check for 1 complement will be 5 (so adding that pair)
                                      likewise,if we check for 5 ,comp will be 1(so add that pair too)
					but in the result we need to add one pair only (1,5) (5,1) = 2 / 2 = 1;

================================================================================================================