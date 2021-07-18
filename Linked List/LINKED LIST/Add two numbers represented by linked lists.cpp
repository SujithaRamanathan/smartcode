Add two numbers represented by linked lists
-------------------------------------------------------

Given two numbers represented by two linked lists of size N and M. The task is to return a sum list. The sum list is a linked list representation of the addition of two input numbers from the last.

Example 1:

Input:
N = 2
valueN[] = {4,5}
M = 3
valueM[] = {3,4,5}
Output: 3 9 0  
Explanation: For the given two linked
list (4 5) and (3 4 5), after adding
the two linked list resultant linked
list will be (3 9 0).
Example 2:

---------------------------------------------------------------------------
only approach:- O(N)
==============
3 -> 4 -> 5
4 -> 5

Ans : 345
            45     (+)
        --------
         390
       ---------
 We  have to add from last...so need to reverse

step 1:-
reverse the lists and dont forget to  change first and second ptrs.
step2:-
Addition
step3:-
reverse the final result

--------------------------------------------------------------------------
class Solution
{
    public:
    //Function to add two numbers represented by linked list.
     struct Node* reverse(struct Node* head) {
        struct Node *curr = head;
        struct Node *prev = NULL;
        struct Node *next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;                   // note here
        return head;             // VVVVimp
         }
   
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      
 // step 1
------------       
       first = reverse(first);
       second = reverse(second);
   
// step 2
-----------    

         struct Node *temp;                                // temp for traversal  , prev for connecting , res for head maintenance
        struct Node *prev = NULL;
        struct Node *res  = NULL;
        int carry = 0,sum;                 // initialize carry as 0
        
        
      while(first != NULL or second != NULL)        // if both loops end means break out of the loop
{
            sum = carry + (first ? first->data : 0) + (second ? second->data : 0);   // carry + first (0) + second (0)
            carry = (sum >=10) ? 1 :  0;       // here note that since a node contain a single digit value sum cannot be more than 18
                                                                       so always carry can be 1 only.
            
            sum = sum%10;               // again updating sum in case we have carry place the unit digit 
            temp = new Node(sum);      // already we have function to create a node.
            
            if(res == NULL)                // if res is not updated till,then store temp which is going to be the head in res
            res = temp;
           else
            prev->next=temp;           // if not the first node ,then connect it with the previous node
            
            prev = temp;                   // after update the prev ptr for further things
            
            if(first) first = first->next;                  // update first and second if not null
            if(second) second = second->next;
        }
      ---------------  
        if(carry > 0)                                       // atlast if we have extra carry then store it in a new node.
                                                                            99 + 1 = 100
        temp->next = new Node(carry);        create and link it at the same time
   
// step3:-
-----------     
        
         res = reverse(res);            // dont forget to reverse dddddd   
         
         return res;      // after reversing then return the res head ptr.
    }
};
----------------------------------------------------------:)