#include<iostream>
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

void insertNode(Node* &tail, int element, int d){
    if(tail == NULL){
        Node* nodeToInsert = new Node(d);
        tail = nodeToInsert;
        nodeToInsert -> next = nodeToInsert;
    }
    else{
        Node* curr = tail;

        while(curr-> data != element){
            curr = curr -> next;
        }

        Node* nodeToInsert = new Node(d);
        nodeToInsert -> next = curr -> next;
        curr -> next = nodeToInsert;
        
    }
}

void print(Node* tail){
    Node* temp = tail;

    //1 way
    // cout << temp->data << " ";
    // temp = temp -> next;
    
    // while(temp != tail){
    //     cout << temp -> data << " ";
    //     temp = temp -> next;
    // }cout << endl;

    //2 way using do while
    if(tail == NULL){
        cout <<"List is empty " << endl;
        return;
    }
    do{
        cout << temp -> data << " ";
        temp = temp -> next;
    }while(temp != tail);
    cout << endl;
}

void deleteNode(Node* &tail, int val){
    if(tail == NULL){
        cout << "List is empty" << endl;
        return;
    }else{
        Node* prev = tail;
        Node* curr = prev->next;

        //if one node exists
        if(curr == prev){
            tail = NULL;
        }


        while(curr -> data != val){
            prev = curr;
            curr = curr -> next;
        }
        prev->next = curr->next;

        
        //>=2 node
        if(tail == curr){
            tail = prev;
        }
        curr->next = NULL;
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

int main(){
    Node* tail = NULL;
    insertNode(tail, 2, 3);
    print(tail);
    
    // insertNode(tail, 3, 5);
    // print(tail);

    // insertNode(tail, 5, 9);
    // print(tail);

    // deleteNode(tail, 3);
    // print(tail);

    // deleteNode(tail, 9);
    // print(tail);

    // deleteNode(tail, 5);
    // print(tail);

    if(isCircular(tail)){
        cout << "Is circular " << endl;
    }else{
        cout << "Is not circular" << endl;
    }
}