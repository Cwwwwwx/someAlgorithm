/*编写一个算法来判断一个数 n 是不是快乐数。

「快乐数」定义为：对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和，
然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。如果 可以变为  1，那么这个数就是快乐数。

如果 n 是快乐数就返回 True ；不是，则返回 False 。

示例：

输入：19
输出：true
解释：
1^2 + 9^2 = 82
8^2 + 2^2 = 68
6^2 + 8^2 = 100
1^2 + 0^2 + 0^2 = 1*/
#include <iostream>
#include <unordered_set>
using namespace std;
//当我们遇到了要快速判断一个元素是否出现集合里的时候，就要考虑哈希法了。
//判断sum是否重复出现就可以使用unordered_set
class Solution
{
public:
    int getSum(int n ) //计算每位上的平方和
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
            
            if (set.find(sum) != set.end()) //如果sum曾出现过，说明出现循环则返回false
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
