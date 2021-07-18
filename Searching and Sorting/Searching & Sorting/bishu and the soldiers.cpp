Bishu and the Soldiers:-
===========================
Problem
Bishu went to fight for Coding Club. There were N soldiers with various powers. There will be Q rounds to fight and in each round, Bishu's power will be varied. With power M, Bishu can kill all the soldiers whose power is less than or equal to M(<=M). After each round, All the soldiers who are dead in the previous round will reborn. Such that in each round there will be N soldiers to fight. As Bishu is weak in mathematics, help him to count the number of soldiers that he can kill in each round and the total sum of their powers.

INPUT:

The first line of the input contains N, the number of soldiers.

The second line contains an array of N numbers denoting the power of each soldier

This third line contains Q, which denotes the number of rounds.

Q lines follow, each line having one number denoting the power of Bishu.

OUTPUT:

For each round, the output should be an array of two numbers. The first number should be the number of soldiers that Bishu can beat, and the second number denotes the cumulative strength of all the soldiers that Bishu can beat.
====================================================================================================



#include<bits/stdc++.h>
using namespace std;
int main() {
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        cin >> a[i];

        sort(a,a+n);                // sort
        int q;
        cin >> q;

        int pre[n+1];                // for that cumulative
        pre[0] = 0;                       // first element may not contain prefix sum;

        for(int i=1;i<=n;i++)
        pre[i] = pre[i-1] + a[i-1];
        
while(q--) {
                int x;
                cin >> x;
                int idx = upper_bound(a,a+n,x) - a;          /// VVVVIMP UPPER_BOUND -> it returns the no of elements <= given                                                                                                value
                cout << idx << " " << pre[idx] << endl;                 // pre[idx] since 1 based indexing
        }

        return 0;
}