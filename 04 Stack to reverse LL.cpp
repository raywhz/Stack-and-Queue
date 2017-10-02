//
//  04 Stack to reverse LL.cpp
//  Stack and Queue
//
//  Created by Haozhou Wu on 9/25/17.
//  Copyright © 2017 Haozhou Wu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>

using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* head = NULL;

void insert0(int num){
    Node* temp = new Node;
    temp->data = num;
    temp->next = head;
    head = temp;
};

void printl(){
    cout << "Linked list is: ";
    Node* cur = head;
    while(cur!=NULL){
        cout << cur->data << " ";
        cur = cur->next;
    }
    cout << endl;
};

void reversel(){
    Node* temp = head;
    stack<struct Node*>S;
    while(temp!=NULL){
        S.push(temp);
        temp = temp->next;
    }
    head = S.top();
    temp = S.top();
    S.pop();
    while(!S.empty()){
        temp->next = S.top();
        S.pop();
        temp = temp->next;
    }
    temp->next = NULL;
};

int main(){
    insert0(4);
    insert0(3);
    insert0(2);
    insert0(1);
    printl();
    
    reversel();
    printl();
    
    
    return 0;
}



