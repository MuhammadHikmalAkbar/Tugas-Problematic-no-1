#include <iostream>
#include <stack>

using namespace std;

bool Balanced (string x) {
    stack <char> o;
    for (int i = 0; i < x.length(); i++) {
        if (o.empty()) {
            o.push(x[i]); //if stack empty just push to next element//
        }
        //checking if there are same element//
        //if there is any same element so the stack will pop//
        else if (o.top() == '(' && x[i] == ')'){
            o.pop();
        }
        else if (o.top() == '{' && x[i] == '}'){
            o.pop();
        }
        else if (o.top() == '[' && x[i] == ']'){
            o.pop();
        }
        else if (o.top() == '*' && x[i] == '*'){
            o.pop();
        }
        else if (o.top() == '/' && x[i] == '/'){
            o.pop();
        }
        else {
            o.push(x[i]);
        }
    }
    //statement for the checking if the stack is empty it is balanced//
    if (o.empty()) {
        return true;
    }
    else {
        return false;
    }
}

int main () {
    string x = "/**/(){}[]";
    if (Balanced(x)) {
        cout << "Balanced" << endl;
    }
    else {
        cout << "Not Balanced" << endl;
    }
}
