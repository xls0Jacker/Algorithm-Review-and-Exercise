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
const int NMAX = 3005;// 稍微大一点
const int MMAX = 3005;// 稍微大一点
const int INF = 1e9 + 7;

typedef pair<char, char> P;

string DNA_A, DNA_B;// 小 A 的 DNA 序列；小 B 的 DNA 序列
map<P, int> mp;// 16 种情况下的权值
int A, B;// 公式系数

const string s = "ATGC";// 计算权值用
int dp[NMAX][MMAX][3];// 表示小 A 已经使用了 i 个字母， 小 B 已经使用了 j 个字母时两者
  // 结尾的“均为字母” “小 A 为空格，小 B 为字母” “小 A 为字母，小 B 为空格”三种情况之一下的最大权值

void solve(){
  // 初始化
  int n = DNA_A.length();
  int m = DNA_B.length();
    // 以下过程中不存在的设为 -INF
  Rep(1, i, n) {
    dp[i][0][0] = -INF;
    dp[i][0][1] = -A - B * (i - 1);
    dp[i][0][2] = -INF;
    dp[0][i][0] = -INF;
    dp[0][i][1] = -INF;
    dp[0][i][2] = -A - B * (i - 1);
  }
  dp[0][0][1] = -INF;
  dp[0][0][2] = -INF;
  // 状态转移
  Rep(1, i, n) {
    Rep(1, j, m) {
      // 两者结尾均为字母
      dp[i][j][0] = max({dp[i - 1][j - 1][0], dp[i - 1][j - 1][1], dp[i - 1][j - 1][2]}) + mp[P(DNA_A[i - 1], DNA_B[j - 1])];
      // 小 A 结尾是空格 小 B 是字母
      dp[i][j][1] = max({dp[i][j - 1][1] - B, dp[i][j - 1][0] - A, dp[i][j - 1][2] - A});
      // 小 A 结尾是字母 小 B 是空格
      dp[i][j][2] = max({dp[i - 1][j][2] - B, dp[i - 1][j][0] - A, dp[i - 1][j][1] - A});
    }
  }
  cout << max({dp[n][m][0], dp[n][m][1], dp[n][m][2]}) << endl;
}

int main(){
  frep;
  cin >> DNA_A >> DNA_B;
  rep(0, i, 4) {
    rep(0, j, 4) {
      cin >> mp[P(s[i], s[j])];
    }
  }
  cin >> A >> B;
  solve();
  frepC;
  sys;
  return 0;
}