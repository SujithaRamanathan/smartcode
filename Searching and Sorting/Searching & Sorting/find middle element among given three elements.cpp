Find middle element in a given three numbers

int x = a-b;
int y = b-c;
int z = a-c;

if(x*y >0)
return b;
else if(x*z >0)
return c;
else
return a;
