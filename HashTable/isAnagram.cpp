#include <iostream>
using namespace std;
//242.有效的字母异位词
class Solution {
public:
    bool isAnagram(string s, string t) {
        int record[26] = {0};
        for (int i = 0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }

        for (int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a']--;
        }

        for (int i = 0; i < 26; i++)
        {
            if (record[i] != 0)
            {
                return false;
            }
        }
        return true;
    }
};

int main ()
{
    Solution sol;
    string A = "abi";
    string B = "bac";
    if (sol.isAnagram(A, B))
    {
        cout << "True";
    }else{
        cout << "False";
    }

}