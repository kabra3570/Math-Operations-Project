class Condition : public SubExpression
{
public:
       Condition(Expression* left, Expression* right, Expression* c) : SubExpression(left, right, c)
       {
       }
       int evaluate()
       {
           // if the condition is true, store the value on the left
           if (c->evaluate())
              return left->evaluate();
            // if not, store the value on the right
           else
              return right->evaluate();
       }
};


