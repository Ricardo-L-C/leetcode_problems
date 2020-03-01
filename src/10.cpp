#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
using namespace std;

class Solution
{
public:
	bool isMatch(string s, string p)
	{
		vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1));

		dp[0][0] = 1;

		for (int i = 2; i < p.size() + 1; ++i)
		{
			if (p[i - 1] == '*' && dp[0][i - 2])
				dp[0][i] = 1;
			else
				dp[0][i] = 0;
		}

		for (int i = 1; i < s.size() + 1; ++i)
			dp[i][0] = 0;

		for (int i = 1; i < s.size() + 1; ++i)
		{
			for (int j = 1; j < p.size() + 1; ++j)
			{
				if (s[i - 1] == p[j - 1] || p[j - 1] == '.')
					dp[i][j] = dp[i - 1][j - 1];
				else if (p[j - 1] == '*')
				{
					if (p[j - 2] != s[i - 1] && p[j - 2] != '.')
						dp[i][j] = dp[i][j - 2];
					else
						dp[i][j] = dp[i - 1][j] | dp[i][j - 1] | dp[i][j - 2];
				}
				else
				{
					dp[i][j] = 0;
				}
			}
		}
		return static_cast<bool>(dp[s.size()][p.size()]);
	}
};

int main()
{
    Solution a;
}