#include<iostream>
using namespace std;


int main() {
        int a[10];
        cout << "enter the 10 numbers" << endl;

        for(int i=0;i<10;i++)
                cin >> a[i];

        int greatest = a[0];
        for(int i=1;i<10;i++) {
                if(a[i] > greatest)
                        greatest = a[i];
        }
        cout << "the greatest one is " << greatest << endl;
        return 0;
}