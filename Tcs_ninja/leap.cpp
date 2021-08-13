 #include<iostream>
using namespace std;
int main() {
        int a;
        cin >> a;
        if((a%4 == 0) and ((a%400 == 0) or (a%100 != 0) ) )

                cout << "leap year" << endl;
        else
                cout << "not a leap year" << endl;
        return 0;
}