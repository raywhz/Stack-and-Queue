//
//  06 Stack to evaluate postfix.cpp
//  2 3*5 4*+9- == 2*3+5*4-9 = 17
//  Stack and Queue
//
//  Created by Haozhou Wu on 9/29/17.
//  Copyright © 2017 Haozhou Wu. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <stack>
#include <iostream>

using namespace std;

// Perform the operation
int operation(char C, int op1, int op2);
bool isOperator(char C);
bool isNumeric(char C);

int evaPostfix(string exp){
    stack<int> S;
    for (int i =0; i<exp.length(); i++){
        if(exp[i] == ' ' || exp[i] == ',')
            continue;
        else if(isOperator(exp[i])){
            int op2 = S.top();          // Get the operands
            S.pop();
            int op1 = S.top();
            S.pop();
            int result = operation(exp[i], op1, op2);
            S.push(result);
        }
        else if(isNumeric(exp[i])){
            int op = 0;
            while(i<exp.length() && isNumeric(exp[i])){
                op = op*10 + exp[i]-'0';    // Get a decimal number
                i++;
            }
            i--;                        // Do not skip an operator
            S.push(op);
        }
    }
    // If everything correct, there will be only 1 element on top of stack
    return S.top();
};

int main(){
    string mystring;
    cout << "Enter a posttfix string: " << endl;
    getline(cin, mystring);
    int result = evaPostfix(mystring);
    cout << "Result: " << result << endl;
    return 0;
}

bool isOperator(char C){
    if (C=='+' || C=='-' || C=='*' || C=='/')
        return true;
    
    return false;
}

bool isNumeric(char C){
    if (C>='0' && C<='9')
        return true;
    return false;
}

int operation(char C, int op1, int op2){
    int result = -1;
    switch(C){
        case '+': result = op1+op2;
            break;
        case '-': result = op1-op2;
            break;
        case '*': result = op1*op2;
            break;
        case '/': result = op1/op2;
    }
    return result;
}






