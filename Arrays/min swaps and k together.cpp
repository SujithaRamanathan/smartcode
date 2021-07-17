MINIMUM SWAPS AND K TOGETHER:-

1.SIMPLE SOLN:-O(EXPONENTIAL TIME)
========================================
COUNT THE ELEMENTS THROUGH THE ARRAY WHICH > K(THAT'S THE SUBARRAY SIZE)
....

2.SLIDING WINDOW METHOD O(N)
================================
COUNT THE ELEMENTS THROUGH THE ARRAY WHICH > K(THAT'S THE window SIZE)
FOR THE FIRST WINDOW COUNT ELEMENTS>K(MAKE A C COUNTER)
THEN SLIDE THE WINDOW
ipo namma next window ponum na first element ah vidanum,so first we are checking
that whether the 1st ele contributed to c (which is min swaps in first win)
i=0,j=count;
if(a[i] > k) c--; // coz we need to check the min swaps for the next window
if(a[j] > k) c++. coz thats a newly added ele to the curr window so we need to check and add it to c
compare last windows minswap with current
res = min(res,c);
return res
===========================================================================================================
int minSwap(int *a, int n, int k) {
       
       int count=0;
       
       for(int i=0;i<n;i++){ //determing window size
       if(a[i] <= k) {
            count++; } 
           }
       
       
       int c=0;
       for(int i=0;i<count;i++) { //determining min swaps for first window
           if(a[i]>k){
               c++;
           }
       }
       
       int i=0,j=count;
       int res=c;;
      //determining result
       while(j<n) {
           if(a[i]>k) 
           c--; // if gonna remove element is contributed we dec count
           if(a[j]>k)
           c++; //gonna add ele is contributed we inc count
           if(res > c)
            res = c;
           i++;
           j++;
       }
           
      return res; 
}
