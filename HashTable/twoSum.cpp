/*给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。

你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。

示例:

给定 nums = [2, 7, 11, 15], target = 9

因为 nums[0] + nums[1] = 2 + 7 = 9

所以返回 [0, 1]*/
//1. 两数之和 https://leetcode.cn/problems/two-sum/
//map中的存储结构为 {key：数据元素，value：数组元素对应的下表}
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++)
        {
            int s = target - nums[i];
            auto iter = map.find(s);
            if (iter != map.end())
            {
                return {iter->second, i};
            }
            map.insert(pair<int, int>(nums[i], i)); //注意形参写法
        }
        return {};
    }
};

int main()
{
    vector<int> a = {1,2,3,4,5,6,7};
    Solution sol;
    vector<int> b(sol.twoSum(a, 3));
    for (auto o : b)
    {
        cout << o << " ";
    }
}