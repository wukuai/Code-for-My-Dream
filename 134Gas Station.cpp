//环形公路加油站问题
//if sum of gas < sum of cost ,return -1
//else 必有解
//从0到n遍历即可，if from 0 to i is impossible,then from j(0<j<i) to i is impossible too. 
//滴滴二面题目，我竟然想成了动态规划，too yong!想复杂了，好好刷题吧！
//https://leetcode.com/problems/gas-station
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum=0;
        int n=gas.size();
        for(int i=0;i<n;i++)
            sum+=(gas[i]-cost[i]);
        if(sum<0) return -1;
        sum=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(sum<0){
                sum=0;
                ans=i;
            }
            sum+=gas[i]-cost[i];
        }
        return ans;
    }
   
};
