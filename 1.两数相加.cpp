#include <iostream>
#include <vector>
#include <unordered_map>

using std::vector;
using std::cout;
using std::endl;

vector<int> twoSum(vector<int>& nums, int target)
{
    std::unordered_map<int, int> hashtable;
    for (int i = 0; i < nums.size(); ++i) {
        auto it = hashtable.find(target - nums[i]);     //就是利用了哈希表查找时间复杂度O(1)的性质。
        if (it != hashtable.end()) {
            return {it->second, i};
        }
        hashtable[nums[i]] = i;
    }
    return {};
}

int main()
{
    vector<int> vec = {2,7,11,15};

    for (auto a : twoSum(vec, 9))
    {
        cout << a << " " ;
    }
    cout << endl;

}