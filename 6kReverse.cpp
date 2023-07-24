Node* kReverse(Node* head, int k) {
    if(head == NULL){
        return NULL;
    }

    //step 1: reverse first k nodes
    Node* next = NULL;
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 0;

    while(curr != NULL && cnt < k){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    //step 2 recursion will handle
    if(next != NULL){
        head -> next = kReverse(next, k);
    }

    return prev;
}