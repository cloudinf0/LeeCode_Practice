#include <unordered_map>
#include <string>
using std::string;
using std::unordered_map;

unordered_map<char, int> ROMAN = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
};

class Solution {
public:
    int romanToInt(string s)
    {
        int ans = 0;
        for (int i = 0; i + 1 < s.size(); i++)
        {
            int x = ROMAN[s[i]], y = ROMAN[s[i + 1]];
            ans += x < y ? -x : x; //这个三路运算很巧妙
        }
        return ans + ROMAN[s.back()]; // 加上最后一个罗马数字
    }
};