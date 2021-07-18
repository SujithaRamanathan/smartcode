Reverse a Doubly Linked List by push at the beginning-SET 2:-
======================================================
we create a push function that adds the given node at the beginning of the given list. We traverse the original list and one by one pass the current node pointer to the push function. This process will reverse the list. Finally return the new head of this reversed list.

void push(Node** head_ref, Node* new_node)
{
    // since we are adding at the beginning,
    // prev is always NULL
    new_node->prev = NULL;
 
    // link the old list off the new node
    new_node->next = (*head_ref);
 
    // change prev of head node to new node
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
 
    // move the head to point to the new node
    (*head_ref) = new_node;
}
 
// function to reverse a doubly linked list


void reverseList(Node** head_ref)
{
    // if list is empty or it contains
    // a single node only
    if (!(*head_ref) || !((*head_ref)->next))
        return;
 
    Node* new_head = NULL;
    Node *curr = *head_ref, *next;
 
    while (curr != NULL) {
 
        // get pointer to next node
        next = curr->next;
 
        // push 'curr' node at the beginning of the
        // list with starting with 'new_head'
        push(&new_head, curr);
 
        // update 'curr'
        curr = next;
    }
 
    // update 'head_ref'
    *head_ref = new_head;
}