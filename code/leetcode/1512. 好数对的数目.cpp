/*

����һ���������� nums ��

���һ������ (i,j) ���� nums[i] == nums[j] �� i < j ���Ϳ�����Ϊ����һ�� ������ ��

���غ����Ե���Ŀ��

?

ʾ�� 1��

���룺nums = [1,2,3,1,1,3]
�����4
���ͣ��� 4 ������ԣ��ֱ��� (0,3), (0,4), (3,4), (2,5) ���±�� 0 ��ʼ
ʾ�� 2��

���룺nums = [1,1,1,1]
�����6
���ͣ������е�ÿ�����ֶ��Ǻ�����
ʾ�� 3��

���룺nums = [1,2,3]
�����0
?

��ʾ��

1 <= nums.length <= 100
1 <= nums[i] <= 100

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/number-of-good-pairs
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������

*/

class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int count[110];
        memset(count,0,sizeof(count));
        for(int i:nums)
        {
            count[i]++;
        }
        int ans = 0;
        for(int i = 1; i <= 100; i++)
        {
            //1+2+3+...+n-1
            ans+=count[i]*(count[i]-1)/2;
        }
        return ans;
    }
}; 
