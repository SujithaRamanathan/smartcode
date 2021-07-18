Add 1 to a number represented as linked list
----------------------------------------------------
A number N is represented in Linked List such that each digit corresponds to a node in linked list. You need to add 1 to it.
Example 1:
Input:
LinkedList: 4->5->6
Output: 457 
================================================================
class Solution
{
    public:
     Node* reverse( Node* head) {
         Node *curr = head;
         Node *prev = NULL;
         Node *next = NULL;
        while(curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        head = prev;
        return head;
         }
   
    Node* addOne(Node *head) 
    {
        head = reverse(head);                    // reverse 
        Node *res = head;                                // store head pos
        Node *temp;
        int carry = 1;                                      // here is the only dofference btw add two numbers and this sum
        int sum;
        
        while(head != NULL) {
            sum = carry + (head ? head->data : 0);
            carry = (sum >=10) ? 1:0;
            sum = sum % 10;
            head->data = sum;                  // just overwrite the head->data
            temp = head;                          // temp plays the role of prev for connecting at last if carry is present
            head = head->next;           // traverse
            
        }
        if(carry > 0)
        temp->next = new Node(carry);              // if carry is there (eg., 99 + 1= 100) we need new node for that 1 right
        
        res = reverse(res);                           // dont forget to reverse
        
        return res;
        
    }
};