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
const int WMAX = 1005;// 稍微大一点

string Ts, Te;// 起始时间 结束时间
int n;// 种类数
int P[NMAX];// 每一种的数目 // 特别地 当数值为 0 时表示为 INF
int C[NMAX];// 每一种的价值
int T[NMAX];// 每一种的容量

int dp[2][WMAX];// 表示从 0 ~ i 这（i + 1）个数中选出重量为 j 的最大价值

void solve(){
  // 预处理
  int pos_1 = Ts.find(':');
  int pos_2 = Te.find(':');
  int T1 = stoi(Ts.substr(0, pos_1)) * 60 + stoi(Ts.substr(pos_1 + 1));
  int T2 = stoi(Te.substr(0, pos_2)) * 60 + stoi(Te.substr(pos_2 + 1));
  int W = T2 - T1;
  // 状态转移
  rep(0, i, n) {
    Rep(T[i], j, W) {
      int pMAX;
      if(P[i] == 0) {
        if(C[i] == 0) {
          continue;
        }
        pMAX = ceil(W / T[i]);
      } else {
        pMAX = P[i];
      }
      for (int k = 0; k * T[i] <= j && k <= pMAX; k++) {
        dp[(i + 1) & 1][j] = max(dp[(i + 1) & 1][j], dp[i & 1][j - k * T[i]] + k * C[i]);
      }
    }
  }
  cout << dp[n & 1][W] << endl;
}

int main(){
  frep;
  cin >> Ts >> Te >> n;
  rep(0, i, n) {
    cin >> T[i] >> C[i] >> P[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}