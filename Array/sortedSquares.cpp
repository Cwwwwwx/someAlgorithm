#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//977.有序数组的平方

class Solution 
{
public:
    vector<int> sortedSquares1 (vector<int> &nums) //暴力法
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i]; 
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
    
    //双指针法
    vector<int> sortedSquares2(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // 注意这里要i <= j，因为最后要处理两个元素
            if (A[i] * A[i] < A[j] * A[j])  {
                result[k--] = A[j] * A[j];
                j--;
            }
            else {
                result[k--] = A[i] * A[i];
                i++;
            }
        }
        return result;
    }
};

int main ()
{
    vector<int> nums = {-7,-3,2,3,11};
    Solution sol;
    vector<int> nums2 = sol.sortedSquares2(nums);
    for (int i = 0; i < nums2.size(); i++)
    {
        cout << nums2[i] << " ";
    }
}