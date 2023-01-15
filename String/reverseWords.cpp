#include <iostream>
using namespace std;
/*给定一个字符串，逐个翻转字符串中的每个单词。

示例 1：
输入: "the sky is blue"
输出: "blue is sky the"
151.翻转字符串里的单词 https://leetcode.cn/problems/reverse-words-in-a-string/
*/

/**
 * 思路
 * 移除多余空格
 * 将整个字符串反转
 * 将每个单词反转
*/
class Solution
{
public:
    void reverse(string &s, int start, int end)
    {
        for (int i = start, j = end; i < j; i++, j--)
        {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string &s) //移除多余空格， 双指针法，遇到空格++
    {
        int slow = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                if (slow != 0) s[slow++] = ' ';
                while (i < s.size() && s[i] != ' ')
                {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    string reverseWords(string s)
    {
        int test = s.size();
        removeExtraSpaces(s);
        reverse(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); ++i)
        {
            if (i == s.size() || s[i] == ' ')
            {   
                reverse(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }
};

int main()
{
    string s = " abc  poi ";
    Solution sol;
    cout << sol.reverseWords(s);
}