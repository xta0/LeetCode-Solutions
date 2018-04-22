#include <iostream>
#include <stack>
using namespace std;

class Solution
{
  public:
    bool isValid(string s)
    {
        stack<char> ss;

        for (auto c : s)
        {
            if (c == '(' || c == '[' || c == '{')
            {
                ss.push(c);
            }
            else
            {
                if (ss.empty())
                {
                    return false;
                }
                else
                {
                    char top = ss.top();
                    if (c == ')')
                    {
                        if (top != '(')
                        {
                            return false;
                        }
                    }
                    else if (c == '}')
                    {
                        if (top != '{')
                        {
                            return false;
                        }
                    }
                    else
                    {
                        if (top != '[')
                        {
                            return false;
                        }
                    }
                    ss.pop();
                }
            }
        }
        return ss.empty();
    }
    
};
int main()
{

    Solution s;
    cout << s.isValid("[") << endl;
    cout << s.isValid("()") << endl;
    cout << s.isValid("()[]{}") << endl;
    cout << s.isValid("(]") << endl;
    cout << s.isValid("([)]") << endl;
    cout << s.isValid("{[]}") << endl;

    return 0;
}
