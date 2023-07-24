#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* prev;
        Node* next;

        Node(int data){
            this -> data = data;
            this -> prev = NULL;
            this -> next = NULL;
        }

        ~Node(){
            int val = this->data;
            if(next != NULL){
                delete next;
                next = NULL;
            }
            cout << "Memory freed for " << this -> data << endl;
        }
};

void print(Node* &head, Node* &tail){
    Node* temp = head;

    while(temp != NULL){
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << endl;
    cout << "Head " << head->data << endl;
    cout << "Tail " << tail->data << endl;
}

int getlength(Node* &head){
    Node* temp = head;
    int len = 0;

    while(temp != NULL){
        len++;
        temp = temp -> next;
    }
    return len;
}

void insertAtHead(Node* &head, Node* &tail, int data){
    //empty list
    if(head == NULL){
        Node* nodeToInsert = new Node(data);
        head = nodeToInsert;
        tail = nodeToInsert;
        return;
    }
    Node* nodeToInsert = new Node(data);

    nodeToInsert -> next = head;
    head -> prev = nodeToInsert;
    head = nodeToInsert;
}

void insertAtTail(Node* &head, Node* &tail, int data){
    //empty list
    if(head == NULL){
        Node* nodeToInsert = new Node(data);
        head = nodeToInsert;
        tail = nodeToInsert;
        return;
    }

    Node* nodeToInsert = new Node(data);
    tail -> next = nodeToInsert;
    nodeToInsert ->prev = tail;
    tail = nodeToInsert;
}

void insertAtPos(Node* &head, Node* &tail, int d, int pos){
    if(pos == 1){
        insertAtHead(head, tail, d);
        return;
    }

    int count = 1;
    Node* temp = head;
    while(count < pos-1 && temp != NULL){
        temp = temp->next;
        count++;
    }

    if(temp -> next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert -> next = temp -> next;
    temp -> next -> prev = nodeToInsert;
    temp -> next = nodeToInsert;
    nodeToInsert-> prev = temp;    
}

void deleteNode(int pos, Node* &head, Node* &tail){

    //start node
    if(pos == 1){
        Node* temp = head;
        head = temp->next;
        temp -> next -> prev = NULL;
        temp -> next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* previous = NULL;

        int cnt = 1;
        while(cnt < pos){
            //curr will point to the node to be deleted
            previous = curr;
            curr = curr -> next;
            cnt++;
        }

        //checking for last node
        curr->prev = NULL;
        previous-> next = curr -> next;
        
        if(curr->next == NULL){
            tail = previous;
        }else{
            curr -> next -> prev = previous;
        }

        curr -> next = NULL;
        delete curr;        

    }
}

int main(){
    // Node* node1 = new Node(10);
    // Node* head = node1;
    // Node* tail = node1;.

    Node* head = NULL;
    Node* tail = NULL;
    // print(head, tail);

    insertAtHead(head,tail, 29);
    print(head, tail);

    insertAtHead(head,tail, 13);
    print(head, tail);

    insertAtTail(head,tail, 30);
    print(head, tail);

    insertAtPos(head, tail, 100, 1);
    print(head, tail);

    insertAtPos(head, tail, 110, 3);
    print(head, tail);

    insertAtPos(head, tail, 120, 6);
    print(head, tail);

    deleteNode(1, head, tail);
    print(head, tail);

    deleteNode(5, head, tail);
    print(head, tail);
}