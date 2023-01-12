#include <iostream>
#include <vector>
using namespace std;

//35.??????
class Solution
{
public:
    int searchInsert1(vector<int> &nums, int val) //???
    {
        for (int i = 0; i < nums.size(); i++)
        {
            if(nums[i] >= val)
            return i;
        }
        return nums.size();
    }

    int searchInsert2(vector<int> nums, int target)//???
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right)
        {
            int middle = (left + right) / 2;
            if(nums[middle] > target)
            right = middle - 1;
            else if(nums[middle] < target)
            left = middle + 1;
            else
            return middle;
        } 
        return right + 1;
    }
};

int main()
{
    vector<int> nums = {1,2,4,5,6,7,8};
    Solution sol;
    cout << sol.searchInsert2(nums, 9);
}