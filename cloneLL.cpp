// clone linked list using a random pointer 
void insertAtTail(Node* & head, Node* &tail, int data){
        Node* newNode = new Node(data);
        if(head == NULL){
            head = newNode;
            tail = newNode;
            return;
        }
        tail -> next = newNode;
        tail = tail -> next;
    }
    public:
    Node *copyList(Node *head)
    {
        //step 1- clone
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        //step 2 -create map
        unordered_map<Node*, Node*> oldToNew;
        
        Node* originalNode = head;
        Node* clonedNode = cloneHead;
        while(originalNode != NULL){
            oldToNew[originalNode] = clonedNode;
            originalNode = originalNode -> next;
            clonedNode = clonedNode -> next;
        }
        
        originalNode = head;
        clonedNode = cloneHead;
        while(originalNode != NULL){
            clonedNode -> arb = oldToNew[originalNode -> arb];
            originalNode = originalNode -> next;
            clonedNode = clonedNode -> next;
        }
        return cloneHead;
    }


    //approach 2 without any extra space
     Node *copyList(Node *head)
    {
        //step 1- clone
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        
        while(temp != NULL){
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp -> next;
        }
        
        //step 2 - add clone nodes between orginal list
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        Node* next = NULL;
        while(originalNode != NULL  && cloneNode != NULL){
            next = originalNode -> next;
            originalNode -> next = cloneNode;
            originalNode = next;
            
            next = cloneNode -> next;
            cloneNode -> next = originalNode;
            cloneNode = next;
        }
        
        //step 3- copy random pointers
        temp = head;
        while(temp != NULL){
            // if(temp -> next != NULL){
               temp -> next -> arb = temp -> arb ? temp -> arb -> next : temp -> arb;
            // }
            temp = temp -> next -> next;
        }
        
        //step 4- revert step 2
        originalNode = head;
        cloneNode = cloneHead;
        
        while(originalNode != NULL && cloneNode != NULL){
            originalNode -> next = cloneNode -> next;
            originalNode = originalNode -> next;
            
            if(originalNode != NULL){
                cloneNode -> next = originalNode -> next;
            }
            cloneNode = cloneNode -> next;
        }
        
        //step 5- return ans
        return cloneHead;
        
    }