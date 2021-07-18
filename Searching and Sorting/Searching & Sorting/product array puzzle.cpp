Product array puzzle
======================

1)DIVISION METHOD VERY EASY:-

GET PRODUCT OF ALL ELEMENTS IN THE ARRAY
a[] =  1 2 3 4 5
tot product = 120

then form the desired arr by dividing the  corresponding elements at indexes

120/1     120/2   120/3 120/4  120/5

120  60   40   30  24

=================================================

2) without division method:-
------------------------------

create two new arrays
l[n] = 1  _  _  _ _
r[n] = _ _ _ _ _ 1


fill l[] array ( 0 -> n)

l[i] = l[i-1] * arr[i-1];


fill r[] array (n-2 ->0)

r[i] = r[i+1] * arr[i+1];

creare output array
 arr[i] = l[i] * r[i] ;


  vector<long long int> l(n);              /// when declaring vector mention size otherwise segmentation error
       vector<long long int> r(n); /// r(n)
       vector<long long int> ans(n);  // ans(n)
       
       l[0]=1;
       r[n-1]=1;
       
       for(int i=1;i<n;i++)
           l[i] = l[i-1] * nums[i-1];
           
        for(int i=n-2;i>=0;i--)
           r[i] = r[i+1] * nums[i+1];
           
           for(int i=0;i<n;i++)
           ans[i] = l[i] * r[i];
           
              
       return ans;