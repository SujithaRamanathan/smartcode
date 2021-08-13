here ,in this 1, 2, 1, 3, 2, 5, 3, 7, 5, 11, 8, 13, 13, 17…..

even terms are prime nos
odd terms are fib nos
==========================



#include<iostream>
#include<cmath>
using namespace std;
void fib(int);
void prime(int);
int isprime(int n) {
                if(n<=1)
                        return 0;
                else {
                for(int i = 2; i <= sqrt(n) ;i++) {
                        if(n%i == 0)
                            return 0;

                         }

                      }

                return 1;
}
void prime(int n) {
        int count = 0;
        for(int i = 2;i<100;i++) {
                if(isprime(i) )
                {
                        count++;
                        if(count == n)
                        {
                        cout << i << endl;
                        break;
                        }
                }
                else
                continue;
        }
}

void fib(int e) {
        int a=1,b=1,c,i;

       if(e==1)
                cout << b << endl;
        for(int i = 2;i<=e;i++) {
         c = a+b;
        a= b;
        b = c;
        }
        cout << b << endl;
}

int main() {
        int n,e;
        cin >> n;
        e = n/2;

        if(n%2 == 0)
                prime(e);
        else
                fib(e);
        return 0;
}