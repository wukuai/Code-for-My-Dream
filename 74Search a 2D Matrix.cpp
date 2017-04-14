//有序二维数组查找
//从右上角开始查找
//发现一个坑，eg. if vector[0]==a number then if(vector[0]==NULL) 表达式为真
//https://leetcode.com/problems/search-a-2d-matrix
//优化？
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size()<=0) return false; //别忘了判断空数组
        bool ans=false;
        int i=0;
        int j=matrix[0].size()-1;
        while(i<matrix.size()&&j>=0){
            if(target==matrix[i][j]){
                ans=true;
                break;
            }
            if(target<matrix[i][j]){
                j--;
            }
            else{
                i++;
            }
        }
        return ans;
    }
};
