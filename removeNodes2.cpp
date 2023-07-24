//Remove every node which has a node with a strictly greater value anywhere
//  to the right side of it.
// 5-> 2-> 13-> 3-> 8 = 13 -> 8

// Return the head of the modified linked list

void insertNode(ListNode* &head, ListNode* &tail, int val){
    ListNode* nodeToInsert = new ListNode(val);
    if(head == NULL){
        head = nodeToInsert;
        tail = nodeToInsert;
        return;
    }
    tail -> next = nodeToInsert;
    tail = tail -> next;

}

ListNode* reverseList(ListNode* head){
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* forward = NULL;
    while(curr != NULL){
        forward = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = forward;
    }
    return prev;
    }
    ListNode* removeNodes(ListNode* head) {
        ListNode* reversedHead = reverseList(head);
        cout << "Revesed list " << endl; 
        // ListNode* temp = reversedHead;
        // while(temp != NULL){
        //     cout << temp -> val << " ";
        //     temp = temp -> next;
        // }
        // cout << endl;

        stack<int> values;
        values.push(reversedHead -> val);
        reversedHead = reversedHead -> next;

        while(reversedHead != NULL){
            if(reversedHead -> val >= values.top()){
                values.push(reversedHead -> val);
            }
            reversedHead = reversedHead -> next;
        }        


        ListNode* head1 = NULL;
        ListNode* tail = NULL;
        while(!values.empty()){
            insertNode(head1, tail, values.top());
            values.pop();
        }
        return head1;
    }