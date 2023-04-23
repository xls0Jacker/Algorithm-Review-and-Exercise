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

int dp[2][MAXW];// 第 i 个物品的选重量小于 j 的物品
int w[MAXW], v[MAXN];// 第 i 个物品的重量 第 i 个物品的价值
int n, W;// 物品数目 物品重量
/*
  方案二
  状态转移方程
  int dp[MAXN][MAXW];// 表示前 i 个物品的选总重量小于 j 的物品
  if (j < w[i]){
    dp[i + 1][j] = dp[i][j];
  } else {
    dp[i + 1][j] = max(dp[i][j], dp[i][j - w[i]] + v[i]);
  }
*/

void solve(){
  rep(0, i, n){
    Rep(0, j, W){
      if (j < w[i]){
        dp[(i + 1) & 1][j] = dp[i & 1][j];
      } else {
        dp[(i + 1) & 1][j] = max(dp[i & 1][j], dp[i & 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[n & 1][W] << endl;
}

int main(){
  frep;
  cin >> n >> W;
  rep(0, i, n) {
    cin >> w[i] >> v[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}