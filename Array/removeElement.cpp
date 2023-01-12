#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/remove-element/
//27.移除元素
class Solution
{   
public:
// 暴力法
    int removeElement1(vector<int> &nums, int val)
    {
        int size = nums.size();
        for (int i = 0; i < size; i++)
        {
            if (nums[i] == val)
            {
                for(int j = i + 1; j < size; j++)
                {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }

    //双指针法
    // 快指针：寻找新数组的元素 ，新数组就是不含有目标元素的数组
    // 慢指针：指向更新 新数组下标的位置
    int removeElement2(vector<int> &nums, int val)
    {
        int slowptr = 0;
        for (int fastptr = 0; fastptr < nums.size(); fastptr++)
        {
            if (nums[fastptr] != val)
            nums[slowptr++] = nums[fastptr];
        }
        return slowptr;
    }
};

int main()
{
    vector<int> nums = {0,1,2,2,3,0,4,2};
    Solution sol;
    int size = sol.removeElement2(nums, 3);
    for (int i = 0; i < size; i++)
    {
        cout << nums[i] << " ";
    }
    cout << "hello";
}