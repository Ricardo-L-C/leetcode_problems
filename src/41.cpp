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
    int firstMissingPositive(vector<int>& nums)
    {
        // has 1?
        bool hasOne = false;
        for (auto& i : nums)
        {
            if (i == 1)
                hasOne = true;

            if (i < 1 || i > nums.size())
                i = 1;
        }

        if (!hasOne)
            return 1;

        for (auto& i : nums)
            nums[abs(i) - 1] = -abs(nums[abs(i) - 1]);

        for (decltype(nums.size()) i = 0; i < nums.size(); ++i)
            if (nums[i] > 0)
                return i + 1;

        return nums.size() + 1;
    }
};

int main()
{
    Solution a;
    vector<int> arr{3, 4, -1, 1};
    a.firstMissingPositive(arr);
}