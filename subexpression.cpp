#include <iostream>
using namespace std;
#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "lessthan.h"
#include "greaterthan.h"
#include "and.h"
#include "equalto.h"
#include "or.h"
#include "not.h"
#include "condition.h"
#include <sstream>
SubExpression::SubExpression(Expression* left, Expression* right)
{
       this->left = left;
       this->right = right;
}
SubExpression::SubExpression(Expression* left)
{
       this->left = left;
}
SubExpression::SubExpression(Expression* left, Expression* right, Expression* c)
{
       this->left = left;
       this->right = right;
       this->c = c;
}
Expression* SubExpression::parse(stringstream& in)
{
        Expression* left;
        Expression* right;
        Expression* c;
        char operation, paren;

        left = Operand::parse(in);
        in >> operation;
        if (operation != '!'){
              right = Operand::parse(in);
              in >> paren;
        }


       switch (operation)
       {
       case '+':
              return new Plus(left, right);
       case '-':
              return new Minus(left, right);
       case '*':
              return new Times(left, right);
       case '/':
              return new Divide(left, right);
       case '<':
              return new LessThan(left, right);
       case '>':
              return new GreaterThan(left, right);
       case '&':
              return new And(left, right);
       case '=':
              return new EqualTo(left, right);
       case '|':
              return new Or(left, right);
       case '!':
              return new Not(left);
       case ':':
              c = Operand::parse(in);
              in >> paren;
              return new Condition(left, right, c);
       }
       system("pause");
       return 0;
}
