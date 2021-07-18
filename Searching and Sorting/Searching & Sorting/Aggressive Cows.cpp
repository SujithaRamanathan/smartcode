Aggresive Cows:-
----------------------------
Problem Statement
Given an array of length ‘N’, where each element denotes the position of a stall. Now you have ‘N’ stalls and an integer ‘K’ which denotes the number of cows that are aggressive. To prevent the cows from hurting each other, you need to assign the cows to the stalls, such that the minimum distance between any two of them is as large as possible. Return the largest minimum distance.
============================================================
Approach 1:- O(n2)
------------------

Brute force:-
-------------------

for each min_dis = 1 to max min dist as a[n-1] - a[0]...
we have to check whether we can place the cows or not

athavathu min distance 1 vachu check pannu
then 2
.
.
. 
some value K  (if in this distance  we cant place all the cows then we have to output ans = k-1)

so this take O(n2)

-----------------------------------------------------------------------------------------------------------------

if 1,2,3,4 ( in 4 if we cant place means then with 5 also we cant place, 6,7,  .... not possible)
to decrease the search space we can use binary search)
---------------------------------------------------------------------------------------------------------------
Binary search:- O(nlogn)  -- n is for checking logn for searching
------------------------------------------------------------------------------------------
bool CanPlaceCows(vector<int> &a,int n, int k,int dist) {
    int pos = a[0];
    int count = 1;
    for(int i=1;i<n;i++){
        if(a[i] - pos  >= dist) {
            count++;
            pos = a[i];                         // update prev position
        }
        if(count == k)                      // at any point if count==cows
            return true;
    }
    return false;
}


int aggressiveCows(vector<int> &a, int k)
{
    int n = a.size();
    sort(a.begin(),a.end());                             // sorting is VVVVIMP for binary searching
    int l = 1;
    int h = a[n-1] - a[0];                                   // initializing l and h
    int res ;
    
    while(l<=h) {
        int mid = (l+h)/2;
        if(CanPlaceCows(a,n,k,mid)){
            res = mid;                                          // res value keeps updating for larger one
            l = mid + 1;
        }
        else
            h = mid - 1;
        
    }
    
    return res;
    
}