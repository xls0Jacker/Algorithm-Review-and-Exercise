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
const int NMAX = 2 * 1e4 + 5;// 稍微大一点

int n;// 行数
int L[NMAX], R[NMAX];// 每一行线的左端点和右端点

int dp[NMAX][2];// 表示走完第 i 行，自己处于左 / 右端点

void solve(){
  // 初始状态
  dp[1][0] = (R[1] - 1) + 1 + (R[1] - L[1]);
  dp[1][1] = (R[1] - 1) + 1;
  // 转移方程
  Rep(2, i, n) {
    dp[i][0] = min(dp[i - 1][0] + abs(L[i - 1] - R[i]) + R[i] - L[i] + 1,
                  dp[i - 1][1] + abs(R[i - 1] - R[i]) + R[i] - L[i] + 1);
    dp[i][1] = min(dp[i - 1][0] + abs(L[i - 1] - L[i]) + R[i] - L[i] + 1,
                  dp[i - 1][1] + abs(R[i - 1] - L[i]) + R[i] - L[i] + 1);
  }
  int Ans = min(n - L[n] + dp[n][0] - 1, n - R[n] + dp[n][1] - 1);
  cout << Ans << endl;
} 

int main(){
  frep;
  cin >> n;
  Rep(1, i, n) {
    cin >> L[i] >> R[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}