#include <iostream>
#include <string>
using namespace std;
bool isKeyword(string name)
{
    if (name == "int"    || name == "float"  ||
        name == "double" || name == "char"   ||
        name == "string" || name == "static" ||
        name == "public" || name == "return")
    {
        return true;
    }
    return false;
}

bool isValid(string name)
{
    if (name.length() == 0)
    {
        cout << "Reason: Name is empty." << endl;
        return false;
    }

    if (name[0] >= '0' && name[0] <= '9')
    {
        cout << "Reason: Cannot start with a digit." << endl;
        return false;
    }

    for (int i = 0; i < name.length(); i++)
    {
        char ch = name[i];

        if (ch >= 'a' && ch <= 'z') continue;
        if (ch >= 'A' && ch <= 'Z') continue;
        if (ch >= '0' && ch <= '9') continue;
        if (ch == '_') continue;

        cout << "Reason: Invalid character '" << ch << "' at position " << i << "." << endl;
        return false;
    }

    if (isKeyword(name))
    {
        cout << "Reason: '" << name << "' is a reserved keyword." << endl;
        return false;
    }

    return true;
}

int main()
{
    string name;

    cout << "Variable Name Validator" << endl;
    cout << "Type 'exit' to quit." << endl;

    while (true)
    {
        cout << "\nEnter variable name: ";
        cin >> name;

        if (name == "exit")
        {
            cout << "Goodbye" << endl;
            break;
        }

        if (isValid(name))
            cout << "Result: VALID" << endl;
        else
            cout << "Result: INVALID" << endl;
    }

    return 0;
}