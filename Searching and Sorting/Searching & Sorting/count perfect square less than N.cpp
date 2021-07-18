count perfect squares

int x = sqrt(N);
if(x*x == N)
return (int) sqrt(N) -1; // because we don't want to include N since count < N is in the qn

else
return (int)sqrt(N);
=======================