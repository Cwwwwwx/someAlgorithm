#include <iostream>
#include <vector>
using namespace std;
//59.螺旋矩阵II 
// 填充上行从左到右
// 填充右列从上到下
// 填充下行从右到左
// 填充左列从下到上
// 坚持循环不变量原则
class Solution
{
public:
    vector<vector<int>> generateMatrix(int n)
    {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int startx = 0;
        int starty = 0;
        int loop = n / 2;
        int mid = n / 2;
        int offset = 1;
        int count = 1;
        int i, j;
        while(loop--)
        {
            i = startx;
            j = starty;

            for (j = starty; j < n - offset; j++)
            {
                res[i][j] =  count++;
            }

            for (i = startx; i < n - offset; i++)
            {
                res[i][j] = count++;
            }

            for (; j > starty; j--)
            {
                res[i][j] = count++;
            }

            for (; i > startx; i--)
            {
                res[i][j] = count++;                
            }

            startx++;
            starty++;
            offset += 1;
        } 
        if ((n % 2) == 1)
        {
            res[mid][mid] = n*n;
        }
        return res;
    }
};

int main ()
{
    Solution sol;
    int n = 4;
    vector<vector<int>> array(sol.generateMatrix(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n ; j++)
        cout << array[i][j] << " ";
        cout << endl;
    }
}