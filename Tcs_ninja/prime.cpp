 A prime is a natural number greater than 1 that has no positive divisors other than 1 and itself. Examples of first few prime numbers are {2, 3, 5,}

#include<iostream>
#include<cmath>
using namespace std;

int main() {
        int n;
        cin >> n;
        if(n<=1) {
                cout << "not prime" << endl;
        return 0;
        }

        for(int i=2;i<=sqrt(n);i++) {              // i range can also be from 2 ->n-1  ,   2 -> n/2
                if(n%i == 0) {
                         cout << "not prime" << endl;
                         return 0;
                }
        }

        cout << "prime" << endl;
        return 0;
}

=========================================================================

return prime numbers within the given range
--------------------------------------------------------
#include<iostream>
#include<cmath>
using namespace std;
int isprime(int n) {
        for(int i =2;i<= sqrt(n);i++) {
                if(n%i == 0) {
                        return 0;
                        break;
                }
        }
        return 1;
}

int main() {
        int a,b;
        cin >> a;
        cin >> b;

        for( int i = a;i<=b;i++) {
                if(i==0 || i==1){

                        continue;
                }

                if(isprime(i))
                        cout << i << endl;

        }


        return 0;
}