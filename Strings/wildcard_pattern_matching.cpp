Wildcard string pattern matching:-(similar to lcs)
=================================
Given two strings 'str' and a wildcard pattern 'pattern' of length N and M respectively,  You have to print '1' if the wildcard pattern is matched with str else print '0' .

The wildcard pattern can include the characters ‘?’ and ‘*’
‘?’ – matches any single character
‘*’ – Matches any sequence of characters (including the empty sequence)

Note: The matching should cover the entire str (not partial str).

==========================================================================
Efficient solution:- O(M x N) (DP APPROACH)
=================
int wildCard(string pattern,string str)
    {
        int n = str.length();
        int m = pattern.length();
        
        if(m==0 && n==0)
        return 1;
        
        bool dp[n+1][m+1];
        memset(dp,false,sizeof(dp));
        
        // empty pattern can match with empty pattern        ******   vvvvimp
        dp[0][0] = true;
        
        //only *  can match with 1st row (i.e., empty str) also hen it occurs first
        for(int j=1;j<=m;j++) {
        if(pattern[j-1] == '*')
        dp[0][j] = dp[0][j-1];
        }
        // lets start filling
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){          
                if(pattern[j-1] == '?' || str[i-1]==pattern[j-1])
                dp[i][j] = dp[i-1][j-1];
                
                else if(pattern[j-1]=='*')
                dp[i][j] = (dp[i-1][j] || dp[i][j-1]);     see here it will use boolean or( t rue- false = true)
                
                else
                dp[i][j]=false;
        } 
        }
        
        if(dp[n][m] == true)
        return 1;
        else
        return 0;
        
    }
};

===============================================================

RECURSION APPROACH:- (Exponential time)

===refer in note==