//given two positions left and right, reverse the LL b/w these two positions
    ListNode* reverseList(ListNode* start, ListNode* end){
        ListNode* prev = NULL;
        ListNode* forward = NULL;

        // cout << "start -> val" << start-> val << endl;
        // cout << "End -> next" << end-> next-> val << endl;

        while(start != end){
            cout << "Start -> val" << start -> val << endl;
            forward = start -> next;
            start -> next = prev;
            prev = start;
            start = forward;
        }
        start -> next = prev;
        return start;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head -> next == NULL) return head;
        if(left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy -> next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;
        int pos = 1;
        while(pos < left){
            prev = curr;
            curr = curr -> next;
            pos++;
        }
        ListNode* start = curr;
        while(pos < right){
            curr = curr -> next;
            pos++;
        }

        ListNode* forward = curr -> next;
        ListNode* reversedHead = reverseList(start, curr);
        prev -> next = reversedHead;
        while(prev -> next != NULL){
            prev = prev -> next;
        }
        prev -> next = forward;
        return dummy -> next;
    }