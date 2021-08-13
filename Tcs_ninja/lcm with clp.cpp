#include<iostream>
using namespace std;
int lcm(int,int);
int gcd(int a,int b) {
        if(b==0)
                return a;
        return gcd(b,a%b);
}
int lcm(int a,int b) {
        int ans = (a * b) / gcd(a,b);
       return ans;
}

int main(int argc,char* argv[]) {
        int num1,num2;
        if(argc == 1)
                cout << " no args " << endl;
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);

        int ans = lcm(num1,num2);
        cout << ans << endl;
        return 0;
}