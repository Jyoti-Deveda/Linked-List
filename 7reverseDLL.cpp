
Node* reverseDLL(Node* head)
{   
    if(head == NULL){
        return head;
    }   

    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        curr -> prev = forward;
        prev = curr;
        curr = forward;
    }

    return prev;
}
