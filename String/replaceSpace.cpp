#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;
/*请实现一个函数，把字符串 s 中的每个空格替换成"%20"。

示例 1： 输入：s = "We are happy."
输出："We%20are%20happy."
剑指Offer 05.替换空格 https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
*/
/**
 * 思路
 * 用双指针法，根据空格数来扩建数组，oldptr指向就数组尾端，newptr指向新数组尾端，遍历，当s[oldptr]
 * 非空时，直接赋值给s[newptr]，否则赋值%20
 * 从前向后填充就是O(n^2)的算法了，因为每次添加元素都要将添加元素之后的所有元素向后移动。
 * 其实很多数组填充类的问题，都可以先预先给数组扩容带填充后的大小，然后在从后向前进行操作。
 * 这么做有两个好处：
 * 1.不用申请新数组
 * 2.从后向前填充元素，避免了从前向后填充元素时，每次添加元素都要将添加元素之后的所有元素向后移动的问题。
*/
class Solution {
public:
    string replaceSpace(string s) {
        int count =  0;
        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '')
            count++;
        }
        int oldptr = s.size();
        s.resize(s.size() + 2*count);
        int newptr = s.size();
        for (int i = oldptr - 1, j = newptr - 1; i < j; i--, j--)
        {
            if (s[i] != ' ')
            {
                s[j] = s[i];
            }else
            {
                s[j] = '0';
                s[j - 1] = '2';
                s[j - 2] = '%';
                j -= 2;
            }
        }
        return s;
    }
};