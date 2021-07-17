Transforming one string to another 
find the minimum no of operations



O(N):-
============
#include<bits/stdc++.h>
using namespace std;
int minops(string& a,string& b) {
        int m = a.length();
        int n = b.length();

        if(n!=m)         // here checking two have same length
                return -1;
        int count[256];
        memset(count,0,sizeof(count));
        for(int i=0;i<n;i++)
                count[a[i]]++;
        for(int i=0;i<n;i++)
                count[b[i]]--;          // by maintaining the count array of str1 and destructing it with str2 
                                         // at last we are checking whethrr count is balanced and neutral. so that str1 & str2 have same characters too.
        for(int i=0;i<256;i++) {

        if(count[i])
                return -1; }


        //this part is to check mini operations
        int res=0;
        for(int i=n-1,j=n-1;i>=0; )
        {
                while(i>=0 and a[i] != b[j])
                {
                        i--;
                        res++;
                }

                if(i>=0) {
                        i--;
                        j--;
                }
        }
        return res;
}


int main() {

        string A = "ABD";
        string B = "BAD";
	 cout << minops(A,B) << endl;
        return 0;
}