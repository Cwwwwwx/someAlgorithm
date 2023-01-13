#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;
//349. 两个数组的交集
//需要再深入了解下哈希表stl容器的用法
class Solution 
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set;// 存放结果，之所以用set是为了给结果集去重
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (auto num : nums2)
        {
            // 发现nums2的元素 在nums_set里又出现过
            if (nums_set.find(num) != nums_set.end())
            {
                result_set.insert(num);
            }
        }
        return vector<int>(result_set.begin(), result_set.end());
    }
};

int main ()
{
    vector<int> a = {1,2,3,4};
    vector<int> b = {2,3};
    Solution sol;
    vector<int> test(sol.intersection(a, b));
    for (auto o : test) //这里的用法会直接返回数组中的值
    {
        cout << o << " ";
    }
}