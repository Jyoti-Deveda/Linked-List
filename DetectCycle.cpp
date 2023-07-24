    map<ListNode*, bool>visited;
        ListNode* temp = head;
        while(temp != NULL){
            if(visited[temp]){
                break;
            }else{
                visited[temp] = true;
            }
            temp = temp -> next;
        }
        return temp;


    //using floyd's cycle detection algo

