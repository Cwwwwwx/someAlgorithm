/*给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

来源：力扣（LeetCode）
链接：https://leetcode.cn/problems/3sum
双指针法，用i遍历，右指针right指向数组尾部，左指针指向i + 1，当三数和大于0，right--，反之亦然。
主要难点在判断重复
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] > 0)
            {
                return result;
            }
            
            if (i > 0 && nums[i] == nums[i - 1]) //判断a是否重复，如果判断i和i + 1的大小，[-1, -1, 2]的情况就被掠过
            {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            while (right > left)
            {
                if (nums[i] + nums[left] + nums[right] > 0) right--;
                else if (nums[i] + nums[left] + nums[right] < 0) left++;
                else{
                    result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                    while (right > left && nums[right] == nums[right - 1]) right--; //判断bc重复要放在先得出结果后，要考虑[0,0,0]
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;                    
                }
            }

        }
        return result;
    }
};