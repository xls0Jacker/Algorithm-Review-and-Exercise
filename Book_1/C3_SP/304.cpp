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
const int NMAX = 355;// 稍微大一点

int N;// 层数
int t;// 数据组数
ll f[NMAX][NMAX];// 存放数值

ll dp[NMAX][NMAX];// 当位置到达 (i, j) 时的最大权值和

void solve(){
  // 转移方程
  rep(0, i, N) {
    rep(0, j, i + 1) {
      if(j > 0) {
        dp[i][j] += max(dp[i - 1][j], dp[i - 1][j - 1]) + f[i][j];
      } else {
        dp[i][j] += dp[i - 1][j] + f[i][j];
      }
    }
  }
  ll Ans = -1;
  rep(0, i, N) {
    Ans = max(Ans, dp[N - 1][i]);
  }
  cout << Ans << endl;
}

int main(){
  frep;
  while(cin >> N) {
    memset(f, 0, sizeof(f));
    memset(dp, 0, sizeof(dp));
    rep(0, i, N) {
      rep(0, j, i + 1) {
        cin >> f[i][j];
      }
    } 
    solve();
  }
  frepC;
  sys;
  return 0;
}