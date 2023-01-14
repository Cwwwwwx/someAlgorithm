/*����һ���������� nums ���ж��Ƿ������Ԫ�� [nums[i], nums[j], nums[k]] ���� i != j��i != k �� j != k ��ͬʱ������ nums[i] + nums[j] + nums[k] == 0 ����

�㷵�����к�Ϊ 0 �Ҳ��ظ�����Ԫ�顣

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode.cn/problems/3sum
˫ָ�뷨����i��������ָ��rightָ������β������ָ��ָ��i + 1���������ʹ���0��right--����֮��Ȼ��
��Ҫ�ѵ����ж��ظ�
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
            
            if (i > 0 && nums[i] == nums[i - 1]) //�ж�a�Ƿ��ظ�������ж�i��i + 1�Ĵ�С��[-1, -1, 2]������ͱ��ӹ�
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
                    while (right > left && nums[right] == nums[right - 1]) right--; //�ж�bc�ظ�Ҫ�����ȵó������Ҫ����[0,0,0]
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    right--;
                    left++;                    
                }
            }

        }
        return result;
    }
};