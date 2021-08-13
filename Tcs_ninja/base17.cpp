#include<iostream>
#include<math.h>
#include<string.h>
#include <unordered_map>
using namespace std;

int main() {
        char input[5];
        cin >> input;

        int n = strlen(input);

        int a = n-1;

        unordered_map <char,int>mp;
        mp['A'] = 10;
         mp['B'] = 11;
          mp['C'] = 12;
         mp['D'] = 13;
          mp['E'] = 14;
           mp['F'] = 15;
           mp['G'] = 16;


           int sum = 0;

        for(int i =0;input[i] !='\0';i++) {

                if(mp.find(input[i]) != mp.end()) {

                        int x = mp[input[i]];
                        sum = sum + x * pow(17,a);
                        a--;
                        continue;
                }


                        int x = input[i] - 48;
                        sum =sum + x * pow(17,a);

                a--;
        }
 }

        cout << sum << " answer" << endl;
//      cout << pow(17,1) << endl;
        return 0;