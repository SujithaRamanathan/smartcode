TO CHECK ARMSTRONG OR NOT:-
================================
#include<iostream>
#include<cmath>
using namespace std;

int main() {
        int n;
        cin >> n;
        int temp = n;
        int count = 0;
        while(temp!=0) {                  // this loop ->to find order(no of digits)
                count++;
                temp = temp/10;
        }
        int sum = 0;
        temp = n;
        while(temp!=0) {                   // this loop to find desired sum
                int r = temp%10;
                int x = pow(r,count);
                sum += x;
                temp = temp/10;
        }
        if(sum == n)                               // here checking
                cout << "yes" << endl;
        else
                cout << "no" << endl;
        return 0;
}


TO FIND Nth ARMSTRONG NUMBER:-
----------------------------------------------------

                } */
int main() {
int n;
cin >> n;
int count=0;

    // upper limit from integer
    for(int i = 1; i <= INT_MAX; i++)
    {
        int num=i, rem, digit=0, sum=0;

        //Copy the value for num in num
        num = i;

        // Find total digits in num
        digit = (int) log10(num) + 1;

        // Calculate sum of power of digits
        while(num > 0)
        {
            rem = num % 10;
            sum = sum + pow(rem,digit);
            num = num / 10;
        }
        // Check for Armstrong number
        if(i == sum)
            count++;
        if(count==n) {
            cout << i << endl;
            break;
        }
    }
return 0;