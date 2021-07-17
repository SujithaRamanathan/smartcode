Rabin karp(pattern searching) ROLL HASH ALGO
simpe but need to remember the hash value formula

===============================================================
TC: O(MXN) WORST CASE (if all hash values same)
But it really reduces the avg time complexity
its applications : detecting plagiarism
==========================================================




 vector <int> search(string pat, string txt)
        {
            int  d = 256;
            int m = pat.length();
            int n = txt.length();
            int i,j;
            int p=0;
            int t=0;
            int h = 1;
            int q = 101;
            
            vector<int>v;
            
            // process h
            for(int i =0;i<m-1;i++)
              h = (h*d) % q;
            // hash values for pat & first window  
            for(i=0;i<m;i++){
                p = (d * p + pat[i])%q;
                t = (d * t + txt[i])%q;
            }
            
            for(i=0;i<=n-m;i++){ // sliding window and check
                if(p==t){
                    for(j=0;j<m;j++){
                        if(txt[i+j] != pat[j])
                        break;
                    }
                    if(j==m)
                    v.push_back(i+1);
                }
            
                
                else if(i<=n-m){
                    t = (d*(t-txt[i]*h) + txt[i+m])%q;
                    if(t<0)
                    t = t+q;
                }
                }
                
                
           vector<int>v1;
           v1.push_back(-1);
           if(v.size()==0)
           return v1;
           else
           return v;
           
            }