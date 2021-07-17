EDIT DISTANCE:-(VVVVEASY IN DP)(SIMILAR TO LCS)
===========================================================

here,if two chars match,dp[i][j] = dp[i-1][j-1];
if dont match,dp[i][j] = 1 + min( dp[i-1][j-1],min( dp[i][j-1], dp[i-1][j])

============================================================

Tc: O(M x N)
Sc:O(M x N)  (dp table - bottom up approach)

============================================================




int editDistance(string s, string t) {
        int n = s.length();
        int m = t.length();
        int dp[n+1][m+1];
        
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0)                                              
                dp[i][j]=j;                                           // in 0th row check carefully,we dont put zeroes
                else if(j==0)
                dp[i][j]=i;                                               //  ''''''''
                else if(s[i-1] == t[j-1])
                dp[i][j]=dp[i-1][j-1];
                else
                dp[i][j] = 1 + min(dp[i-1][j-1], min(dp[i-1][j],dp[i][j-1]));
            }
                
            }
        return dp[n][m];
        }
    