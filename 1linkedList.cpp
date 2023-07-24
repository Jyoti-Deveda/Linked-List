#include<iostream>
#include <map>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data){
            this -> data = data;
            this ->next = NULL;
        }

        //destructor
        ~Node(){
            int val = this -> data;
            if(this -> next != NULL){
                delete next;
                this -> next = NULL;
            }
            cout << "Memory freed for " << val << endl;
        }
};

void insertAtHead(int d, Node* &head){
    Node* newNode = new Node(d);

    newNode -> next = head;
    head = newNode;
}

void insertAtTail(int d, Node* &tail){
    Node* newNode = new Node(d);
    tail -> next = newNode;
    tail = newNode;
}

void insertAtPosition(Node* &head, Node* &tail, int pos, int d){
    //if position is 1
    if(pos == 1){
        insertAtHead(d, head);
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count < pos-1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    // if inserting at end
    if(temp -> next == NULL){
        insertAtTail(d, tail);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next = nodeToInsert;
}

void print(Node* head){
    if(head == NULL){
        cout << "list is empty" << endl;
        return;
    }
    Node* temp = head;
    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
}

//deleting a node by position
void deleteNode(int pos, Node* &head, Node* &tail){

    //start node
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int cnt = 1;
        while(cnt < pos){
            //curr will point to the node to be deleted
            prev = curr;
            curr = curr -> next;
            cnt++;
        }
        prev -> next = curr -> next;
        if(curr->next == NULL){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}

//deleting a node by value
void deleteNodeByValue(Node* &head, Node* &tail, int val){
    Node* prev = NULL;
    Node* curr = head;
    while(curr -> data != val && curr->next != NULL){
        prev = curr;
        curr = curr -> next;
    }

    //checking if the val to be deleted is on first pos
    if(prev == NULL){
        Node* temp = head;
        head = head-> next;
        temp->next = NULL;
        delete temp;
    }else {
        prev -> next = curr -> next;
        if(curr ->next == NULL){
            tail = prev;
        }
        curr -> next = NULL;
        delete curr;
    }
}


bool isCircular(Node* head){
    //if list is empty
    if(head == NULL) return true;

    //for multiple nodes
    Node* temp = head -> next;
    while(temp != NULL && temp != head){
        temp = temp -> next;
    }

    if(temp == NULL) return false;

    if(temp == head) return true;
}

bool detectLoop(Node* head){
    if(head == NULL) return false;

    map<Node*, bool> visited;
    Node* temp = head;

    while(temp != NULL){
        if(visited[temp] == true){
            //cycle is present 
            cout << "Cycle is present at " << temp -> data << endl;
            return true;
        }
        visited[temp] = true;

        temp = temp -> next;

    }

    return false;
}

Node* floydDetectLoop(Node* head){
    if(head == NULL) return NULL;

    Node* slow = head;
    Node* fast = head;

    while(fast != NULL){
        fast = fast -> next;
        if(fast != NULL){
            fast = fast -> next;
        }
        slow = slow -> next;
        if(fast == slow){
            return slow;
        }
    }
    return NULL;
}

    Node* getStartingNode(Node* head){
        if(head == NULL) return NULL;

        //getting the intersection point
        Node* intersection = floydDetectLoop(head);

        Node* slow = head;
        while(slow != intersection){
            slow = slow -> next;
            intersection = intersection -> next;
        }
        return slow;
    }

void removeLoop(Node* &head){
    if(head == NULL) return;

    Node* startOfLoop = getStartingNode(head);

    Node* temp = startOfLoop;

    while(temp -> next != startOfLoop){
        temp = temp -> next;
    }
    temp -> next = NULL;
}

int main(){
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    print(head);

    insertAtHead(12, head);
    // insertAtTail(12, tail);
    // print(head);

    insertAtHead(16, head);
    // insertAtTail(16, tail);
    // print(head);

    insertAtPosition(head, tail, 2, 17);
    // print(head); 

    tail -> next = head ->next;

    // if(detectLoop(head)){
    //     cout << "Contains cycle" << endl;
    // }else{
    //     cout << "Cycle is not present" << endl;
    // }

    if(floydDetectLoop(head) != NULL){
        cout << "Contains cycle" << endl;
    }else{
        cout << "Cycle is not present" << endl;
    }
    cout << "Starting node of the cycle is ";
    cout << getStartingNode(head) -> data << endl;

    removeLoop(head);

    if(floydDetectLoop(head) != NULL){
        cout << "Contains cycle" << endl;
    }else{
        cout << "Cycle is not present" << endl;
    }
    print(head);



    // insertAtPosition(head,tail, 1, 20);
    // print(head);        

    // insertAtPosition(head,tail, 6, 30);
    // print(head);      

    // cout << "Head " << head -> data << endl;
    // cout << "Tail " << tail -> data << endl;

    // deleteNodeByValue(head, tail, 20);
    // print(head);

    // cout << "Head " << head -> data << endl;
    // cout << "Tail " << tail -> data << endl;

    // deleteNodeByValue(head, tail, 30);
    // print(head);

    // cout << "Head " << head -> data << endl;
    // cout << "Tail " << tail -> data << endl;

    // deleteNodeByValue(head, tail, 17);
    // print(head);

    // cout << "Head " << head -> data << endl;
    // cout << "Tail " << tail -> data << endl;

    // if(isCircular(NULL)){
    //     cout << "Is circular " << endl;
    // }else{
    //     cout << "Is not circular" << endl;
    // }
}

