void deleteNode(ListNode* &head, ListNode* curr, ListNode* prev){
        ListNode* temp = curr;
        if(curr == head){
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return;
        }

        prev -> next = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head == NULL) return head;

        if(head -> next == NULL && n == 1) return NULL;
        //calculate length
        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            len++;
            temp = temp -> next;
        }

        n = len-n+1;
        int cnt = 1;
        ListNode* prev = NULL;
        ListNode* curr = head;
        while(cnt < n){
            prev = curr;
            curr = curr -> next;
            cnt++;
        }

        deleteNode(head, curr, prev);
        return head;
    }