#include<iostream>
#include<cstring>
#include<map>
using namespace std;

int main() {
        string s1;
        string s2;
        string s3;
        cin >> s1;
        cin >> s2;
        cin >> s3;

        map<char,int> mp;   // here we can also put capital letters
        mp['a'] = 0;
        mp['e'] = 1;
        mp['i'] = 2;
        mp['o'] = 3;
        mp['u'] = 4;

        for(int i = 0;i<s1.length();i++) {
                if(mp.find(s1[i]) != mp.end())      // if vowel then change it
                        s1[i] = '*';
                else
                        continue;
        }

        cout << s1 << endl;

        for(int i = 0;i<s2.length();i++) {
                if((s2[i]>='a'&&s2[i]<='z') || (s2[i]>='A'&&s2[i]<='Z'))              // here we check wheteher its a alphabet and then we r checking                                                                                                                         for consonant
                 if(mp.find(s2[i]) == mp.end())
                         s2[i] = '@';
                 else
                         continue;
        }
         cout << s2 << endl;

        for(int i = 0;i<s3.length();i++) {
                s3[i] = toupper(s3[i]);                          // toupper() vvvvimp or else we can use s[i] = s[i] - 32; if alphabet.
        }
         cout << s3 << endl;
   return 0;
}