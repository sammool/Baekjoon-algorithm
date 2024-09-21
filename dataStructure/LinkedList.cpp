
#include <bits/stdc++.h>
using namespace std;

class Node{
    public:   
       int data;
       Node *next; //다음 노드의 주소
       
       Node(){
           data = 0;
           next = NULL;
       }
};

class LinkedList{
public:
    Node* head;
    Node* tail;
    
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    
    void pushFront(int num){
        Node* newNode = new Node();
        newNode -> data = num;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            newNode -> next = head;
            head = newNode;
        }
    } // pushFront 끝
    
    void pushBack(int num){
        Node* newNode = new Node();
        newNode-> data = num;
        newNode-> next = NULL;
        if(head == NULL){
            head = newNode;
            tail = newNode;
        }else{
            tail->next = newNode;
            tail = newNode;
        }
    } //addNode 끝
    
    void popFront(){
        if(head == NULL){
            cout << "list empty" << '\n';
            return;
        }

        Node* cur = head;
        head = head->next;

        //리스트의 노드가 한 개만 있었을 경우
        if(head == NULL)
            tail = NULL;
        
        delete cur;
    } //popFront() 끝

    

    void print(){
        Node* iter = head;
        while(iter != NULL){
            cout << iter->data << '\n';
            iter = iter -> next;
        }
        cout << '\n';
    }
};

int main() {
    LinkedList list;
    list.pushBack(1);
    list.pushBack(2);
    list.pushBack(3);
    
    list.print();
    list.pushFront(4);
    list.print();
}
//https://www.youtube.com/watch?v=OGOf7ZK4xaI