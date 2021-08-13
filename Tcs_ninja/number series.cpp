Number series:-
==============
Ques. Find the 15th term of the series?

0,0,7,6,14,12,21,18, 28
================================
method 1:-
=======
#include<iostream>
using namespace std;

int main() {
        int n;
        cin >> n;
        int a[n+2];
        a[0] = 0;
        a[1] = 0;

        int i = 0;
        int j = 2;
        int b = 1;
        int c = 1;
        for(int k = 2;k<=n;k++) {
                if(i==0) {
                        a[j] = 7 * c;
                        c++;
                        j++;
                        i = 1;
                }
                else {
                        a[j] = 6 * b;
                        b++;
                        j++;
                        i=0;
                }
        }
        cout << a[n-1] << endl;
return 0;
}
------------------------------------------------------------
#include<iostream>
using namespace std;

int main() {
        int n;
        cin >> n;
        int a[n+3];
        a[0] = 0;
        a[1] = 0;
        a[2] = 7;
        int i = 0;
        int j = 3;
        int b = 2;
        int c = 1;
        for(int k = 3;k<=n;k++) {
                if(i==0) {
                        a[j] = a[j-1] - c;
                        c++;
                        j++;
                        i = 1;
                }
                else {
                        a[j] = 7 * b;
                        b++;
                        j++;
                        i=0;
                }
        }
        cout << a[n-1] << endl;
return 0;
}