
BUY & SELL STOCK METHOD 1:- O(N)
=================================

approach:-

we cant buy stock of 0th index.so we traverse array from 1 to n only,
initialize buy ,sell with a[0];

if(current ele > prev ele && current element != buy)
we need to select the day which is best suit for selling the first stock (sell++)
also maintining flag to indicate that we had buy and sell something with the array. 

else if(buy == sell)
i.e when we have both buy and sell on same day we need to change the ptr to curr ele

epo namma sell panlam na when we reach an ele which is lower value than prev
then we put first index,prev index and making the buy and sell ptr to the current ele


=======================================================
 vector<vector<int> > stockBuySell(vector<int> A, int n){
        
         vector<vector<int>>v1;
         int buy=0,sell=0,flag=0;
        for(int i=1;i<n;i++){
            if(A[i]>=A[i-1] and A[i] != A[buy]){
                sell++;
                flag=1;
            }
            else if(buy==sell){
                buy=i;
                sell=i;
            }
            else {
                vector<int>v;
                v.push_back(buy);
                v.push_back(sell);
                v1.push_back(v);
                buy=i;
                sell=i;
            }
        }
        if(flag==0)
        return v1;
        else if(buy!=n-1 && sell == n-1){
            vector<int>v2;
                v2.push_back(buy);
                v2.push_back(sell);
                v1.push_back(v2);
               }
               
               return v1;
    }
};

==========================================================================================