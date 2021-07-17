KMP ALGO:- V.V.V.V.VIMP 
REFER GEEKS FOR CODE
REFER NOTES FOR MORE INFO

1) PREPROCESS - LPS ARRAY
2) SCAN & MATCH PATTERN
==============================================

TC : O(N)
SC:O(M)
============================================
 vector <int> search(string pat, string text)
        {
            int n = text.length();
            int m = pat.length();
            vector<int>v;
            // preprocess
            int lps[m];
            computelps(pat,m,lps);
            int i =0;
            int j = 0;
            while(i<n){
                if(text[i] == pat[j]){
                    i++;
                    j++;
                }
                
                if(j==m){
                    v.push_back(i-j+1);
                    j = lps[j-1];
                }
                
                else if(i<n && pat[j] != text[i]){
                    if(j != 0)
                    j = lps[j-1];
                    else
                    i = i+1;
                }
            }
            vector<int>v1;
            v1.push_back(-1);
        if(v.size() == 0)
        return v1;
        else
            return v; 
        }
        
///PREPROCESS

void computelps(string pat,int m,int lps[]){
            int len = 0;
            int i=1;
            lps[0] = 0;
            while(i<m){
                if(pat[i] == pat[len]){
                    len++;
                    lps[i] = len;
                    i++;
                }
                else {
                    if(len != 0)
                        len = lps[len-1];
                    else { 
                    lps[i] = 0;
                    i++;
                    }
                    }
            }
}     


=======================================================================================