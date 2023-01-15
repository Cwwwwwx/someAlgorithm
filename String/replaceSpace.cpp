#include <iostream>
#include <vector>
// #include <algorithm>
using namespace std;
/*��ʵ��һ�����������ַ��� s �е�ÿ���ո��滻��"%20"��

ʾ�� 1�� ���룺s = "We are happy."
�����"We%20are%20happy."
��ָOffer 05.�滻�ո� https://leetcode.cn/problems/ti-huan-kong-ge-lcof/
*/
/**
 * ˼·
 * ��˫ָ�뷨�����ݿո������������飬oldptrָ�������β�ˣ�newptrָ��������β�ˣ���������s[oldptr]
 * �ǿ�ʱ��ֱ�Ӹ�ֵ��s[newptr]������ֵ%20
 * ��ǰ���������O(n^2)���㷨�ˣ���Ϊÿ�����Ԫ�ض�Ҫ�����Ԫ��֮�������Ԫ������ƶ���
 * ��ʵ�ܶ��������������⣬��������Ԥ�ȸ��������ݴ�����Ĵ�С��Ȼ���ڴӺ���ǰ���в�����
 * ��ô���������ô���
 * 1.��������������
 * 2.�Ӻ���ǰ���Ԫ�أ������˴�ǰ������Ԫ��ʱ��ÿ�����Ԫ�ض�Ҫ�����Ԫ��֮�������Ԫ������ƶ������⡣
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