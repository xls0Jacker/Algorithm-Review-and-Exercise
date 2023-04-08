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
const int NMAX = 1e4 + 5;// 稍微大一点
const int MMAX = 1005;// 稍微大一点
const int KMAX = 1e4 + 5;// 稍微大一点
const int INF = 1e9 + 7;

int n, m, k;// 地图长度 最高高度 障碍物的数目
int x[NMAX], y[NMAX];// 点击和不点击的位移距离
int p[KMAX], l[KMAX], r[KMAX];// 每个水管的位置 最高高度 最低高度

int dp[2][MMAX];// 表示到达 i 位置，自身高度为 j 且经过 l 个水管的最小点击次数

void solve(){
  // 初始化
    明天记得加上条条框框
  // 状态转移
  rep(0, i, n) {
    Rep(0, j, m) {
      for (int l = 0; j + l * x[i] <= m; l++) {
        if(l != 0) {
          dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j + l * x[i]] + l);
        } else {
          dp[(i + 1) & 1][j] = dp[i & 1][j - y[i]];
        }
      }
    }
  }
  cout << *max_element(dp[n & 1], dp[n & 1] + m) << endl;
} 

int main(){
  frep;
  cin >> n >> m >> k;
  rep(0, i, n) {
    cin >> x[i] >> y[i];
  }
  rep(0, i, k) {
    cin >> p[i] >> l[i] >> r[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}