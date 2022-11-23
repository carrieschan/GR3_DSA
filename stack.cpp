#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

string infixToPostfix(stack<char> stack, string infix)
{
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        char ch = infix[i];

        if (isalnum(ch))
        {
            postfix += ch;
        }
        else if (ch == '(')
        {

            stack.push('(');
        }
        else if (ch == ')')
        {
            while (stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.pop();
        }
        else
        {
            while (!stack.empty() && precedence(infix[i]) <= precedence(stack.top()))
            {
                postfix += stack.top();
                stack.pop();
            }
            stack.push(ch);
        }
    }
    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }

    return postfix;
}

string InfixToPrefix(stack<char> s, string infix)
{
    string prefix;
    reverse(infix.begin(), infix.end());
    for (int i = 0; i < infix.length(); i++)
    {
        if (infix[i] == '(')
        {
            infix[i] = ')';
        }
        else if (infix[i] == ')')
        {
            infix[i] = '(';
        }
    }
    prefix = infixToPostfix(s, infix);
    reverse(prefix.begin(), prefix.end());
    return prefix;
}

int main()
{

    string infix, prefix, postfix;
    stack<char> stack;

    cout << "Enter a Infix Expression : ";
    cin >> infix;

    cout << "\n\nINFIX EXPRESSION: " << infix << endl;
    prefix = InfixToPrefix(stack, infix);
    cout << endl
         << "PREFIX EXPRESSION: " << prefix;

    postfix = infixToPostfix(stack, infix);
    cout << endl
         << "POSTFIX EXPRESSION: " << postfix;

    return 0;
}