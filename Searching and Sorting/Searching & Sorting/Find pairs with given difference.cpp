Find pair with given difference:_

Naive app 1

two loops,checking all pairs
==============================================
app2:-
sort the array,then only we can search for a + diff right!? otherwise ( a-b = diff)  b = a-diff )-----------> O(NLOGN)
traverse the array 
for each element , 
    binary search for element a[i] + difference------------------------for n elements logn search( so O(nlogn))

===============================

app 3 :- we can avoid bin search by two ptr technique:-

AFTER SORTING VVVVIMP Dont forget:-
i=0,j=1;
while(i<n and j<n) {
if(a[j] - a[i] < diff)
j++;
else if(a[j] - a[i] > diff)
i++;
else
return true or make count;

===================================================

