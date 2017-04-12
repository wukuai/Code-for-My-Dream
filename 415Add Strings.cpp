//模拟大数相加
//注意reverse函数的使用 eg. reverse(s.begin(),s.end())
//先判断进位，再相加
//https://leetcode.com/problems/add-strings
class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1=num1.length();
        int n2=num2.length();
        reverse(num1.begin(),num1.end());
        reverse(num2.begin(),num2.end());
        string sum="";
        if(n1<n2){
            for(int i=0;i<n2-n1;i++)
                num1=num1+"0";
        }
        else if(n2<n1){
            for(int i=0;i<n1-n2;i++)
                num2=num2+"0";
        }
        int nmax=max(n1,n2);
        for(int i=0;i<=nmax;i++){
            sum+="0";
        }
        for(int i=0;i<nmax;i++){
                 sum[i+1]=((num1[i]-'0')+(num2[i]-'0')+(sum[i]-'0'))/10+'0';
                 sum[i]=((num1[i]-'0')+(num2[i]-'0')+(sum[i]-'0'))%10+'0';//这两条语句不能反！because sum[i]要用两次，不可使用更改后的值
                
        }
        reverse(sum.begin(),sum.end());
        if(sum[0]!='0')
            return sum;
        else{
            return sum.substr(1,nmax);
        }
    }
};
