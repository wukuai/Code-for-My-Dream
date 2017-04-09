//¾ØÕó¿ìËÙÃÝÄ£°å£¨ÖØÔØÔËËã·û£©
struct Matrix{
  long long a[N][N];
  Matrix(){
    memset(a,0,sizeof(a));
  }
  void init(){
    for(int i=1;i<=n;++i)a[i][i]=1;
  }
  Matrix operator *(const Matrix &rhs)const{
     Matrix ret;
     for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        for(int k=1;k<=n;++k)
          ret.a[i][j]=(ret.a[i][j]+a[i][k]*rhs.a[k][j]%mod)%mod;
      return ret;
  }
  Matrix operator ^(LL mi)const{
    Matrix tmp=(*this),ret;
    ret.init();
    while(mi){
      if(mi&1)ret=ret*tmp;
      tmp=tmp*tmp;
      mi>>=1;
    }
    return ret;
  }
};

//Àý×Ó hihocoder #1504ÆïÊ¿ÓÎÀú
//http://hihocoder.com/problemset/problem/1504
#include<bits/stdc++.h>
typedef long long LL;
const int mod = 1000000007;
const int N = 65;
using namespace std;
int id[9][9],cnt;
int n = 64;
struct Matrix{
  LL a[N][N];
  Matrix(){
    memset(a,0,sizeof(a));
  }
  void init(){
    for(int i=1;i<=n;++i)a[i][i]=1;
  }
  Matrix operator *(const Matrix &rhs)const{
     Matrix ret;
     for(int i=1;i<=n;++i)
      for(int j=1;j<=n;++j)
        for(int k=1;k<=n;++k)
          ret.a[i][j]=(ret.a[i][j]+a[i][k]*rhs.a[k][j]%mod)%mod;
      return ret;
  }
  Matrix operator ^(LL mi)const{
    Matrix tmp=(*this),ret;
    ret.init();
    while(mi){
      if(mi&1)ret=ret*tmp;
      tmp=tmp*tmp;
      mi>>=1;
    }
    return ret;
  }
}X,A;
int dx[8]={-2,-2,-1, 1,-1,1, 2,2};
int dy[8]={-1, 1,-2,-2, 2,2,-1,1};
int main(){
   for(int i=1;i<=8;++i)
     for(int j=1;j<=8;++j)
        id[i][j]=++cnt;
   for(int i=1;i<=8;++i){
     for(int j=1;j<=8;++j){
       int u = id[i][j];
       for(int k=0;k<8;++k){
         int px=i+dx[k];
         int py=j+dy[k];
         if(px<1||px>8||py<1||py>8)continue;
         int v = id[px][py];
         X.a[u][v]=1;
       }
     }
   }
   int n,r,c;
   scanf("%d%d%d",&n,&r,&c);
   A.a[id[r][c]][1]=1;
   Matrix ret=(X^(n))*A;
   int ans = 0;
   for(int i=1;i<=64;++i){
       ans=(ans+ret.a[i][1])%mod;
   }
   printf("%d\n",ans);
   return 0;
}

