#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//��454��.�������II https://leetcode.cn/problems/4sum-ii/
/*�����ĸ��������� nums1��nums2��nums3 �� nums4 �����鳤�ȶ��� n ����������ж��ٸ�Ԫ�� (i, j, k, l) �����㣺

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
�ȱ���ǰ�������������ӵ�ֵ����map�У��ڱ���������������ӵ�ֵ�ĸ����Ƿ���map�г��ֹ�
?*/
class Solution
{
public:
    int fourSumCount(vector<int> A, vector<int> B, vector<int> C, vector<int> D)
    {
        unordered_map<int, int> map;
        for (int a : A)
        {
            for (int b : B)
            {
                map[a + b]++;
            }
        }

        int count = 0;
        
        for (int c : C)
        {
            for(int d : D)
            {
                if (map.find(0 - (c + d)) != map.end())
                {
                    count += map[0 - (c + d)];
                }
            }
        }
        return count;
    }
}