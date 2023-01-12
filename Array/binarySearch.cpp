#include <iostream>
#include <vector>
using namespace std;

//���ֲ��� 704. ���ֲ���
//�����Ŀ��ǰ��������Ϊ�������飬ͬʱ��Ŀ��ǿ�����������ظ�Ԫ��
class Solution {
public:
   //���Ƕ�������ұ�����[left, right]�����
   //while (left <= right) Ҫʹ�� <= ����Ϊleft == right��������ģ�����ʹ�� <=
   //if (nums[middle] > target) right Ҫ��ֵΪ middle - 1����Ϊ��ǰ���nums[middle]һ������target����ô������Ҫ���ҵ�����������±�λ�þ��� middle - 1
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

   //���Ƕ�������Ϊ����ҿ�[left, right)�����
   //while (left < right)������ʹ�� < ,��Ϊleft == right������[left, right)��û�������
   //if (nums[middle] > target) right ����Ϊ middle����Ϊ��ǰnums[middle]������target��ȥ���������Ѱ�ң���Ѱ������������ҿ����䣬����right����Ϊmiddle��������һ����ѯ���䲻��ȥ�Ƚ�nums[middle]
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