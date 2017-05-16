//循环数组，找出右边第一个比它大的数
//https://leetcode.com/problems/next-greater-element-ii
//用栈，来两遍，
//关键点：push进栈的是数组下标（便于找到在结果数组中的位置），so 比较的时候也不要忘了用下标
class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,-1);
        stack<int>s;
        for(int i=0;i<2*n;i++){
            while((!s.empty()&&nums[i%n]>nums[s.top()])){//nums[s.top()]
                ans[s.top()]=nums[i%n];
                s.pop();
            }
            if(i<n) s.push(i%n);
        }
        return ans;
    }
};
