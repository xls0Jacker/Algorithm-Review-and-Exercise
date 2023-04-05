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
const int KMAX = 1e5 + 5;// 稍微大一点

int n, K;// 数字数目 数字和
int a[NMAX];// 数字数值
int m[NMAX];// 数字个数

bool dp[2][KMAX];// 能否从 0 到 i 这 (i + 1) 个数选出若干个数计算出数值和为 K

void solve(){
  dp[0][0] = true;
  rep(0, i, n) {
    Rep(0, j, K) {
      Rep(0, k, m[i]) {
        dp[(i + 1) & 1][j] |= dp[i & 1][j - k * a[i]];
      }
    }
  }
  if(dp[n & 1][K]) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main(){
  frep;
  cin >> n >> K;
  rep(0, i, n) {
    cin >> a[i];
  }
  rep(0, i, n) {
    cin >> m[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}