/*
给定一个非负整数数组和一个整数?m，你需要将这个数组分成?m?个非空的连续子数组。设计一个算法使得这?m?个子数组各自和的最大值最小。

注意:
数组长度?n?满足以下条件:

1 ≤ n ≤ 1000
1 ≤ m ≤ min(50, n)
示例:

输入:
nums = [7,2,5,10,8]
m = 2

输出:
18

解释:
一共有四种方法将nums分割为2个子数组。
其中最好的方式是将其分为[7,2,5] 和 [10,8]，
因为此时这两个子数组各自的和的最大值为18，在所有情况中最小。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/split-array-largest-sum
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/ 

class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        long long dp[1010][55];//前i个数字分成j组的和的最小值
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
