#include <iostream>
#include <stack>
#include <string>
#include <cctype>

using namespace std;

int evaluatePostfixExpression(string postfix) {
    stack<int> operandStack;

    for (char c : postfix) {
        if (isdigit(c)) {
            operandStack.push(c - '0'); 
        } else if (c == ' ') {
            continue; 
        } else if (c == '+' || c == '-' || c == '*' || c == '/') {
            if (operandStack.size() < 2) {
                cerr << "Invalid postfix expression." << endl;
                return -1; 
            }
            int operand2 = operandStack.top();
            operandStack.pop();
            int operand1 = operandStack.top();
            operandStack.pop();

            switch (c) {
                case '+':
                    operandStack.push(operand1 + operand2);
                    break;
                case '-':
                    operandStack.push(operand1 - operand2);
                    break;
                case '*':
                    operandStack.push(operand1 * operand2);
                    break;
                case '/':
                    if (operand2 == 0) {
                        cerr << "Division by zero is not allowed." << endl;
                        return -1; 
                    }
                    operandStack.push(operand1 / operand2);
                    break;
                default:
                    cerr << "Invalid operator: " << c << endl;
                    return -1; 
            }
        } else {
            cerr << "Invalid character: " << c << endl;
            return -1; 
        }
    }

    if (!operandStack.empty() && operandStack.size() == 1) {
        return operandStack.top();
    } else {
        cerr << "Invalid postfix expression." << endl;
        return -1; 
    }
}

int main() {
    string postfixExpression;
    cout << "Enter a postfix expression: ";
    getline(cin, postfixExpression);

    int result = evaluatePostfixExpression(postfixExpression);
    if (result != -1) {
        cout << "Result: " << result << endl;
    }

    return 0;
}
