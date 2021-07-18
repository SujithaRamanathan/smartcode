Remove duplicate element from sorted Linked List
----------------------------------------------------------------
LinkedList: 2->2->4->5
Output: 2 4 5
Explanation: In the given linked list 
2 ->2 -> 4-> 5, only 2 occurs more 
than 1 time.

----------------------------------------------

since its sorted we know that the duplicate elements are adjacent right..

void removeDuplicates(struct Node* head)
{
    struct Node *temp = head;
    struct Node *store;
    if(temp == NULL)
    return;
    while(temp->next != NULL) {
        if(temp->data == temp->next->data) {               // checking
            store =  temp->next->next;
            free(temp->next);                                      // free is verey necessary for that firstly we have to store the address.
            temp->next = store;            VVVIMP // no updation of temp ptr...
         }                                                         eg.   2   2   2   2  2
    
     else
    
    temp = temp->next;                       // only if there is no detection update temp ptr....
    }
    
    
}

----------------------------------------------------------------------
Method 2:- Usinh Hash Maps(O(nodes) extra space

void removeDuplicates(Node* head)
{
    unordered_map<int, bool> track;
    Node* temp = head;
    while (temp) {
        if (track.find(temp->data) == track.end()) {
            cout << temp->data << " ";
        }
        track[temp->data] = true;
        temp = temp->next;
    }
}
