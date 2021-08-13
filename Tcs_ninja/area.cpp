#include<iostream>
using namespace std;
int area_circle(int);
float area_triangle(int b,int h) {
        return (0.5 * b * h);
}
int area_circle(int r) {
        return 3.14 * r * r;
}

int main(int argc,char* argv[]) {
        if(argc == 1) {
                cout << " no args" << endl;
                return 0;
        }

        int r,b,h;
        r = atoi(argv[1]);
        b = atoi(argv[2]);
        h = atoi(argv[3]);

        int ans = area_circle(r);
        float ans1 = area_triangle(b,h);

        cout << " area of circle " << ans << endl;
        cout << " area of triangle " << ans1 << endl;



        return 0;
}