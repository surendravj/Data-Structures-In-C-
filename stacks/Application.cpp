#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string s1 = "{[({})]}";
    stack<char> stack;
    int i = 0;
    while (s1[i])
    {
        if (s1[i] == '(' || s1[i] == '[' || s1[i] == '{')
        {
            stack.push(s1[i]);
            i++;
        }
        if (s1[i] == ')' || s1[i] == '}' || s1[i] == '}')
        {
            stack.pop();
            i++;
        }
    }
    if (stack.empty())
        cout << "Brackets are balanced";
    else
        cout << "Brackets are unbalanced";
    return 0;
}