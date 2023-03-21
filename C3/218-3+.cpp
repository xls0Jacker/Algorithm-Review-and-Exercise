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

int dp[2][WMAX];// 从 0 到 i 这 i + 1 个物品中选出价值最大的

// 优化：
/*
  dp[i] 计算时只需要 dp[i + 1]，可以通过位运算 & 优化内存
*/
void solve(){
  // 为什么 i 从 0 开始？
  // 因为第 0 个物品的价值和为 0（还没开始选），符合 dp 数组的初始状态
  rep(0, i, n) {
    Rep(0, j, W) {
      if(j < w[i]) {
        dp[(i + 1) & 1][j] = dp[i & 1][j];
      } else {
        dp[(i + 1) & 1][j] = max(dp[i & 1][j], dp[i & 1][j - w[i]] + v[i]);
      }
    }
  }
  cout << dp[n & 1][W] << endl;
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