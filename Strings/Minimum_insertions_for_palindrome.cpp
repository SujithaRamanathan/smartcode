MINIMUM NO OF INSERTIONS TO MAKE A STRING PALINDROME:-
===========================================================================

Input: str = "abcd"
Output: 3
Explanation: Inserted character marked
with bold characters in dcbabcd

Input: str = "geeks"
Output: 3                        VVVVIMP

skgeegks
||        |
=================================================
EFFICIENT APPROACH (DP - SIMILAR TO LCS APPROACH)
TC : O(N2)
SC:O(N2)
======================================================================
  int countMin(string s1){
     int n = s1.length();
     string s2 = s1;
     reverse(s2.begin(),s2.end());
     
     int len = lcs(s1,s2,n);               /////// VVVVVVVVVVIMPORTANT
    // HERE ,WE SUBTRACTING LEN FROM TOTAL SIZE ===>INSERTIONS
     int insertions = n - len;
     return insertions;
    }
    
   int lcs(string s1,string s2,int n){
        int dp[n+1][n+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                if(i==0 or j==0)
                dp[i][j] = 0;
                else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
    
        return dp[n][n];
    }
====================================================================
O(N) APPROACH (BUT SUITS ONLY FOR INSERTIONS AT FRONT)    

NAIVE APPROACH:-
---------------------------

int countMin(string str){
    int count = 0;
    int flag = 0;
       while(str.length() > 0) {
        if(is_palindrome(str))
        {
            flag = 1;
            break;
        }
        
        else {
            count++;
            str.erase(str.begin() + str.length() -1);
        }
    }
    if(flag)
    return count;
    
    }
    
    bool is_palindrome(string s){
        int n = s.length();
        int i,j;
        for(i=0,j=n-1;i<=j;i++,j--){
            if(s[i] != s[j])
            return false;
        }
        return true;
            
        }
        
 };

========================================
