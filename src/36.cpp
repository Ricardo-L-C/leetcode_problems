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
    bool isValidSudoku(vector<vector<char>>& board)
    {
        int arr[9]{};

        // ∫·≈≈
        for (const auto & i:board)
        {
            memset(arr, 0, sizeof(arr));
            for (const auto& j : i)
                if(j != '.' )
                    ++arr[j - '1'];

            for (const auto& j : arr)
                if (j > 1)
                    return false;
        }

        //  ˙≈≈
        for (int i = 0; i < 9; ++i)
        {
            memset(arr, 0, sizeof(arr));
            for (int j = 0; j < 9; ++j)
                if (board[j][i] != '.')
                    ++arr[board[j][i] - '1'];

            for (const auto& j : arr)
                if (j > 1)
                    return false;
        }

        // æ≈π¨∏Ò
        for (int i = 0; i < 9; ++i)
        {
            memset(arr, 0, sizeof(arr));
            for (int j = 0; j < 3; ++j)
                for (int k = 0; k < 3; ++k)
                    if (board[i / 3 * 3 + k][i % 3 * 3 + j] != '.')
                        ++arr[board[i / 3 * 3 + k][i % 3 * 3 + j] - '1'];

            for (const auto& j : arr)
                if (j > 1)
                    return false;
        }

        return true;
    }
};

int main()
{
    auto s = Solution();
    auto ss = vector<vector<char>>{};
    
    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 3; ++j)
            for (int k = 0; k < 3; ++k)
                    cout << i / 3 + k << "," << i % 3 * 3 + j << " ";

        cout << endl;
    }

    //auto c = s.isValidSudoku(ss);
    //cout << c[0] << " " << c[1] << endl;
}