//209.长度最小的子数组
#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(vector<int> nums, int target)
    {
        int k = 0;
        int min = INT32_MAX;
        int current = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            k = 0;
            for (int j = i; j < nums.size(); j++)
            {
                k += nums[j];
                if (k >= target)
                {
                    current = j - i + 1; 
                    if(current < min)
                    min = current;
                    break;
                }
            }
        }
        return min == INT32_MAX ? 0 : min;
    }

    //滑动窗口的精妙之处在于根据当前子序列和大小的情况，不断调节子序列的起始位置
    int minSubArrayLen2(vector<int> nums, int target) //滑动窗口法
    {
        int result = INT32_MAX;
        int sum = 0;
        int length = 0;
        int start = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            sum += nums[i];
            while (sum >= target)
            {
                length = i - start + 1;
                result = result < length ? result : length;
                sum -= nums[start++]; 
            }
        }
        return result == INT32_MAX ? 0 : result;
    }
};

int main ()
{
    vector<int> nums = {2,3,1,2,4,3};
    Solution sol;
    cout << sol.minSubArrayLen2(nums, 7);
}