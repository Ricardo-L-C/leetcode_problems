#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>
using namespace std;

class Solution
{
public:
    int longestValidParentheses(string s)
    {
        if (s.empty())
            return 0;

        int left = 0, right = 0, rleft = 0, rright = 0, max = 0;

        for (decltype(s.size()) i = 0; i < s.size(); ++i)
        {
            if (s[i] == '(')
                ++left;
            else
                ++right;

            if (left == right)
                max = max > 2 * right ? max : 2 * right;
            else if (right > left)
                left = right = 0;

            if (s[s.size() - i - 1] == '(')
                ++rleft;
            else
                ++rright;

            if (rleft == rright)
                max = max > 2 * rleft ? max : 2 * rleft;
            else if (rleft > rright)
                rleft = rright = 0;
        }

        return max;
    }
};

int main()
{
	Solution a;

    cout << a.longestValidParentheses(")()(((()))(()()()(()(()(())))(())()((()()(((()())()))(()()())())(())(()(()()()()))(((()())))(((()))))()()()))") << endl;
}