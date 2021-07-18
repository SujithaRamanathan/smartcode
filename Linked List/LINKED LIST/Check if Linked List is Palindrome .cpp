Check if Linked List is Palindrome :-
------------------------------------------------
Given a singly linked list of size N of integers. The task is to check if the given linked list is palindrome or not.
Example 1:
Input:
N = 3
value[] = {1,2,1}
Output: 1
Explanation: The given linked list is
1 2 1 , which is a palindrome and
Hence, the output is 1.
----------------------------------------------------------------------------------------
2 approaches:-

1) Using stack:-
=================
A simple solution is to use a stack of list nodes. This mainly involves three steps.
Traverse the given list from head to tail and push every visited node to stack.
Traverse the list again. For every visited node, pop a node from the stack and compare data of popped node with the currently visited node.
If all nodes matched, then return true, else false

bool isPalin(Node* head){
         
        // Temp pointer
        Node* slow= head;
 
        // Declare a stack
        stack <int> s;
  
 
        // Push all elements of the list
        // to the stack
        while(slow != NULL){
                s.push(slow->data);
 
                // Move ahead
                slow = slow->ptr;
        }
 
        // Iterate in the list again and
        // check by popping from the stack
        while(head != NULL ){
             
            // Get the top most element
             int i=s.top();
 
             // Pop the element
             s.pop();
 
             // Check if data is not
             // same as popped element
            if(head -> data != i){
                return false;
            }
 
            // Move ahead
           head=head->ptr;
        }
 
return true;
}
=========================================================

2) Reverse approach (O(1) EXTRA space so efficient one)
------------------------------------------------------------------------
class Solution{
  public:
    void reverse(struct Node** head_ref)      -------------------------------------------> 1

                                                                           /// see here ** so changing ref here wil affect there
{
    struct Node* prev = NULL;
    struct Node* current = *head_ref;
    struct Node* next;
     
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
   

bool compare(struct Node* head1,              --------------------------------------------------> 2
                  struct Node* head2)
{
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;
 
    while (temp1 && temp2)
    {
        if (temp1->data == temp2->data)
        {
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
        else
            return 0;
    }
 
    // Both are empty reurn 1
    if (temp1 == NULL && temp2 == NULL)   // if both same size only we can return 1
        return 1;
 
    // Will reach here when one is NULL
    // and other is not
    return 0;  
}
   
 bool isPalindrome(Node *head) ---------------------------------------------------------------------> 3
    {
        bool res = true;
        
        Node *sp = head;
        Node *fp = head;
        Node *prev_sp = head;            --------// prev only the end of first half
        Node *second_half;                    // for second half head
        Node *midnode = NULL;          // take vare of mid element in case of odd nodes
        
        if(head != NULL and head->next != NULL) {
            
            while(fp != NULL and fp->next != NULL){   // find mid (sp will hold that)
                fp = fp->next->next;
                prev_sp = sp;
                sp = sp->next;
            }
            
            if(fp != NULL) {
                midnode = sp;                   // if odd nodes store mid element
                sp = sp->next;                             // make sp the next node
            }
            
            second_half = sp;           // second half head
            prev_sp ->next = NULL;    // terminate first half
            
            reverse(&second_half);              // reverse
            
            res = compare(head,second_half);           // compare
            
            reverse(&second_half);           // again reverse for restore
            
            if(midnode != NULL) {                         // if there is a mid element do join like this
                prev_sp->next = midnode;
                midnode->next = second_half;
            }
            else 
            prev_sp->next = second_half;               // else simply join like this
            
            
            
        }
        
        return res;            // rerurn final res
        
    }
};