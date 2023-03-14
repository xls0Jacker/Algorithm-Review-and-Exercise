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

int dp[MAXW];// 第 i 个物品的选重量小于 j 的物品
int w, v;// 第 i 个物品的重量 第 i 个物品的价值
int n, W;// 物品数目 物品重量
// 优化
/*
  空间优化: 去除数组 w[] 和 v[]
  时间优化: O(n^2) 转为 O(n)
  优化思路：
*/

/*
  状态转移方程
  if(j < w[i]){
    dp[i][j] = dp[i + 1][j];
  } else {
    dp[i][j] = max(dp[i + 1][j], dp[i + 1][j - w[i]] + v[i]);
  }
*/

/*
  更改后的状态转移方程

*/

void solve(){
  rep(0, i, n){
    cin >> w >> v;
    Per(w, j, W){
        dp[j] = max(dp[j], dp[j - w] + v);
    }
  }
  cout << dp[W] << endl;
}

int main(){
  frep;
  cin >> n >> W;
  solve();
  frepC;
  sys;
  return 0;
}