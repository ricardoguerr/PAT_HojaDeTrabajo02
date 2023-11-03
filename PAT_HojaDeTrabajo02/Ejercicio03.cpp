#include "Ejercicio03.h"

#include <stack>
#include <cctype>

int Ejercicio03::calculate(string s)
{
    std::stack<int> values;
    std::stack<char> operators;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        if (c == ' ') {
            continue; 
        }
        else if (isdigit(c)) {
            int num = 0;
            while (i < s.length() && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            i--;
            values.push(num);
        }
        else if (c == '(') {
            operators.push(c);
        }
        else if (c == ')') {
            while (!operators.empty() && operators.top() != '(') {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.pop(); 
        }
        else if (c == '+' || c == '-') {
            while (!operators.empty() && (operators.top() == '+' || operators.top() == '-' || operators.top() == '*' || operators.top() == '/')) {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(c);
        }
        else if (c == '*' || c == '/') {
            while (!operators.empty() && (operators.top() == '*' || operators.top() == '/')) {
                int b = values.top();
                values.pop();
                int a = values.top();
                values.pop();
                char op = operators.top();
                operators.pop();
                values.push(applyOperation(a, b, op));
            }
            operators.push(c);
        }
    }

    while (!operators.empty()) {
        int b = values.top();
        values.pop();
        int a = values.top();
        values.pop();
        char op = operators.top();
        operators.pop();
        values.push(applyOperation(a, b, op));
    }

    return values.top();

}


int Ejercicio03::applyOperation(int a, int b, char op) {
    if (op == '+') {
        return a + b;
    }
    else if (op == '-') {
        return a - b;
    }
    else if (op == '*') {
        return a * b;
    }
    else if (op == '/') {
        return a / b;
    }
    else {
        return 0; 
    }
}
