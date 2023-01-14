#include <iostream>
using namespace std;
//383.����� https://leetcode.cn/problems/ransom-note/
/*����һ������� (ransom) �ַ�����һ����־(magazine)�ַ������жϵ�һ���ַ��� ransom �ܲ����ɵڶ����ַ��� magazines ������ַ����ɡ�
������Թ��ɣ����� true �����򷵻� false��
(��Ŀ˵����Ϊ�˲���¶������ּ���Ҫ����־������������Ҫ����ĸ����ɵ����������˼����־�ַ����е�ÿ���ַ�ֻ����������ַ�����ʹ��һ�Ρ�)
��magazinÿ�����ֵ��ַ��洢�������鹹���Ĺ�ϣ���У�����һ��++��Ȼ�����ransomnote�������������Ƿ����--
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