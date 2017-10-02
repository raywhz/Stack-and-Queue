//
//  01 Stack by Array.cpp
//  Stack and Queue
//
//  Created by Haozhou Wu on 9/24/17.
//  Copyright © 2017 Haozhou Wu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

#define MAX_SIZE 101
int A[MAX_SIZE];
int top = -1;

void push(int num){
    if (top == MAX_SIZE -1){
        cout << "Error: stack overflow" << endl;
        return;
    }
    A[++top] = num;
};

void pop(){
    if (top == -1){
        cout << "Error: stack is empty" << endl;
        return;
    }
    top--;
};

int showtop(){
    return A[top];
};

void prints(){
    cout << "Stack is: ";
    for(int i = 0; i<=top; i++){
        cout << A[i] << " ";
    }
    cout << endl;
};

int main(){
    push(2);
    prints();
    push(4);
    prints();
    push(5);
    prints();
    pop();
    prints();
    push(10);
    prints();
    
    cout << showtop();
    
    
}
