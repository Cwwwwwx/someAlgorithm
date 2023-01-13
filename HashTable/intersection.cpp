#include <unordered_set>
#include <iostream>
#include <vector>
using namespace std;
//349. ��������Ľ���
//��Ҫ�������˽��¹�ϣ��stl�������÷�
class Solution 
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> result_set;// ��Ž����֮������set��Ϊ�˸������ȥ��
        unordered_set<int> nums_set(nums1.begin(), nums1.end());
        for (auto num : nums2)
        {
            // ����nums2��Ԫ�� ��nums_set���ֳ��ֹ�
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
    for (auto o : test) //������÷���ֱ�ӷ��������е�ֵ
    {
        cout << o << " ";
    }
}