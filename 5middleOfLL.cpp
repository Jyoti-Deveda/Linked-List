class Node 
        { 
        public:
            int data;
            Node *next;
            Node(int data) 
            {
               this->data = data;
              this->next = NULL;
            }
        };


int getLength(Node* head){
    int len = 0;
    while(head != NULL){
        head = head -> next;
        len++;
    }
    return len;
}

Node *findMiddle(Node *head) {

    int len = getLength(head);
    int mid = len/2;
    int cnt = 0;
    Node* temp = head;
    while(cnt < mid){
        temp = temp->next;
        cnt++;
    }

    return temp;

    // Write your code here
}