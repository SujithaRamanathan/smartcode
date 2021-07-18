Reverse the dll:-
----------------------------
Given the pointer to the head node of a doubly linked list, reverse the order of the nodes in place. That is, change the next and prev pointers of the nodes so that the direction of the list is reversed. Return a reference to the head node of the reversed list.

Note: The head node might be NULL to indicate that the list is empty.
--------------------------------------------------------------------------------------------------

approach :- just swap prev and next ptrs
------------------------------------------------------
DoublyLinkedListNode* reverse(DoublyLinkedListNode* llist) {
    
    
    DoublyLinkedListNode *curr = llist;
    DoublyLinkedListNode *temp;
    
    if(llist == NULL or llist->next == NULL)

    return llist;            ///////////////////vvvvvvvvvvvvvvvimp
    
    while(curr != NULL) {
        temp = curr->prev;
        curr->prev = curr->next;               // swapping
        curr->next = temp;
        curr = curr->prev;
    }    
    
    if(temp != NULL)           // vvvvvvvvimp since in one node only temp is null and it would give exception
    temp = temp->prev;           // dont forget to update temp and temp as newhead and return that only.
    
    
    return temp;
    
  }