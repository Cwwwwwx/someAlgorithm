#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;
//第454题.四数相加II https://leetcode.cn/problems/4sum-ii/
/*给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：

0 <= i, j, k, l < n
nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
先遍历前两个数组各个相加的值储存map中，在遍历后两个数组相加的值的负数是否在map中出现过
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