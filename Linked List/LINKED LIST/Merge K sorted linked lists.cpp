Merge K sorted linked lists:-
=============================

Naive approach:-
----------------------

recursive traversal .. go up to last one
then return after returning merge it with the current one then return the merged list to above one

o(nk2)
=============================
Method 3: Divide and Conquer. 
In this post, Divide and Conquer approach is discussed. This approach doesn’t require extra space for heap and works in O(nk Log k)
It is known that merging of two linked lists can be done in O(n) time and O(n) space. 

The idea is to pair up K lists and merge each pair in linear time using O(n) space.
After the first cycle, K/2 lists are left each of size 2*N. After the second cycle, K/4 lists are left each of size 4*N and so on.
Repeat the procedure until we have only one list left.
======================================================





 Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
 
    /* Base cases */
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);
 
    /* Pick either a or b, and recur */
    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}
    
    Node* mergeKLists(Node* a[], int k)
    {
        int last = k-1;            /// vvvimpppp 0 based indexing so
           while(last != 0){    if k = 5.last = 4;
               int i =0;
              int j =last;
              
              while(i<j){
                  a[i] = SortedMerge(a[i],a[j]);           // merge a[0] and a[4] store in a[0]
                  i++;                 // then i = 1;j=3 // so merge a[1] and a[3] store in a[1]
                  j--;
              
                  if(i>=j){               // i=2,j=2 so update last as j i.e 2 coz(now the size reduced to 0,1,2) we want to merge
                      last  = j;
                      
                  }
              }
              
              }
              
              return a[0];              //finally return a[0]
           
    }
};
