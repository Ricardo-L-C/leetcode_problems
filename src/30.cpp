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
    vector<int> findSubstring(string s, vector<string>& words)
    {
        if (s.empty() || words.empty())
            return {};

        auto wordLen = words[0].size(), sumLen = wordLen * words.size();
        vector<decltype('a' + 'b')> posSum(wordLen, 0);
        vector<int> ans;
        unordered_map<string, int> wordCnt;

        for (const auto& word : words)
        {
            ++wordCnt[word];
            for (decltype(wordLen) i = 0; i < wordLen; ++i)
                posSum[i] += word[i];
        }

        for (auto it = s.begin(); s.end() - it >= sumLen; ++it)
        {
            decltype(wordLen) i = 0;
            while (i < wordLen)
            {
                auto temp = +*(it + i);

                for (decltype(words.size()) j = 1; j < words.size(); ++j)
                    temp += *(it + i + wordLen * j);
                
                cout << "temp:" << temp << "," << posSum[i] << endl;

                if (temp != posSum[i])
                    break;

                ++i;
            }

            cout << i << "==" << wordLen << endl;

            if (i == wordLen)
            {
                cout << it - s.begin();

                unordered_map<string, int> temp;
                for (decltype(words.size()) j = 0; j < words.size(); ++j)
                {
                    string clip = s.substr(it - s.begin() + j * wordLen, wordLen);
                    ++temp[clip];
                    if (!wordCnt.count(clip))
                        break;
                }
                if (temp == wordCnt)
                    ans.push_back(it - s.begin());
            }
            
        }

        return ans;
    }
};

int main()
{
    auto s = Solution();
    vector<string> arr = {"foo", "bar"};

    cout << 'f' + 'b' << " " << 'a' + 'o' << " " << 'o' + 'r' << endl;

    auto ans = s.findSubstring("barfoothefoobarman", arr);

    cout << "ans:";
    for (const auto& i : ans)
        cout << i << " ";
}