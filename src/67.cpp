#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string ans;

        int sizea = a.size(), sizeb = b.size();
        bool carry = false;

        while (sizea && sizeb)
        {
            auto c = a[--sizea] - '0' + b[--sizeb] - '0';

            if (c == 2 && carry)
            {
                ans.append(1, '1');
            }
            else if (c == 2 || c == 1 && carry)
            {
                ans.append(1, '0');
                carry = true;
            }
            else
            {
                ans.append(1, '0' + carry + c);
                carry = false;
            }
        }

        cout << sizea << sizeb << endl;

        while (sizea)
        {
            auto c = a[--sizea] - '0';

            if (carry && c == 1)
                ans.append(1, '0');
            else
            {
                ans.append(1, '0' + c + carry);
                carry = false;
            }
        }

        while (sizeb)
        {
            auto c = b[--sizeb] - '0';

            if (carry && c == 1)
                ans.append(1, '0');
            else
            {
                ans.append(1, '0' + c + carry);
                carry = false;
            }
        }

        if (carry)
            ans.append(1, '1');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};

int main()
{
    auto a = Solution();
}