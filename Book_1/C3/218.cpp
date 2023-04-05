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
const int WMAX = 10005;// 稍微大一点

int n, W;// 物品数量 背包容量
int w[NMAX], v[NMAX];// 物品重量 物品价值

int dp[NMAX][WMAX];// 对重量为 j 时对第 i 个物品选或者不选 价值和

void solve(){
  // 为什么 i 从 n 开始？
  // 因为第 n 个物品的价值和为 0（不存在第 n 个物品），符合 dp 数组的初始状态
  Per(0, i, n - 1) {
    Rep(0, j, W) {
      if(j < w[i]) {
        dp[i][j] = dp[i + 1][j];
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[0][W] << endl;
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