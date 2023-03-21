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
const int NMAX = 1e3 + 5;
const int MMAX = 1e3 + 5;

int n, m;// 串 s 的长度 串 t 的长度
string s, t;// 串 s 串 t

int dp[NMAX][MMAX];// s 串和 t 串各走 i 和 j 步的最长子序列

void solve(){
  rep(0, i, n) {
    rep(0, j, m) {
      if(s[i] == t[j]) {
        dp[i + 1][j + 1] = max({dp[i][j + 1], dp[i + 1][j], dp[i][j] + 1});
      } else {
        dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
      }
    }
  }
  cout << dp[n][m] << endl;
}

int main(){
  frep;
  cin >> n >> m;
  cin >> s >> t;
  solve();
  frepC;
  sys;
  return 0;
}