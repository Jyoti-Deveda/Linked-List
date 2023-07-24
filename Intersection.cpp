ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        map<ListNode*, bool> visited;
        while(headA != NULL){
            if(visited[headA] == true) {
                headA = headA -> next;
            }
            else{
                visited[headA] = true;
                headA = headA -> next;
            }    
        }

        while(headB != NULL){
            if(visited[headB] == true){
                return headB;
            }
            headB = headB -> next;
        }

        return NULL;
    }


//approach 2
// In this approach, we can simply convert this problem into a loop problem.

// Find the tail.
// Connect the tail with any of the head which creates a loop.
// Using the other head, find intersection point of the loop.
// Undo the loop, by setting tail->next = NULL.
// Return the intersection node.

//this problem will become like floyds cycle detection algo