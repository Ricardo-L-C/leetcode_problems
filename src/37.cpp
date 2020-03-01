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
    using pos = vector<vector<char>>::size_type;
    const pos maxPos = 9;

    bool dfs(vector<vector<char>>& board, pos row, pos col)
    {
        for (pos i = row; i < maxPos; ++i)
            for (pos j = 0; j < maxPos; ++j)
                if (board[i][j] == '.')
                {
                    vector<int> available = calAvailable(board, i, j);

                    for (decltype(available.size()) item = 0; item < maxPos; ++item)
                    {
                        if (available[item] == 0)
                        {
                            board[i][j] = '1' + static_cast<char>(item);

                            if (dfs(board, i, j))
                                return true;

                            board[i][j] = '.';
                        }
                    }

                    return false;
                }

        return true;
    }

    vector<int> calAvailable(const vector<vector<char>>& board, pos row, pos col)
    {
        vector<int> available(9, 0);

        for (pos i = 0; i < maxPos; ++i)
        {
            if (board[row][i] != '.')
                available[board[row][i] - '1'] = 1;

            if (board[i][col] != '.')
                available[board[i][col] - '1'] = 1;
        }

        for (pos i = 0; i < 3; ++i)
            for (pos j = 0; j < 3; ++j)
                if (board[row / 3 * 3 + i][col / 3 * 3 + j] != '.')
                    available[board[row / 3 * 3 + i][col / 3 * 3 + j] - '1'] = 1;

        return available;
    }

    void solveSudoku(vector<vector<char>>& board)
    {
        dfs(board, 0, 0);
    }
};

int main()
{
    Solution a;


}