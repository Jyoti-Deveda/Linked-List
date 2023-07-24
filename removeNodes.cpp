//approach 1- uses extra space
//creating a new linked list which does not contain the node with given val

void insertAtTail(ListNode* &head, ListNode* &tail, int val){
        ListNode* nodeToInsert = new ListNode(val);
        if(head == NULL){
            head = nodeToInsert;
            tail = nodeToInsert;
            return;
        }
        tail -> next = nodeToInsert;
        tail = tail -> next;
    }

    ListNode* removeElements(ListNode* head, int val) {
        ListNode* head1 = NULL;
        ListNode* tail = NULL;
        ListNode* temp = head;
        while(temp != NULL){
            if(temp -> val != val){
                insertAtTail(head1, tail, temp -> val);
            }
            temp = temp -> next;
        }

        return head1;
    }

    //approach 2
    //no extra space
    //used a dummy Node
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;

        ListNode* dummyNode = new ListNode(0);
        dummyNode -> next = head;
        ListNode* prev = dummyNode;

        while(head != NULL){
            if(head -> val == val){
                ListNode* temp = head;
                prev -> next = temp -> next;
                head = head -> next;
                temp -> next = NULL;
                delete temp;
            }
            else{
                prev = head;
                head = head -> next;
            }
        }
        
        return dummyN