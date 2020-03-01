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
    vector<vector<string>> ans;
    vector<string> temp;
    vector<int> cur;
    int n;

    vector<vector<string>> solveNQueens(int n)
    {
        this->n = n;

        for (auto i = 0; i < n; ++i)
            temp.emplace_back(n, '.');

        dfs(0);

        return ans;
    }

    void dfs(int depth)
    {
        if (depth == n)
        {
            auto t = this->temp;

            for (auto i = 0; i < n; ++i)
                t[i][cur[i]] = 'Q';

            ans.push_back(move(t));

            return;
        }

        for (int i = 0; i < n; ++i)
        {
            if (check(depth, i))
            {
                cur.push_back(i);
                dfs(depth + 1);
                cur.pop_back();
            }
        }
    }

    bool check(int x, int y)
    {
        if (x == 0)
            return true;

        for (auto i = 0; i < cur.size(); ++i)
            if (y == cur[i] || abs(y - cur[i]) == x - i)
                return false;

        return true;
    }
};

int main()
{
    Solution a;
}