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
    vector<string> fullJustify(vector<string>& words, int maxWidth)
    {
        if (words.empty())
            return {};

        vector<string> ans;

        auto it = words.begin();

        while (it != words.end())
        {
            if (it == words.end() - 1)
            {
                ans.push_back(*it + string(maxWidth - it->size(), ' '));
                break;
            }

            auto tempIt = it;
            int lineCount = 0;
            int realNum = 0;
            while (tempIt != words.end())
            {
                if (lineCount + tempIt->size() == maxWidth)
                    lineCount += tempIt->size(), realNum += tempIt->size();
                else if (lineCount + tempIt->size() + 1 <= maxWidth)
                    lineCount += tempIt->size() + 1, realNum += tempIt->size();
                else
                    break;

                ++tempIt;
            }

            if (it + 1 == tempIt)
            {
                ans.push_back(*it + string(maxWidth - it->size(), ' '));
                ++it;
                continue;
            }

            if (tempIt == words.end())
            {
                string tempStr;
                while (it != tempIt - 1)
                {
                    tempStr += *it + " ";
                    ++it;
                }
                tempStr += *it;
                ++it;

                tempStr = tempStr+string(maxWidth - tempStr.size(), ' ');
                ans.push_back(move(tempStr));
                break;
            }

            string tempStr;
            int spaceCount = tempIt - it - 1, spaceNum = maxWidth - realNum;
            while (it != tempIt)
            {
                tempStr += *it++;
                
                if (!spaceCount)
                    break;

                if (spaceNum % spaceCount > 0)
                {
                    tempStr += string(spaceNum / spaceCount + 1, ' ');
                    spaceNum -= spaceNum / spaceCount + 1;
                }
                else
                {
                    tempStr += string(spaceNum / spaceCount, ' ');
                    spaceNum -= spaceNum / spaceCount;
                }
                --spaceCount;
            }
            
            ans.push_back(move(tempStr));
        }

        return ans;
    }
};

int main()
{
    Solution a;

    vector<string> arr = {"ask", "not", "what", "your", "country", "can", "do", "for", "you", "ask", "what", "you", "can", "do", "for", "your", "country"};
    
    a.fullJustify(arr, 16);
}