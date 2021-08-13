#include<iostream>
#include<algorithm>
using namespace std;

int main() {
        string str;
        cin >> str;

        // using reverse inbulit one
        reverse(str.begin(), str.end());
        cout << " the ans is " <<endl << str << endl;

        // using swap
        int n = str.length();
        for(int i=0;i<n/2;i++)
        {
        swap(str[i],str[n-i-1]);
        }
        cout << "swap ans is  " << str << endl;

        return 0;
}