class Solution {
public:
    ListNode* reversePairs(ListNode* head, ListNode* temp){
        if(head == NULL || head -> next == NULL) return head;

        //swaping logic
        ListNode* forward = temp-> next;
        temp -> next = head;
        head -> next = NULL;

        if(forward!= NULL){
            cout << "Forward " << forward -> val << endl;
            head -> next = reversePairs(forward, forward -> next);
        }
        return temp;
    }
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL) return head;
        return reversePairs(head, head -> next);
    }
};