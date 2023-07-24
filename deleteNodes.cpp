// delete nodes from sorted LL 
// 1 1 1 2 3 ->  2 3

void deleteNode(ListNode* &head, ListNode* curr, ListNode* prev){
        ListNode* temp = curr;
        if(head == curr){
            head = head -> next;
            temp -> next = NULL;
            delete temp;
            return;
        }
        prev -> next = temp -> next;
        temp -> next = NULL;
        delete temp;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL || head -> next == NULL) return head;

        map<int, int> visited;
        ListNode* temp = head;
        while(temp != NULL){
            int val = temp -> val;
            if(visited[val]){
                visited[val]++;
            }else{
                visited[val] = 1;
            }
            temp = temp -> next;
        }
        // for (auto i = visited.begin(); i != visited.end(); i++)
        // cout << i->first << " \t\t\t" << i->second << endl;

        ListNode* prev = NULL;
        ListNode* curr = head;

        while(curr != NULL){
            int val = curr -> val;
            if(visited[val] > 1){
                ListNode* dummy = curr-> next;
                deleteNode(head, curr, prev);
                curr = dummy;
            }else{
                prev = curr;
                curr = curr -> next;
            }

        }
        return head;
    }