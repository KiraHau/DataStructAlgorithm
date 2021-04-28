#include <iostream>
#include<stack>
using namespace std;


int main()
{
    bool isValid(string s);
    string s = "){";
    if (isValid(s)) cout << "1" << endl;
    else cout << "0" << endl;
}



bool isValid(string s) {
    if (s.length() % 2 == 1)
    {
        return false;
    }
    stack <char> a;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            a.push(')');
        }
        else if (s[i] == '[')
        {
            a.push(']');
        }
        else if (s[i] == '{')
        {
            a.push('}');
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if ( a.empty()|| s[i] != a.top())
            {
                return false;
            }
            else a.pop();
        }

    }
    if (a.empty()) return true;
    else return false;

}