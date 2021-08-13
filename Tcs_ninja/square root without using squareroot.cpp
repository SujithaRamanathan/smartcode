#include<iostream>
#include<iomanip>
using namespace std;
void sq(float);
float findinrange(float,float,float);
float findinrange(float n,float i,float j) {
        float mid = (i + j) / 2;
        float mul = mid*mid;

        if((mul == n) or (abs(mul - n) < 0.000001))   // even if there is a small difference we can accept that
               return mid;
        else if(mul < n)
        return findinrange(n,mid,j);
        else
        return findinrange(n,i,mid);
}

void sq(float n) {
        float i = 1;
        bool found = false;
        while(!false) {                                      // trying out start form 1
                if(i*i == n) {
                        cout << fixed << setprecision(3) << i;                  // if equal just printing that
                        break;
                }

                else if(i*i > n) {                                         // if greater  then by fact it lies between i-1 and i ...so do bin search
                        float ans = findinrange(n,i-1,i);
                        cout << fixed << setprecision(3) << ans;
                        break;
                }
                else                       // if less just inc i by 1
                        i++;
        }
}


int main() {
        float n,i;
        cin >> n;

/*      for( i = 0.01 ; i*i < n;i= i+0.01);         // here method 2
      cout  << fixed << setprecision(3) <<  i; */
 cout  << fixed << setprecision(3) <<  i; */
         sq(n);
        return 0;
}