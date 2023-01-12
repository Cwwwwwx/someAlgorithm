#include <iostream>
#include <vector>
using namespace std;

//二分查找 704. 二分查找
//这道题目的前提是数组为有序数组，同时题目还强调数组中无重复元素
class Solution {
public:
   //这是对于左闭右闭区间[left, right]的情况
   //while (left <= right) 要使用 <= ，因为left == right是有意义的，所以使用 <=
   //if (nums[middle] > target) right 要赋值为 middle - 1，因为当前这个nums[middle]一定不是target，那么接下来要查找的左区间结束下标位置就是 middle - 1
   int search1(vector<int>& nums, int target) {
      int left = 0;
      int right = nums.size() - 1;
      while (left <= right)
      {
         int middle = (left + right) / 2;
         if (nums[middle] < target)
         {
            left = middle + 1;
         }else if(nums[middle] > target)
         {
            right = middle - 1;
         }else{
            return middle;
         }
      }
      return -1;
   }

   //这是对于区间为左闭右开[left, right)的情况
   //while (left < right)，这里使用 < ,因为left == right在区间[left, right)是没有意义的
   //if (nums[middle] > target) right 更新为 middle，因为当前nums[middle]不等于target，去左区间继续寻找，而寻找区间是左闭右开区间，所以right更新为middle，即：下一个查询区间不会去比较nums[middle]
   int search2(vector<int>& nums, int target) {
      int left = 0;
      int right = nums.size();
      while (left <= right)
      {
         int middle = (left + right) / 2;
         if (nums[middle] < target)
         {
            left = middle + 1;
         }else if(nums[middle] > target)
         {
            right = middle;
         }else{
            return middle;
         }
      }
      return -1;
   }   
};

int main(){
   Solution sol;
   vector<int> nums = {-1,0,3,5,9,12};
   cout << sol.search1(nums, 5);
 }