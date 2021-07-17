





Write a function “runCustomerSimulation” that takes following two inputs
a) An integer ‘n’: total number of computers in a cafe and a string:
b) A sequence of uppercase letters ‘seq’: Letters in the sequence occur in pairs. The first occurrence indicates the arrival of a customer; the second indicates the departure of that same customer.

A customer will be serviced if there is an unoccupied computer. No letter will occur more than two times.
Customers who leave without using a computer always depart before customers who are currently using the computers. There are at most 20 computers per cafe.

For each set of input the function should output a number telling how many customers, if any walked away without using a computer. Return 0 if all the customers were able to use a computer.

runCustomerSimulation (2, “ABBAJJKZKZ”) should return 0

runCustomerSimulation (3, “GACCBDDBAGEE”) should return 1 as ‘D’ was not able to get any computer




1) Initialize result as 0.

2) Traverse the given sequence. While traversing, keep track of occupied computers (this can be done by keeping track of characters which have appeared only once and a computer was available when they appeared). At any point, if count of occupied computers is equal to ‘n’, and there is a new customer, increment result by 1.



The important thing is to keep track of existing customers in cafe in a way that can indicate whether the customer has got a computer or not. Note that in sequence “ABCBCADEED”, customer ‘B’ did not get a seat, but still in cafe as a new customer ‘C’ is next in sequence.







O(N)
=================================================
int findCustomers(int n,string s) {
int res=0;
int occupied=0;


 int seen[26] = {0};                       // here we make an occurence array

     // seen[i] = 0, indicates that customer 'i' is not in cafe
    // seen[i] = 1, indicates that customer 'i' is in cafe but
    //              computer is not assigned yet.
    // seen[i] = 2, indicates that customer 'i' is in cafe and
    //              has occupied a computer.




for(int i=0;i<s.length();i++) {
int index = s[i] - 'A' ;
  
if(seen[index] == 0) {            // if the incoming char is first occurence
    
     seen[index] = 1;             // welcoming into the cafe
     

     if(occupied < n) {           // checking if there is comp 
     occupied++;                  // if yes, set as 2
     seen[index]=2;
      }

    else                   // if no seat.so inc res++
     res++;

}

else {                          // V.V.V.V.IMP if it is not the first occurence (seen[index = 1 or 2)
                                  if 2, relese the seat(occupied--) and set as 0 (if used customer wants to leave)
if(seen[index] == 2)              if 1,just set as 0;  (if waiting customer wants to leave)
occupied--;
seen[index] = 0;

}
}
return res;
}


