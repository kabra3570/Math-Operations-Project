
class SubExpression : public Expression

{

public:

       //constructors

       SubExpression(Expression* left, Expression* right);
       SubExpression(Expression* left);
       SubExpression(Expression* left, Expression* right, Expression* c);

       //declare a static function parse()

       static Expression* parse(stringstream& in);

protected:

       //declare the variables

       Expression* left;

       Expression* right;

       Expression* c;
};
