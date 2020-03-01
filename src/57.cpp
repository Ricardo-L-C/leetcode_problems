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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        auto left = intervals.begin();

        while (left != intervals.end() && (*left)[1] < newInterval[0])
            ++left;

        if (left == intervals.end())
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        auto right = left;

        while (right != intervals.end())
        {
            if ((*right)[0] > newInterval[1])
                break;

            if ((*right)[0] < newInterval[0])
                newInterval[0] = (*right)[0];

            if ((*right)[1] > newInterval[1])
                newInterval[1] = (*right)[1];

            right = intervals.erase(right);
        }

        intervals.insert(left, newInterval);

        return intervals;
    }
};

int main()
{
    Solution a;
}