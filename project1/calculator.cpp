#include "calculator.hpp"
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <sstream>

double Calculator::evaluateTerm(std::string s, int &idx) {
    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
    std::stringstream ss;
    double d;
    int n = idx;

    if (s[idx] == '(') {
        idx++;
        return evaluateExpression(s, idx, 1);
    }

    while (idx < s.size() && operatorPriority(s[idx]) == 0 && s[idx] != ')' && s[idx] != '(') { // ��ȣ ���� �� �׳� ���ڷ� ��ȯ
        idx++;
    }
    ss << s.substr(n, idx - n);
    ss >> d;

    return d;
    ////////////////////////////////////////////////////////////
}

int Calculator::operatorPriority(char op) {
    switch (op) {
    case '^':
        return 3;
    case '/':
        return 2;
    case '*':
        return 2;
    case '+':
        return 1;
    case '-':
        return 1;
    case ')':
        return 0;
    default:
        return 0;
    }
 
}

double Calculator::evaluateOperator(double left, double right, char op) {

    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
    switch (op) {
    case '+':
        return left + right;
    case '-':
        return left - right;
    case '/':
        return left / right;
    case '*':
        return left * right;
    case '^':
        return pow(left, right);
    default :
        return left;
    }
    ////////////////////////////////////////////////////////////
}

double Calculator::evaluateExpression(std::string s, int &idx, int level) {

    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
    double left, right;
    char op;
    // base case: ���ڸ� return
    if (level > MAX_OPERATOR_PRIORITY_LEVEL) {
        return evaluateTerm(s, idx);
    }
    // recursive step: operator priority check & recursively set the left and right values of the operator
    left = evaluateExpression(s, idx, level + 1);
    if (level == 1 && (s[idx] == ')')) {
        idx++;
        return left;
    }
    else if (operatorPriority(s[idx]) < level) {
        return left;
    }

    while (1) {
        op = s[idx]; // left ���� ���� ù ������
        idx++;
        if (operatorPriority(op) == 3) { // "^"�� ���� EE(,,level) call
            right = evaluateExpression(s, idx, level);}
        else {
            right = evaluateExpression(s, idx, level + 1); }// ���� level�� ���� �����ڿ� ����

        if (idx == s.size()) break;

        left = evaluateOperator(left, right, op); // ���� ���� �������� opPriority�� ������ ������ ����
    }
    return evaluateOperator(left, right, op);
    ////////////////////////////////////////////////////////////
}

bool Calculator::query() {
    double answer, prediction;
    std::string s;
    int idx = 0;
    std::cin >> s;
    answer = evaluateExpression(s, idx, 1);

    std::cout << "input the answer of the equation: ";
    std::cin >> prediction;
    std::cout << "the answer is: ";
    std::cout << std::fixed;
    std::cout.precision(10);
    std::cout << answer << std::endl;
    if (fabs(prediction - answer) <= 1e-4)
        return true;
    return false;
}
