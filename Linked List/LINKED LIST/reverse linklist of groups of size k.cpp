Reverse a Linked List in groups of given size. 
---------------------------------------------------------

Given a linked list of size N. The task is to reverse every k nodes (where k is an input to the function) in the linked list.

time complexity : O(N)
------------------------------------------------------------------
vvvvvveasy
know how to handle ptrs ...thats it...


class Solution
{
    public:
    struct node *reverse (struct node *head, int k)
    { 
        if(head == NULL or head->next == NULL or k==1)
        return head;                                                             // the base case
        
        int n = 0;
        struct node *curr = head;
        struct node *newhead;
        while(curr != NULL){                       get the total count of nodes...in due course find the newhead of our result list
            n++;
            if(n==k)                                       // and its nothing but kth node of the original list
            newhead = curr;
            curr = curr->next;
            }
            
            // declaring all ptrs
            struct node *prev = NULL;   // these three we have already seen in reverse list
            curr = head;
            struct node *next = NULL;
           

           struct node *t1 = NULL;          // t1 pts to last element of reversed blok
            struct node *t2 = head;            // t2 pts to first element in the next unreversed one
            
         while(n>=k){      // big outer loop begins       we will first do for blocks containing k elements
         
         for(int i=0;i<k;i++){         // normal reversal
             next = curr->next;
             curr->next = prev;
             prev = curr;
             curr = next;
         }
                                                                t1               prev
         if(t1)                                      1  2  3            4  5                
         t1->next = prev;               prev will pt the last element in reverssed one so chnging t1
         t1 = t2;                            
         t2 = curr;
         prev = NULL;          vvvimp
         n-=k;              
             
         }   
         
        while(curr != NULL){            // after completing for blocks of size k...we have to do for remaining nodes
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        t1->next = prev;            // dont forget to change
         return newhead;