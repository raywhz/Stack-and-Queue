//
//  03 Stack to reverse string.cpp
//  Stack and Queue
//
//  Created by Haozhou Wu on 9/24/17.
//  Copyright © 2017 Haozhou Wu. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
#include <stack>
using namespace std;

void reverse(char* words, size_t n){
    stack<char> S;
    for(int i = 0; i < n; i++){
        S.push(words[i]);
    }
    for(int i = 0; i < n; i++){
        words[i] = S.top();
        S.pop();
    }
    
};


int main(){
    char words[51];
    cout << "Enter a string: ";
    cin >> words;
    reverse(words, strlen(words));
    cout <<strlen(words) << endl;
    cout << words << endl;
    
    return 0;
}

