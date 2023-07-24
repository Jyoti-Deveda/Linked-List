
Node * uniqueSortedList(Node * head) {
    //empty list
    if(head == NULL) return head;

    Node* curr = head;
    while(curr != NULL){
        if((curr->next != NULL) && curr -> data == curr -> next -> data){
            Node* nodeToDelete = curr -> next;
            curr -> next = curr -> next -> next;
            delete(nodeToDelete);
        }else{
            curr = curr-> next;
        }
    }
    return head;
}
