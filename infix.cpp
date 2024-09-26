#include <iostream>
#include <cstring>

using namespace std;

#define MAX 100

class Stack {
    char arr[MAX];
    int top;

public:
    Stack() { top = -1; }

    void push(char x) { arr[++top] = x; }

    char pop() { return arr[top--]; }

    char peek() { return arr[top]; }

    bool isEmpty() { return top == -1; }
};

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int precedence(char ch) {
    if (ch == '+' || ch == '-') return 1;
    if (ch == '*' || ch == '/') return 2;
    return 0;
}

void infixToPostfix(char* exp) {
    Stack stack;
    
    for (int i = 0; exp[i] != '\0'; i++) {
        char ch = exp[i];

        if (isOperand(ch)) {
            cout << ch;
        } else if (ch == '(') {
            stack.push(ch);
        } else if (ch == ')') {
            while (stack.peek() != '(') {
                cout << stack.pop();
            }
            stack.pop();
        } else {
            while (!stack.isEmpty() && precedence(ch) <= precedence(stack.peek())) {
                cout << stack.pop();
            }
            stack.push(ch);
        }
    }

    while (!stack.isEmpty()) {
        cout << stack.pop();
    }
}

int main() {
    char exp[MAX];
    cout << "Enter infix expression: ";
    cin >> exp;

    cout << "Postfix expression: ";
    infixToPostfix(exp);
    cout << endl;

    return 0;
}
