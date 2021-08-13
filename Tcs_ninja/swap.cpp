Different methods:-
================
1) swap() in c++
2) temp

3) +,-

 a = a+b;
 b = a-b;
 a = a-b;

4) *, /

a = a*b;
b = a/b;
 a = a/b;


5) exor
=
#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
        int a,b;
        cin >> a;
        cin >> b;
	if(a==b)
	return a;
        a = a^b;
        b = a^b;
        a = a^b;


        cout << "a = " << a << " b = " << b << endl;
        return 0;
}