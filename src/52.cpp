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
    int ans = 0;
    vector<int> cur;
    int n;

    int totalNQueens(int n)
    {
        this->n = n;

        dfs(0);

        return this->ans;
    }

    void dfs(int depth)
    {
        if (depth == n)
        {
            ++this->ans;
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