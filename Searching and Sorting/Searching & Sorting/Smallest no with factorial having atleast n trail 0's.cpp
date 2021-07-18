Smallest factorial number 
-----------------------------------------------------
Given a number n. The task is to find the smallest number whose factorial contains at least n trailing zeroes.

Example 1:

Input:
n = 1
Output: 5
Explanation : 5! = 120 which has at
least 1 trailing 0.
Example 2:

Input:
n = 6
Output: 25
Explanation : 25! has at least
6 trailing 0.


=================================================

BINARY SEAARCH APPROACH:-
becoz the max number with atleast n trailing 0's would be 5*n always
so,we need  to search for the minimum in the range 0 ------------- 5*n 


class Solution
{
    public:
    
    
        bool check(int p,int n){                  // func checks the given no's fatorial has n trail 0's or not
            int f = 5;
            int count = 0;
            
            while(f<=p){
                count += p/f;                   // how many times a number is divided by 5 and its multiples if possible would be the no of trailing 0's of                                                                  that factorial
                f = f*5;
            }
            if(count >= n)                  // if atleat so greater than or equal to
            return true;
            return false;
        }
        
        int findNum(int n)
        {
            if(n==1)                      if 1 simply return 5
            return 5;
        int l = 0;
        int h = n*5;
        
        while(l<h){                     // l<h so h = mid and return low only...don't forget VVVV imp
            int mid = (h+l)/2;
            if(check(mid,n))
            h = mid;
            else
            l=mid+1;
        }
        
        return l;
        }
};