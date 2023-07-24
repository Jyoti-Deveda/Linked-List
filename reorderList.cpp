ListNode* findMid(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL){
            fast = fast -> next;
            if(fast != NULL){
                fast = fast -> next;
            }
            slow = slow -> next;
        }
        return slow;
    }

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
            forward= curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        if(head == NULL || head -> next == NULL)return;
        //split the list into two halfs
        ListNode* mid = findMid(head);
        cout << "Mid " << mid -> val << endl;
        ListNode* head2 = mid;
        ListNode* head1 = head;
        ListNode* temp = head;
        while(temp -> next != mid){
            temp = temp -> next;
        }
        temp -> next = NULL;

        //reverse the second half
        head2 = reverseList(head2);

        // cout << "reversed list" << endl;
        // while(head2 != NULL){
        //     cout << head2 -> val << " ";
        //     head2 = head2 -> next;
        // }

        ListNode* for1 = NULL;
        ListNode* for2 = NULL;
        while(head1 != NULL && head2 != NULL){
            for1 = head1 -> next;
            head1 ->next = head2;
            for2 = head2 -> next;
            head2 -> next = for1;
            head1 = for1;
            head2 = for2;
        }

    }