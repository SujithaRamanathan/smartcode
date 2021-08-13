#include<iostream>
using namespace std;

int main() {
        string str;
        cin >> str;

        int n = str.length();
        int a=0,b=0,i=0;

        while(n > 0) {
                if(i==0) {
                        a += str[n-1] - 48;
                        n--;
                        i=1;
                }
                else {
                        b += str[n-1] - 48;
                        n--;
                        i=0;
                }
        }

        cout << abs(a-b) << endl;
        return 0;
}
