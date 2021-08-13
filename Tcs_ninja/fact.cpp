#include<iostream>
using namespace std;

int fact(int n) {
        return (n==0 or n==1) ? 1 : n*fact(n-1);
}
int main() {
        int n;
        cin >> n;
        int ans = fact(n);
        cout << ans << endl;
        return 0;
}