Multiply two linked lists
=========================

Simple,generate the actual numbers from list
and simply multiply and return them....
---------------------------------------------------------------

long long  multiplyTwoLists (Node* l1, Node* l2)
{
  long long n1 = 0;
  long long n2 = 0;
  long long m = 1000000007;                //// vvvimp 10^9 + 7
  
  while(l1 or l2){
      if(l1){
          n1 = (n1*10)%m + l1->data;              // here see that mod to avoid integer overflows
          l1 = l1->next;
      }
      
       if(l2){
          n2 = (n2*10)%m + l2->data;              ... here also check that mod
          l2 = l2->next; 
      }
      
      
     }
     
     return ((n1%m)*(n2%m))%m;             // see here too we r multiplying %m individually and to the whole result.
}