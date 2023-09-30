#include <iostream>
using namespace std;

struct Expression
{
    virtual double evaluate() const = 0;
    virtual ~Expression() {};
};

struct Number : Expression
{
    Number(double value)
        : value(value)
    {}

    double evaluate() const override{
        return value;
    }

private:
    double value;
};

struct BinaryOperation : Expression
{
    /*
      Здесь op это один из 4 символов: '+', '-', '*' или '/', соответствующих операциям,
      которые вам нужно реализовать.
     */
    BinaryOperation(Expression const * left, char op, Expression const * right)
        : left(left), right(right), op(op)
    { }

    double evaluate() const override {
        if (op == '*')
            return left->evaluate() * right->evaluate();
        else if (op == '-')
            return left->evaluate() - right->evaluate();
        else if (op == '+')
            return left->evaluate() + right->evaluate();
        else
            return left->evaluate() / right->evaluate();
    }
    ~BinaryOperation() {
        delete left;
        delete right;
    }

private:
    Expression const * left;
    Expression const * right;
    char op;
};
