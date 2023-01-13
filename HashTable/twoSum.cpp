/*����һ���������� nums ��һ��Ŀ��ֵ target�������ڸ��������ҳ���ΪĿ��ֵ���� ���� ���������������ǵ������±ꡣ

����Լ���ÿ������ֻ���Ӧһ���𰸡����ǣ�������ͬһ��Ԫ�ز���ʹ�����顣

ʾ��:

���� nums = [2, 7, 11, 15], target = 9

��Ϊ nums[0] + nums[1] = 2 + 7 = 9

���Է��� [0, 1]*/
//1. ����֮�� https://leetcode.cn/problems/two-sum/
//map�еĴ洢�ṹΪ {key������Ԫ�أ�value������Ԫ�ض�Ӧ���±�}
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
            map.insert(pair<int, int>(nums[i], i)); //ע���β�д��
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