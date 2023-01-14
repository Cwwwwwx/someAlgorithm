#include <iostream>
using namespace std;
//383.赎金信 https://leetcode.cn/problems/ransom-note/
/*给定一个赎金信 (ransom) 字符串和一个杂志(magazine)字符串，判断第一个字符串 ransom 能不能由第二个字符串 magazines 里面的字符构成。
如果可以构成，返回 true ；否则返回 false。
(题目说明：为了不暴露赎金信字迹，要从杂志上搜索各个需要的字母，组成单词来表达意思。杂志字符串中的每个字符只能在赎金信字符串中使用一次。)
将magazin每个出现的字符存储在由数组构建的哈希表中，出现一次++，然后遍历ransomnote，查找数组中是否出现--
*/
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int record[26] = {0};
        for (int i = 0; i < magazine.size(); i++)
        {
            record[magazine[i] - 'a']++;
        }
        for (int i = 0; i < ransomNote.size(); i++)
        {
            record[ransomNote[i] - 'a']--;
            if (record[ransomNote[i] - 'a'] < 0)
            {
                return false;
            }
        }
        return true;
    }
};