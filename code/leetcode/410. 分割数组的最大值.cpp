/*
����һ���Ǹ����������һ������?m������Ҫ���������ֳ�?m?���ǿյ����������顣���һ���㷨ʹ����?m?����������Ժ͵����ֵ��С��

ע��:
���鳤��?n?������������:

1 �� n �� 1000
1 �� m �� min(50, n)
ʾ��:

����:
nums = [7,2,5,10,8]
m = 2

���:
18

����:
һ�������ַ�����nums�ָ�Ϊ2�������顣
������õķ�ʽ�ǽ����Ϊ[7,2,5] �� [10,8]��
��Ϊ��ʱ��������������Եĺ͵����ֵΪ18���������������С��

��Դ�����ۣ�LeetCode��
���ӣ�https://leetcode-cn.com/problems/split-array-largest-sum
����Ȩ������������С���ҵת������ϵ�ٷ���Ȩ������ҵת����ע��������
*/ 

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long dp[1010][55];//ǰi�����ֳַ�j��ĺ͵���Сֵ
        long long sum[1010];
        memset(sum,0,sizeof(sum));
        memset(dp,1,sizeof(dp));
        for(long long i = 1; i <= nums.size(); i++) sum[i]=sum[i-1]+nums[i-1],dp[i][1]=sum[i];
        for(long long j = 2; j <= m; j++)
        {
            for(long long i = 1; i <= nums.size(); i++)
            {
                for(long long k = 1; k < i; k++)
                    dp[i][j] = min(dp[i][j],max(dp[k][j-1],sum[i]-sum[k]));
                cout << i << ' ' << j << ' ' << dp[i][j] << endl;
            }
        }
        return dp[nums.size()][m];
    }
};
