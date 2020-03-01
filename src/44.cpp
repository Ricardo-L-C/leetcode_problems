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
	bool isMatch(string s, string p)
	{
		vector<vector<int>> dp(s.size() + 1, vector<int>(p.size() + 1));

		dp[0][0] = 1;

		for (decltype(p.size()) i = 1; i <= p.size(); ++i)
		{
			if (p[i - 1] == '*')
				dp[0][i] = dp[0][i - 1];
			else
				break;
		}

		for (decltype(s.size()) i = 1; i <= s.size(); ++i)
		{
			for (decltype(p.size()) j = 1; j <= p.size(); ++j)
			{
				if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
					dp[i][j] = dp[i - 1][j - 1];
				else if (p[j - 1] == '*')
				{
					for (decltype(j) k = 0; k <= i; ++k)
						if (dp[k][j - 1] == 1)
						{
							dp[i][j] = 1;
							break;
						}
				}
			}
		}

		return static_cast<bool>(dp[s.size()][p.size()]);
	}
};

int main()
{
    Solution a;
	a.isMatch("a", "a*");
}