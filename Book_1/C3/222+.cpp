#include"bits/stdc++.h"
using namespace std;
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;
const int NMAX = 105;// 稍微大一点
const int KMAX = 1e5 + 5;// 稍微大一点

int n, K;// 数字数目 数字和
int a[NMAX];// 数字数值
int m[NMAX];// 数字个数

int dp[KMAX];// 从 0 到 i 这 (i + 1) 个数选出若干数达到数值和 j 时第 i 种数的最大剩余值 

void solve(){
  memset(dp, -1, sizeof(dp));
  dp[0] = 0;
  rep(0, i, n) {
    Rep(0, j, K) {
      if(dp[j] >= 0) {// 上一步已经能够达成该数值
        dp[j] = m[i];
      } else if (j < a[i] or dp[j - a[i]] <= 0) {// 凑不出 K（加了超或加了不够）
        dp[j] = -1;
      } else {
        dp[j] = dp[j - a[i]] - 1;
      }
    }
  }
  if(dp[K] >= 0) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main(){
  frep;
  cin >> n >> K;
  rep(0, i, n) {
    cin >> a[i];
  }
  rep(0, i, n) {
    cin >> m[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}