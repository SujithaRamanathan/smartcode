#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main() {
        string str;
        string cat;

        cin >> str;
        cin >> cat;
        string ais = str;
        char a[] = "sujitha";
        char b[] = "ramanathan";

        string ans = strcat(a,b); // method1       -----> strcat works only on char arrays
        string ans1 = str.append(cat); // method2     ---->once appended with former string,then former string permanently changed.

        string ans2 = ais + cat; // method3       ===> thats why here ais sytring is used

        cout << ans << endl;
        cout << ans1 << endl;
         cout << ans2 << endl;
 return 0;
}
