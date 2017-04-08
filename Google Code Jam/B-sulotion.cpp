#include <bits/stdc++.h>
using namespace std;


struct Node{
    string s;
    int cnt;
};

int main()
{
//   freopen("in.txt","r",stdin);
   freopen("B-small-attempt1.in","r",stdin);
   freopen("B-small-attempt1-1.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int c=1;c<=t;c++){
        printf("Case #%d: ",c);
       string s;
       cin>>s;
//       cout<<s<<endl;
       int l=s.length();
       int a[l];
       for(int i=0;i<l;i++){
        a[i]=(s[i]-'0');
       }
       int flag=1;
       for(int i=0;i<l-1;i++){
        if(a[i+1]<a[i]) flag=-1;
       }
//       string ans;
//       if(flag==1){
//        ans=s;
//       }
       if(flag==-1){
        for(int i=1;i<l;i++){
         if(a[i]<a[i-1]){
            for(int j=i-1;j>=1;j--){
                if(a[j]-1>=a[j-1]){
                    a[j]--;
                    for(int k=j+1;k<l;k++)
                        a[k]=9;
                    flag=0;
                    break;
                }
                if(j==1&&a[0]>1){
                    flag=2;
                    break;
                }
            }
         }
        if(flag==0||flag==2) break;
        }
       }
       if(flag==-1&&a[0]>1){
        flag=2;
       }
       if(flag==-1){
        for(int i=1;i<l;i++)
            printf("9");
        printf("\n");
       }
       else if(flag==0){
           for(int i=0;i<l;i++)
            printf("%d",a[i]);
           printf("\n");
       }
       else if(flag==1){
        cout<<s<<endl;
       }
       else if(flag==2){
            printf("%d",a[0]-1);
         for(int i=1;i<l;i++)
            printf("9");
        printf("\n");
       }
//       cout<<"flag:"<<flag<<endl;
    }
//    cout<<"111111111111111110"<<endl;
    return 0;
}
