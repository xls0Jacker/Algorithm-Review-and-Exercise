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
const int WMAX = 1e9 + 5;// 稍微大一点
const int VMAX = 105;// 稍微大一点
const int NMAX = 105;// 稍微大一点
const int INF = 1e9 + 7;

int n, W;// 物品数量 背包容量
int w, v;// 物品重量 物品价值

int dp[NMAX][VMAX * NMAX];// 从 0 到 i 这 i + 1 个物品中选出总价值为 j 时的最小重量
// 最后找出符合条件的重量下的最大价值

void solve(){
  // 初始条件
  fill(dp[0], dp[0] + NMAX * VMAX, INF);// 选 0 个物品价值为一大于 0 的值不存在，找最小 故设置为无穷
  dp[0][0] = 0;
  rep(0 ,i ,n) {
    cin >> w >> v;
    Rep(0, j, VMAX * NMAX) {
      if(j < v) {
        dp[i + 1][j] = dp[i][j];
      } else {
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v] + w);
      }
    }
  }
  int Ans = 0;// 符合条件的最大价值 
  Rep(0, i, NMAX * VMAX) {
    if(dp[n][i] <= W and i <= 10000) {
      Ans = i;
    }
  }
  cout << Ans << endl;
}

int main(){
  frep;
  cin >> n >> W;
  solve();
  frepC;
  sys;
  return 0;
}