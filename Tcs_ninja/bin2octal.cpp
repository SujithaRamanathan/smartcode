#include<iostream>
#include<cmath>
using namespace std;

int main() {

                string str;
                cin >> str;
                int i = 0;
                int n = str.length();
                int b = n-1;
                int ans = 0;
                while(i<n) {
                        int x = str[i] - 48;
                        ans += (x * pow(2,b));
                        i++;
                        b--;
                }
                int a[32];
                i=0;
                while(ans != 0) {

                a[i] = ans%8;
                ans = ans/8;
                i++;
                }
                for(int j=i-1;j>=0;j--)
                        cout << a[j] ;


        return 0;
}