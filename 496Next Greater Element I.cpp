class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        //[2,1,3,4,5,6]
        int n=nums.size();
        stack<int>s;
        map<int,int>m;
        for(int i=0;i<n;i++){
             cout<<n<<" test"<<endl;
            if(!s.empty()&&nums[i]>s.top()){ //top()   !!!!!
                while((!s.empty())&&nums[i]>s.top()){//!运算顺序？  pop之前就要想到判空
                    m[s.top()]=nums[i];
                    s.pop();
                }
            }
            s.push(nums[i]);
        }
        while(!s.empty()){
            m[s.top()]=-1;
            s.pop();
        }
      
        vector<int>ans;
        for(int i=0;i<findNums.size();i++){//?size()会执行多少次
            ans.push_back(m[findNums[i]]);//push_back not push!
        }
        return ans;
    }
};
