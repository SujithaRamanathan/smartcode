The Painter's Partition Problem:-  (SAME AS BOOK ALLOCATION PROBLEM) refer
-------------------------------------------
Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.

Example 1:

Input:
n = 5
k = 3
arr[] = {5,10,30,20,15}
Output: 35
Explanation: The most optimal way will be:
Painter 1 allocation : {5,10}
Painter 2 allocation : {30}
Painter 3 allocation : {20,15}
Job will be done when all painters finish
i.e. at time = max(5+10, 30, 20+15) = 35
Example 2:

Input:
n = 4
k = 2
arr[] = {10,20,30,40}
Output: 60
Explanation: The most optimal way to paint:
Painter 1 allocation : {10,20,30}
Painter 2 allocation : {40}
Job will be complete at time = 60

--------------------------------------------------------------------------------------

class Solution
{
    public:
    
    bool canPaint(int arr[], int n, int k,long long barrier){
        long count = 1;                 // use long long
        long long sum = 0;
        for(int i=0;i<n;i++){
            if(arr[i] > barrier)
            return false;
             if(sum + arr[i] > barrier) {
                count++;
                sum = arr[i];
                if(count > k)
                return false;
            }
            
            else
            sum += arr[i];
        }
        return true;
    }
   
    long long minTime(int arr[], int n, int k)
    {
        
        long long l = arr[0];                    //  no sort is needed
        long long sum = 0;
        for(int i = 0;i<n;i++)
        sum += arr[i];
        
        long long h = sum;
        long long res;
        
        while(l<=h){
            long long mid = (l+h)/2;
            
            if(canPaint(arr,n,k,mid)){
                res = mid;
                h = mid-1;
            }
            else
            l = mid + 1;
        }
        
        return res;
    }
};