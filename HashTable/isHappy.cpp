/*��дһ���㷨���ж�һ���� n �ǲ��ǿ�������

��������������Ϊ������һ����������ÿһ�ν������滻Ϊ��ÿ��λ���ϵ����ֵ�ƽ���ͣ�
Ȼ���ظ��������ֱ���������Ϊ 1��Ҳ������ ����ѭ�� ��ʼ�ձ䲻�� 1����� ���Ա�Ϊ  1����ô��������ǿ�������

��� n �ǿ������ͷ��� True �����ǣ��򷵻� False ��

ʾ����

���룺19
�����true
���ͣ�
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1*/
#include <iostream>
#include <unordered_set>
using namespace std;
//������������Ҫ�����ж�һ��Ԫ���Ƿ���ּ������ʱ�򣬾�Ҫ���ǹ�ϣ���ˡ�
//�ж�sum�Ƿ��ظ����־Ϳ���ʹ��unordered_set
class Solution
{
public:
    int getSum(int n ) //����ÿλ�ϵ�ƽ����
    {
        int sum = 0;
        while(n)
        {
            sum += (n % 10) * (n % 10);
            n = n / 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        unordered_set<int> set; 
        while(1)
        {
            int sum = getSum(n);
            if (sum == 1)
            {
                return true;
            }
            
            if (set.find(sum) != set.end()) //���sum�����ֹ���˵������ѭ���򷵻�false
            {
                return false;
            }else{
                set.insert(sum);
            }
            n = sum;
        }
    }
};

int main()
{
    Solution sol;
    cout << sol.isHappy(2);
}
