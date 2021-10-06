class Not : public SubExpression
{
public:
       Not(Expression* left) : SubExpression(left)
       {
       }
       int evaluate()
       {
           return !left->evaluate();
       }
};


