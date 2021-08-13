#include<iostream>
using namespace std;

int main(int argc,char* argv[]) {
        int num;
        num = atoi(argv[1]);
        int sum = 0;
        while(num != 0)
        {
                int rem = num % 10;
                sum += rem;
                num = num/10;
        }
        cout << sum << endl;
}