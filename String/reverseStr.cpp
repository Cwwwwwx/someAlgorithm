#include <iostream>
#include <vector>
using namespace std;
/*����һ���ַ��� s ��һ������ k�����ַ�����ͷ����, ÿ������ 2k ���ַ����ͷ�ת�� 2k ���ַ��е�ǰ k ���ַ���

���ʣ���ַ����� k ������ʣ���ַ�ȫ����ת��

���ʣ���ַ�С�� 2k �����ڻ���� k ������תǰ k ���ַ��������ַ�����ԭ����
541. ��ת�ַ���
*/

//�����˼���˺ܾã�ʣ���ַ�ָ�������size - 2nk�Ĳ��֣����ಿ��ֱ�ӷ�תǰk���ַ��Ϳ�����

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size() ;i += 2*k)
        {
            if (i + k <= s.size()){ //�����ж�������Ϊ�˲�������Խ�磬ͬʱҲ�������λʣ���ַ���k�Ĺ�ϵ
            reverse(s.begin() + i, s.begin() + i + k)
            }else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};