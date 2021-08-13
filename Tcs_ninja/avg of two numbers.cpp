#include<iostream>
using namespace std;
int main(int argc,char* argv[]) {
        int num1,num2;
        if(argc == 1)
                cout << "no args found" << endl;
        num1 = atoi(argv[1]);
        num2 = atoi(argv[2]);
        int ans = (num1 + num2) / 2;
        cout << ans << endl;
        return 0;
}