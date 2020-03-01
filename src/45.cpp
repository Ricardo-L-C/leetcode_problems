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
    int jump(vector<int>& nums)
    {
        if (nums.empty() || nums.size() == 1)
            return 0;

        int turn = 0;
        decltype(nums.size()) pos = 0, far = 0;

        while (pos + nums[pos] < nums.size() - 1)
        {
            for (auto i = pos, j = pos; i <= j + nums[j] && i < nums.size(); ++i)
            {
                if (far <= i + nums[i])
                {
                    far = i + nums[i];
                    pos = i;
                }
            }

            ++turn;
        }

        return turn + 1;
    }
};

int main()
{
	Solution a;
    vector<int> arr{2, 3, 1};
    a.jump(arr);
}