//find middle node
//split LL into two halves
//reverse the second half
//compare the nodes of both the halves
//if equal-palindrome
//else-not

ListNode* findMiddle(ListNode* head){
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
    bool isPalindrome(ListNode* head) {
        if(head == NULL || head -> next == NULL) return true;

        ListNode* mid = findMiddle(head);
        ListNode* temp = head;
        while(temp -> next != mid){
            temp = temp -> next;
        }

        temp -> next = NULL;

        //reversing half of the linked list
        ListNode* prev = NULL;
        ListNode* curr = mid;
        ListNode* forward = NULL;
        while(curr != NULL){
            forward = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = forward;
        }
        mid = prev;
        
        // comparing two halves
        while(head && mid){
            if(head -> val != mid -> val){
                return false;
            }
            head = head -> next;
            mid = mid -> next;
        }
        return true;
    }