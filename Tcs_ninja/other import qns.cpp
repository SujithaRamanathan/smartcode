Other important questions:-
----------------------------------------

1) isnan(x) ---> true if x is not a numeric.
2) count freq of char and return char with max freq 

#include<iostream>
using namespace std;

int main() {
        string str;
        cin >> str;
        char ans;
        int max = 0;
        int count[256];
        for(int i=0;i<str.length();i++) {
                count[str[i]]++;
                if(count[str[i]] > max) {
                        max = count[str[i]];
                        ans = str[i];
                }
        }
        cout << ans << endl;
        return 0;
}