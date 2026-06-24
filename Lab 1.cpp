#include <iostream>
#include <string>
using namespace std;

bool isReservedKeyword(string name)
{
    string keywords[8] = {"int", "float", "double", "char", "string", "static", "public", "return"};
    for (int i = 0; i < 8; i++) 
    {
        if (name == keywords[i]) 
        {
            return true;
        }
    }
    return false;
}

bool isValidChar(char ch) 
{
    if ((ch >= '0' && ch <= '9') ||
        (ch >= 'A' && ch <= 'Z') ||
        (ch >= 'a' && ch <= 'z') ||
        (ch == '_')) {
        return true;
    }
    return false;
}

bool isValidVariableName(string name) 
{
    if (name.length() == 0) 
    {
        cout << "Reason  : Variable name cannot be empty." << endl;
        return false;
    }
    if (name.at(0) >= '0' && name.at(0) <= '9') 
    {
        cout << "Reason  : Variable name cannot start with a digit ('" << name.at(0) << "')." << endl;
        return false;
    }
    for (int i = 0; i < name.length(); i++) 
    {
        if (!isValidChar(name.at(i))) 
        {
            cout << "Reason  : Invalid/special character '" << name.at(i) << "' found at position " << i << "." << endl;
            return false;
        }
    }
    if (isReservedKeyword(name)) 
    {
        cout << "Reason  : '" << name << "' is a reserved keyword." << endl;
        return false;
    }

    return true;
}

int main() 
{
    string varName;
    cout << "      Variable Name Validator (C++)     " << endl;
    cout << "Reserved Keywords : int, float, double, char," << endl;
    cout << "                    string, static, public, return" << endl;

    while (true) 
    {
        cout << "\nEnter variable name: ";
        cin >> varName;

        if (varName == "exit") 
        {
            cout << "Exiting program. Goodbye!" << endl;
            break;
        }

        cout << "Input   : " << varName << endl;

        if (isValidVariableName(varName)) 
        {
            cout << "Result  : VALID variable name." << endl;
        } else {
            cout << "Result  : INVALID variable name." << endl;
        }
    }

    return 0;
}