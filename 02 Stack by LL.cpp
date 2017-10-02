//
//  02 Stack by LL.cpp
//  Stack and Queue
//
//  Created by Haozhou Wu on 9/24/17.
//  Copyright © 2017 Haozhou Wu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};

Node* top = NULL;

void push(int num){
    Node* temp = new Node;
    temp->data = num;
    temp->next = top;
    top = temp;
};

void pop(){
    if (top == NULL)
        return;
    Node* temp = top;
    top = top->next;
    delete temp;

};

void prints(){
    Node* temp = top;
    while(temp!=NULL){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
};

int main(){
    push(2);
    prints();
    push(5);
    prints();
    push(8);
    prints();
    pop();
    prints();

    
    
    
    return 0;
}



