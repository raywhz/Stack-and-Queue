//
//  05 Stack to check bracket balance.cpp
//  Stack and Queue
//
//  Created by Haozhou Wu on 9/29/17.
//  Copyright © 2017 Haozhou Wu. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool ifPaired(char opening, char closing){
    if (opening == '(' && closing == ')')
        return true;
    else if (opening == '[' && closing == ']')
        return true;
        else if (opening == '{' && closing == '}')
            return true;
    return false;
    
}

bool areBracketBalanced(string exp){
    stack<char> S;
    for (int i = 0; i<exp.length(); i++){
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{' )
            S.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}'){
            if (S.empty() || !ifPaired(S.top(), exp[i]))
                return false;
            else
                S.pop();
        }
    }
    return S.empty()?true:false;
    
};

int main(){
    string mystring;
    cout << "Enter a string: " << endl;
    cin >> mystring;
    if(areBracketBalanced(mystring))
        cout << "Balanced" << endl;
    else
        cout << "Not balanced" << endl;
    return 0;
}
