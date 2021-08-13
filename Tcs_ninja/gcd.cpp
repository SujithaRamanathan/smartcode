Method 1- c++ algorithm library function __gcd(a,b)
=======================================
NOte:- underscore underscore gcd

#include<iostream>
#include<algorithm>
using namespace std;
int main() {
        int a,b;
        cin >> a;
        cin >> b;
        cout << "gcd is " << __gcd(a,b) << endl;
        return 0;
}

--------------------------------------------------------------------------------------
Method 2:-Euclidean algorithm:-
=========================
GCD of two numbers doesn’t change if smaller number is subtracted from a bigger number. 
#include<iostream>
#include<algorithm>
using namespace std;
int gcd(int a,int b) {

        if(a==0)
                return b;
        if(b==0)
                return a;
        if(a==b)
                return a;
        if(a>b)
                return gcd(a-b,b);
        return gcd(a,b-a);
}
int main() {
        int a,b,ans;
        cin >> a;
        cin >> b;
//      cout << "gcd is " << __gcd(a,b) << endl;
        ans = gcd(a,b);
      cout <<  ans  << endl;
        return 0;
}

--------------------------------------------------
Method 3: using modulo operator
========================
int gcd(int a,int b) {
/*      if(b==0)
                return a;
        return gcd(b,a%b); */
-----------------------------------------------------