#include<iostream>
#include<bits/stdc++.h>
#include<string.h>
using namespace std;

int main() {
        string s;
        cin >> s;
        string ans = s;               // after reversing s gets changes to reversed one
        reverse(s.begin(),s.end());  
        if(s != ans)                               // comparator operator
                cout << "not palind" << endl;
        else
                cout << "palin" << endl;
        return 0;
}