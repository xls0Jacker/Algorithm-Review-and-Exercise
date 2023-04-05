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
const int MMAX = 105;// 稍微大一点
const int mod = 1e6 + 7;

int n, m;// 盆栽的种类 盆栽总数
int a[NMAX];// 每种盆栽的数目

int dp[NMAX][MMAX];// 表示从 1 ~ i 这 i 种盆栽中筛选过程中使总和为 j 的可行方案数

void solve(){
  // 初始状态
  dp[0][0] = 1;
  // 转移方程
  Rep(1, i, n) {
    Rep(0, j, m) {
      Rep(0, k, min(j, a[i])) {
        dp[i][j] += dp[i - 1][j - k];
        dp[i][j] %= mod;
      }
    }
  }
  cout << dp[n][m] << endl;
}

int main(){
  frep;
  cin >> n >> m;
  Rep(1, i, n) {
    cin >> a[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}