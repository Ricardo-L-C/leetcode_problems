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
    int trap(vector<int>& height)
    {
        if (height.empty())
            return 0;

        int sum = 0, lmax = 0, rmax = 0;

        auto left = height.begin(), right = height.end() - 1;

        while (left < right)
        {
            if (lmax < rmax)
            {
                *left >= lmax ? (lmax = *left) : sum += (lmax - *left);
                ++left;
            }
            else
            {
                *right >= rmax ? (rmax = *right) : sum += (rmax - *right);
                --right;
            }
        }

        return sum;
    }
};

int main()
{
    Solution a;

}