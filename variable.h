#include <sstream>
#include <vector>

using namespace std;
class Variable : public Operand
{
public:
       Variable(string name)
       {
              this->name = name;
       }
       int evaluate();
private:
       string name;
};
