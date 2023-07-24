//approach 1
Node* sortList(Node *head){
    int zeroes = 0;
    int ones = 0;
    int twos = 0;
    Node* temp = head;
    while(temp != NULL){
        if(temp -> data == 0){
            zeroes++;
        }else if(temp -> data == 1){
            ones++;
        }else{
            twos++;
        }
        temp = temp -> next;
    }
    temp = head;
    while(temp != NULL){
        if(zeroes != 0){
            temp-> data = 0;
            zeroes--;
        }else if(ones != 0){
            temp -> data = 1;
            ones--;
        }else if(twos != 0){
            temp -> data = 2;
            twos--;
        }
        temp = temp -> next;
    }
    return head;
}

//approach 2
void insertAtTail(Node* &tail, Node* curr){
    tail -> next = curr;
    tail = curr;
}

Node* sortList(Node *head){
    Node* zeroHead = new Node(0);
    Node* zeroTail = zeroHead;
    Node*oneHead = new Node(0);
    Node* oneTail = oneHead;
    Node*twoHead = new Node(0);
    Node* twoTail = twoHead;

    Node* curr = head;
    //three diffeent LL
    while(curr != NULL){
        int val = curr -> data;
        if(val == 0){
            insertAtTail(zeroTail, curr);
        }else if(val == 1){
            insertAtTail(oneTail, curr);
        }else if(val == 2){
            insertAtTail(twoTail, curr);
        }
        curr = curr -> next;
    }

    //merging
    //if 1s Linked list is  empty
    if(oneHead -> next == NULL){
        zeroTail -> next = twoHead -> next;
    }else{
        zeroTail -> next = oneHead -> next;
    }

    oneTail -> next = twoHead -> next;
    twoTail -> next = NULL;

    head = zeroHead -> next;

    delete zeroHead;
    delete oneHead;
    delete twoHead;

    return head;
}