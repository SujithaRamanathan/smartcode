Decimal to Binary:-
=====================

Method 1 
-------

#include<iostream>
using namespace std;
#define MAXSIZE 32
int main() {
        int n;
        cin >> n;
        int a[MAXSIZE];

        for(int i =31;i>=0;i--) {                  please try to remember it...
                int k = n >> i;                              right shift here
               
                 if(k & 1)                            if msb 1 then o/p 1 else 0
                        cout << 1 ;
                else
                        cout << 0;
        }

Method 2:- Easy method:-
------------------------------------
/*      int i =0;
        while(n!=0) {
                int r = n%2;
                a[i] = r;
                n = n/2;
                i++;
        }
        for(int j = i-1;j>=0;j--) {
                cout << a[j] << " ";
        } */
        return 0;
}

=============================================================================================
Binary to decimal
----------------------
method 1:-
==========
#include<iostream>
#include<cmath>               // make use of pow cmath
using namespace std;

int main() {
        string str;
        cin >>  str;
        int n = str.length();           //length
        int a = n-1;                        // - 1 to find the max limit of power
        int ans = 0;
        int i =0;
        
       while(i<n) {
        int x = str[i] - 48;          //  vvvvimp - 48 then only consider as value
        ans += x * pow(2,a);
        i++;
        a--;
        }
        

cout << ans << endl;
        return 0;
}
         