Prime number with pos,neg twist:-
===================

#include<iostream>
using namespace std;
#include<cmath>
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
int main() {
        int n;
        cin >> n;

        if(n>0) {
                if(isprime(n))
                        cout << " prime "  << endl;
                else
                        cout << "not prime" << endl;
        }

        else {
                cout << " enter a positive number" << endl;
        }

        return 0;
}

