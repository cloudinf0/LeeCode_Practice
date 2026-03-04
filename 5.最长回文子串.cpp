#include <string>
#include <iostream>

using std::string;
using std::cin;
using std::cout;

string longestPalindrome(string s)
{
    char type = -1;         //0表示aa型，1表示aba型
    int head = 0;
    int longest = 0;
    int longestPtr = 0;
    int len = s.length();

    int p, q;
    while (head <= len)
    {
        //检测aa型
        p = head;
        q = head + 1;
        int temp = 0;
        while (p >= 0 && q <= len && s[p] == s[q])
        {
            ++temp;
            --p;
            ++q;
        }
        if (temp > longest)
        {
            if (temp > 0)    type = 0;
            longest = temp;
            longestPtr = head - temp;
        }

        //检测aba型(aba会比aa长一位)
        p = head - 1;
        q = head + 1;
        temp = 0;
        while (p >= 0 && q <= len && s[p] == s[q])
        {
            ++temp;
            --p;
            ++q;
        }
        if (temp >= longest)
        {
            if (temp > 0)   type = 1;
            longest = temp;
            longestPtr = head - temp;
        }

        ++head;
    }

    //输出
    string ans;
    switch (type)
    {
        case -1:
            ans += s[0];
            break;
        case 0:
            for (int i = 1; i <= longest * 2 ; ++i)
            {
                ans += s[longestPtr + i];
            }
            break;
        case 1:
            for (int i = 0; i <= longest * 2 ; ++i)
            {
                ans += s[longestPtr + i];
            }
            break;
    }

    return ans;
}

int main()
{
    cout << "Hello" << std::endl;
    string s, a;
    cin >> s;

    a = longestPalindrome(s);
    cout << a;
}