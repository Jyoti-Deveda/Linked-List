
Node *removeDuplicates(Node *head)
{
    //empty list
    if(head == NULL) return head;
    
    //approach 1 - O(n2) and O(1) time and space compexity
    Node* temp = head;

    while(temp != NULL){
        Node* curr = temp -> next;
        Node* prev = temp;
        while(curr != NULL){
            if(curr -> data == temp -> data){
                prev -> next = curr -> next;
                delete(curr);
            }
            else{
                prev = curr;
            }
                curr = prev -> next;
        }
        temp = temp -> next;

    }
    return head;

    //approach 2 O(n) time and space complexity
    // unordered_map<int, bool> visited;

    // Node* curr = head;
    // Node* prev = NULL;

    // while(curr != NULL){
    //     //if the node data is not present in map
    //     int data = curr->data;
    //     if(!visited[data]){
    //         visited[data] = true;
    //         prev = curr;
    //     }else{
    //         prev -> next = curr -> next;
    //         delete (curr);
    //     }
    //     curr = prev-> next;
    // }
    // return head;
}