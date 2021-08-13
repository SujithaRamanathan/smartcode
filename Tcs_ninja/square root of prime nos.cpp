#include<stdlib.h>
#include<stdbool.h>
#include<math.h>
bool isPrime(int n)
{
    if(n<2)
    return false;

    int i;
    for(i=2;i*i<=n;i++)
    {
        if(n%i==0)
        return false;
    }
    return true;
}


int main(int argc, char *argv[])
{
    if(argc==1)                // vvvvimp
    {
        printf("No arguments");
        return 0;
    }
    else
    {
        int n;
        n=atoi(argv[1]);               // converting to integer vvvvimp
        double sq=0;

        if(isPrime(n))
        {
            sq = sqrt(n);                   // squareroot finding
            printf("%.2f\n",sq);
        }
        else
        printf("%.2f\n",sq);

    return 0;
    }
}