o(exponential time)-method 1-finding subsets and comparing minimum
o(n)-sort <<  i+m-1 < n



public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
    sort(a.begin(),a.end());
    long long mindifference=INT_MAX;
    for(int i=0;i+m-1<n;i++)
    {
        int d = a[i+m-1] - a[i];
       if(d<mindifference)
       mindifference = d;
    }
    return mindifference;
    
    }   
};