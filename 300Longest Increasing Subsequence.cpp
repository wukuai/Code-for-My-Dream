//最长递增子序列
//if(nums[j]<nums[i]&&dp[j]+1>dp[i]) dp[i]=dp[j]+1;
//复杂度O(n*n),hwo to improve?
//https://leetcode.com/problems/longest-increasing-subsequence
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+5);
        for(int i=0;i<n;i++)
            dp[i]=1;
        for(int i=0;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(nums[j]<nums[i]&&dp[j]+1>dp[i])//关键点，dp[i]表示以i结尾的最长递增子序列的长度
                    dp[i]=dp[j]+1;
            }
        }    
        
        int ans=dp[0];
        for(int i=0;i<n;i++)
            ans=max(ans,dp[i]);
        return ans
        ;
    }
};
