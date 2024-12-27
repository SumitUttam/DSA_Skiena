#include<iostream>

using namespace std;

struct node{
    int key;
    node *next;
};

int main(){
    node *head, *tail, *curr;
    head = new node;
    head->key = 0;
    head->next = NULL;
    tail = head;

    //inserts New Node;
    curr = new node;
    curr->key = 5;
    curr->next = NULL;
    tail->next = curr;
    tail = tail->next;

    //print the list;
    curr = head;
    while (curr!=NULL){
        cout << curr->key << " -> ";
        curr = curr->next;
    }
    cout << "END" << endl;
}