#include <iostream>
#include <vector>
using namespace std;
/*给定一个字符串 s 和一个整数 k，从字符串开头算起, 每计数至 2k 个字符，就反转这 2k 个字符中的前 k 个字符。

如果剩余字符少于 k 个，则将剩余字符全部反转。

如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
541. 反转字符串
*/

//这道题思考了很久，剩余字符指的是最后size - 2nk的部分，其余部分直接翻转前k个字符就可以了

class Solution {
public:
    string reverseStr(string s, int k) {
        for (int i = 0; i < s.size() ;i += 2*k)
        {
            if (i + k <= s.size()){ //这里判断条件是为了不让数组越界，同时也可以理解位剩余字符和k的关系
            reverse(s.begin() + i, s.begin() + i + k)
            }else{
                reverse(s.begin() + i, s.end());
            }
        }
        return s;
    }
};