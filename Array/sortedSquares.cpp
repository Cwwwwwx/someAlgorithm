#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//977.���������ƽ��

class Solution 
{
public:
    vector<int> sortedSquares1 (vector<int> &nums) //������
    {
        for (int i = 0; i < nums.size(); i++)
        {
            nums[i] *= nums[i]; 
        }
        sort(nums.begin(), nums.end());
        return nums;
    }
    
    //˫ָ�뷨
    vector<int> sortedSquares2(vector<int>& A) {
        int k = A.size() - 1;
        vector<int> result(A.size(), 0);
        for (int i = 0, j = A.size() - 1; i <= j;) { // ע������Ҫi <= j����Ϊ���Ҫ��������Ԫ��
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