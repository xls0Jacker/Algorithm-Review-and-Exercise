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
const int MAXN = 105;
const int MAXW = 1005;

int dp[MAXN][MAXW];
int w[MAXW], v[MAXN];// 第 i 个物品的重量 第 i 个物品的价值
int n, W;// 物品数目 物品重量
/*
  方案一
  int dp[MAXN][MAXW];// 表示从第 i 个物品之后的物品中选总重量小于 j 的物品
  状态转移方程
  if(j < w[i]){
    dp[i][j] = dp[i + 1][j];
  } else {
    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
  }
*/

void solve(){
  Per(0, i, n - 1){
    Rep(0, j, W){
      if (j < w[i]){
        dp[i][j] = dp[i + 1][j];
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[0][W] << endl;
}

int main(){
  // frep;
  cin >> n >> W;
  rep(0, i, n) {
    cin >> w[i] >> v[i];
  }
  solve();
  // frepC;
  // sys;
  return 0;
}