//given a value x , move all the nodes with val < x to the front of LL and leave the rest of 
//the nodes as it is maintaining the relative order

    void deleteNode(ListNode* curr, ListNode* prev){
        ListNode* temp = curr;
        prev -> next = curr -> next;
        temp -> next = NULL;
        delete temp;
    }

    ListNode* partition(ListNode* head, int x) {
        if(head == NULL || head -> next == NULL) return head;
        ListNode* dummy = new ListNode(0);
        dummy -> next = head;
        queue<int> greater;
        ListNode* prev = dummy;
        ListNode* curr = curr;
        while(curr != NULL){
            int val = curr -> val;
            if(val >= x){
                greater.push(val);
                deleteNode(curr, prev);
                curr = prev -> next;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }


        while(!greater.empty()){
            prev -> next = new ListNode(greater.front());
            greater.pop();
            prev = prev -> next;
        }
        return dummy-> next;
    }