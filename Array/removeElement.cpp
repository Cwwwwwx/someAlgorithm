#include <iostream>
#include <vector>
using namespace std;

// https://leetcode.cn/problems/remove-element/
//27.�Ƴ�Ԫ��
class Solution
{   
public:
// ������
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

    //˫ָ�뷨
    // ��ָ�룺Ѱ���������Ԫ�� ����������ǲ�����Ŀ��Ԫ�ص�����
    // ��ָ�룺ָ����� �������±��λ��
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