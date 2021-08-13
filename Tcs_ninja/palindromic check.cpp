check palindrome string:-
-----------------------------------	
int isPlaindrome(string s)
	{
	    int n = s.length();
	    for(int i=0,j=n-1;i<j;i++,j--){
	        if(s[i]!=s[j]) {
	            return 0;
	            break;
	        }
	        
	        }
return 1;	        
	    }

======================================
Palindromic number:-
----------------------------

#include<iostream>
using namespace std;
int main() {
        int n;
        cin >> n;
        int a = n;
        int ans = 0;
        while(n!=0) {
                int r = n%10;
                ans = (ans*10) + r;
                n = n/10;
        }

        if(ans==a)
        cout << "palindrome" << endl;
        else
        cout << "not palindrome"<<endl;
        return 0;
}
