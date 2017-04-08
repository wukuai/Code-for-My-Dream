#include <bits/stdc++.h>
using namespace std;
struct Node{
    string s;
    int cnt;
};
int main()
{
//   freopen("in.txt","r",stdin);
   freopen("A-large.in","r",stdin);
   freopen("A-large.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;c++){
        string s;
        cin>>s;
        int k;
        cin>>k;
        int l=s.length();
        int ans=0;
        for(int i=0;i<l;i++){
            if(s[i]=='-'){
                ans++;
                for(int j=i;j<i+k;j++){
                if(j>=l){
                    ans=-1;
                    break;
                }
                if(s[j]=='-') s[j]='+';
                else s[j]='-';
                }
                if(ans==-1) break;
            }
             if(ans==-1) break;
        }
         if(ans==-1)
            printf("Case #%d: IMPOSSIBLE\n",c,ans);
         else
            printf("Case #%d: %d\n",c,ans);
    }
    return 0;
}
