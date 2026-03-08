#include <iostream>
#include <string>
#include <vector>
using std::string;
using std::vector;
using std::cout;
using std::endl;

string longestCommonPrefix(vector<string>& strs)
{
    if (strs.empty()) return "";        //修改1 检测为空（防止未定义）

    string ans = "";
    int len = strs[0].length();         //关于int和char内存占用问题

    for (int index = 0; index < len; ++index)
    {
        char currentChar = strs[0][index];
        for (const auto& ch : strs)     //修改2 取出一个引用，减少内存消耗
        {
            if (ch[index] != currentChar)
            {
                return ans;
            }
        }
        ans += currentChar;
    }
    return ans;
}

int main()
{
    vector<string> strs = {"flower" , "flower" , "floggg"};


    cout << longestCommonPrefix(strs) << endl;
}
