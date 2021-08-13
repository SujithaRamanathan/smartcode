#include<iostream>
using namespace std;

int main() {
        int n;
        cin >> n;
        int a[n];
        a[0] = 0;
        a[1] = 0;
        a[2] = 2;
        a[3] = 1;
        int j = 4;
        int i = 0;
        int an = 2;

        for(int k = 4;k<=n;k++) {

        if(i==0) {
                a[j] = an * 2;
                an++;
                j++;
                i = 1;
        }
        else {
                a[j] = a[j-2] + 1;
                j++;
                i = 0;
        }
        }

        cout << a[n-1] << endl;
        return 0;
}