#include <iostream>
#include <cstring>
using namespace std;

int stack[100], n = 100, top = -1;

void push(int val) {
    if (top >= n - 1)
        cout << "Stack Overflow" << endl;
    else {
        top++;
        stack[top] = val;
    }
}

void pop() {
    if (top <= -1)
        cout << "Stack Underflow" << endl;
    else {
        cout << "The popped element is " << stack[top] << endl;
        top--;
    }
}

void display() {
    if (top >= 0) {
        cout << "Stack elements are:";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    } else
        cout << "Stack is empty";
}

bool isPalindrome(string str) {
    int len = str.length();

    for (int i = 0; i < len; i++) {
        push(str[i]);
    }

    for (int i = 0; i < len; i++) {
        if (stack[top] != str[i]) {
            return false;
        }
        top--; 
    }
    return true;
}

int main() {
    int ch, val;
    string str;

    cout << "1) Push in stack" << endl;
    cout << "2) Pop from stack" << endl;
    cout << "3) Display stack" << endl;
    cout << "4) Check Palindrome" << endl;
    cout << "5) Exit" << endl;

    do {
        cout << "Enter choice: " << endl;
        cin >> ch;

        switch (ch) {
            case 1: {
                cout << "Enter value to be pushed:" << endl;
                cin >> val;
                push(val);
                break;
            }
            case 2: {
                pop();
                break;
            }
            case 3: {
                display();
                break;
            }
            case 4: {
                cout << "Enter a string to check for palindrome:" << endl;
                cin >> str;
                top = -1;  // Reset the stack top
                if (isPalindrome(str))
                    cout << str << " is a palindrome." << endl;
                else
                    cout << str << " is not a palindrome." << endl;
                break;
            }
            case 5: {
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Invalid Choice" << endl;
            }
        }
    } while (ch != 5);

    return 0;
}
