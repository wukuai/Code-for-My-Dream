//最大连续子序列的和
//当前面和为负数的时候，后面的元素就不需要前面的元素了
//记得考虑输入只有一个值且为负数的时候
//复杂度O(n)，但是时间不够少，怎么优化？
//https://leetcode.com/problems/maximum-subarray
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n=nums.size();
        int ans=nums[0];//不要初始化为0，考虑当只有一个输入值且为负数的时候
        int sum=0;
        for(int i=0;i<n;i++){
            if(sum<0) sum=0;//如果前面为负，肯定就不需要了
            sum=sum+nums[i];
            ans=max(sum,ans);
        }
        return ans;
    }
};
