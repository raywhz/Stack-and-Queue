//
//  07 Stack infix to postfix.cpp
//  (a+b)*(c+d) == ab+cd+*
//  Stack and Queue
//
//  Created by Haozhou Wu on 10/2/17.
//  Copyright © 2017 Haozhou Wu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>
using namespace std;

// function to convert infix to postfix
string in2post(string exp);

// functiont to verify whether it is an numeric operand
bool isOperand(char mychar);

// function to verify whether it is an operator
bool isOperator(char mychar);

// function to verify the precendence
// if op1 has higher precendence, return 1
bool precendence(char op1, char op2);

int main(){
    string mystring;
    cout << "Enter a string: " << endl;
    getline(cin, mystring);
    string postfix = in2post(mystring);
    
    cout << "Postfix is: " << postfix << endl;
    
    return 0;
}

bool isOperator(char mychar){
    if (mychar =='+' || mychar =='-' || mychar =='*' || mychar =='/')
        return true;
    
    return false;
}

bool isOperand(char C){
    if (C>='0' && C<='9')
        return true;
    if (C>='a' && C<='z')
        return true;
    if (C>='A' && C<='Z')
        return true;
    return false;
}

string in2post(string exp){
    stack<char> S;
    string postfix = "";
    for(int i = 0; i < exp.length(); i++){
        if(exp[i] == ' ' || exp[i] == ',')
            continue;
        else if(isOperator(exp[i])){
            while(!S.empty() && S.top()!='(' && precendence(S.top(), exp[i])){
                postfix += exp[i];
                S.pop();
            }
            S.push(exp[i]);
        }
        else if(isOperand(exp[i])){
            postfix += exp[i];
        }
        else if(exp[i] == '(')
            S.push(exp[i]);
        else if(exp[i] == ')'){
            while(!S.empty() && S.top() !=  '('){
                postfix += S.top();
                S.pop();
            }
            S.pop();                // pop the opening paretheses
        }
    }
    
    while(!S.empty()){
        postfix += S.top();
        S.pop();
    }
    
    return postfix;
}

int getWeight(char mychar){
    if(mychar == '+' || mychar == '-')
        return 1;
    if(mychar == '*' || mychar == '/')
        return 2;
    return -1;
};

bool precendence(char op1, char op2){
    int weight1 = getWeight(op1);
    int weight2 = getWeight(op2);
    
    return weight1 > weight2? true:false;
}



