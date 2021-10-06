#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"


SymbolTable symbolTable;
void parseAssignments(stringstream& in);
int main()
{
       Expression* expression;
       char paren, comma;
       cout << "Enter name of the input file containing the expression(s) you wish to test.";
       cout << endl;
       cout << "Add the .txt extension when entering the filename.";
       cout << endl;
       cout << "The input file must be in the same directory/folder as this program.";
       cout << endl;
       string filename;
       cin >> filename;
       string line;
       ifstream fin(filename);
       if (!fin.is_open())
              perror("error while opening file");
       while (getline(fin, line))
       {
              symbolTable.init();
              if (!fin)
                     break;
              stringstream in(line, ios_base::in);
              in >> paren;
              cout << line << " ";
              expression = SubExpression::parse(in);
              in >> comma;
              parseAssignments(in);
              int result = expression->evaluate();
              cout << "Value = " << result << endl;
       }
       system("pause");
       return 0;

}

//definition of the function parseAssignments()

void parseAssignments(stringstream& in)

{

    char assignop, delimiter;

    string variable;

    int value;

       symbolTable.init();

    do

    {

        variable = parseName(in);

        in >> ws >> assignop >> value >> delimiter;

        symbolTable.insert(variable, value);

    }

    while (delimiter == ',');

}
