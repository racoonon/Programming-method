#include <string>

class Calculator {
  public:
    // Do not modify constants
    // Maximum operation priority level
    const int MAX_OPERATOR_PRIORITY_LEVEL = 3;

    // Evaluate the term number starting at the idx.
    double evaluateTerm(std::string s, int &idx);

    // Return the priority level of given operator character.
    int operatorPriority(char op);

    // Evaluate the operator given left and right operands and operator
    // chraracter. Function that executes the arithmetic operation with the
    // given inputs
    // @param operand : (double type) operand number
    // @param op : (char type) operator (,+,-,*,/,^,)
    // @return : The calculation outcome of the "left op right"
    double evaluateOperator(double left, double right, char op);

    // Evaluate the expression (consisting of various operators and terms) at
    // the given level.
    double evaluateExpression(std::string s, int &idx, int level);

    // Used in Quaridor game.
    // You don't need to implement this function.
    bool query();
};
