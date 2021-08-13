In mathematical terms, the sequence Fn of Fibonacci numbers is defined by the recurrence relation 

Fn = Fn-1 + Fn-2
with seed values 

F0 = 0 and F1 = 1.
======================================
Method 1:Recursion
-----------------------------

#include<iostream>
using namespace std;

int fib(int n) {
        if(n==1 or n==2)
                return 1;              ///// vvvvvvimp here,series starts with 1 .if series starts with 0 then n==1,return 0,and for n=2,3 return 1.

        return fib(n-1) + fib(n-2);
}

int main() {
        int n;
        cin >> n;

        int ans = fib(n);
        cout << ans << endl;
        return 0;
}
===========================================
Method 2:Dynamic Programming
--------------------------------------------
int f[n+2];                             size as n+2 ---->to store for 0th and 1st term as 0 and 1
        f[0] = 0;
        f[1] = 1;                                    
        for(int i =2;i<=n;i++)                    // VVVimp <= equal to n
                f[i] = f[i-1] + f[i-2];
        cout << f[n] << endl;                    // coz we r going to return f[n];
        return 0;
}

=======================================================

Method 3:- Space optimized approach
--------------------------------------------------
 int a = 0, b = 1,c;
        if(n==0)
         return a;
        if(n==1)
        return b;
        for(int i =2;i<=n;i++) {
        c = a+b;
        a = b;
        b = c;
        }
        cout << b << endl;
        return 0;
}
===========================================================
