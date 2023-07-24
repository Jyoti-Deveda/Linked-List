int findLength(ListNode* head){
        int len = 0;
        while(head != NULL){
            len++;
            head = head -> next;
        }
        return len;
    }
    int pairSum(ListNode* head) {
        int len = findLength(head);
        int half = len/2;
        int cnt = 0;
        stack <int> firstHalf;
        while(cnt < half){
            firstHalf.push(head -> val);
            head = head -> next;
            cnt++;
        }
        
        int max = 0;
        while(head != NULL){
            if((head -> val + firstHalf.top()) > max){
                max = head -> val + firstHalf.top();
            }
            firstHalf.pop();
            head = head -> next;
        }
        return max;
    }