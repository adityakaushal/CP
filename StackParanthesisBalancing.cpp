#include <iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};

struct Node *newNode(char data)
{
    Node *tmp = new Node;
    tmp->data = data;
    tmp->next = NULL;
    return tmp;
}

class Stack
{
public:
    Node *top;
    Stack()
    {
        top = NULL;
    }

    void push(char x)
    {
        Node *tmp = newNode(x);
        tmp->next = top;
        top = tmp;
    }

    void pop()
    {
        Node *tmp = top;
        top = top->next;
        delete tmp;
    }

    bool empty()
    {
        if (top == NULL)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    char Top()
    {
        return top->data;
    }
};

bool ArePair(char opening, char closing)
{

    if (opening == '(' && closing == ')')
    {
        return true;
    }
    if (opening == '{' && closing == '}')
    {
        return true;
    }
    if (opening == '[' && closing == ']')
    {
        return true;
    }
    return false;
}

bool isParanthesisBalanced(string exp)
{
    Stack s;
    for (int i = 0; i < exp.length(); i++)
    {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
        {
            s.push(exp[i]);
        }
        else if (exp[i] == ')' || exp[i]  == '}' || exp[i] == ']')
        {
            if (s.empty() || !ArePair(s.Top(), exp[i]))
            {
                return false;
            }
            else
            {
                s.pop();
            }
        }
    }
    return s.empty() ? true : false;
}

int main()
{
    int T;
    cout<<"Enter the Number of Test Cases"<<endl;
    cin >> T;
    while (T--)
    {

        string expression;
        cout << "Enter the expression" << endl;
        cin >> expression;
        if (isParanthesisBalanced(expression))
        {
            cout << "Balanced" << endl;
        }
        else
        {
            cout << "Not Balanced" << endl;
        }
    }
    return 0;
}
