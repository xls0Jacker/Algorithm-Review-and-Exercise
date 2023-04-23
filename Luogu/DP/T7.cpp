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
int p[KMAX], L[KMAX], R[KMAX];// 每个水管的位置 最高高度 最低高度

int dp[2][MMAX];// 表示到达 i 位置，自身高度为 j 且经过 l 个水管的最小点击次数

struct pipe{// 给水管排序用（因为输入的位置不是有序的）
  int pos, low, high;
}P[KMAX];

bool cmp(pipe a, pipe b) {
  return a.pos < b.pos;
}

void solve(){
  // 初始化
  Rep(1, i, k) {
    P[i].pos = p[i];
    P[i].low = L[i];
    P[i].high = R[i];
  }
  sort(P + 1, P + k + 1, cmp);
  int Npos = 1;// 最近未接触的水管位次
  // 状态转移
  Rep(1, i, n) {
    Rep(0, l, m) {
      dp[i & 1][l] = INF;
    }
    // 完全背包（点击）
    for (int l = x[i] + 1; l <= m + x[i]; l++) {// m + x[i] 是为了使其能够登顶
      dp[i & 1][l] = min(dp[(i - 1) & 1][l - x[i]] + 1, dp[i & 1][l - x[i]] + 1);
    }
    for (int l = m + 1; l <= m + x[i]; l++) {
      dp[i & 1][m] = min(dp[i & 1][m], dp[i & 1][l]);// 可能 RE
    }
    // 01 背包（不点）
    for (int l = 1; l <= m - y[i]; l++) {
      dp[i & 1][l] = min(dp[(i - 1) & 1][l + y[i]], dp[i & 1][l]);
    }
    int Ans = INF;
    if(i == P[Npos].pos) {// 当前位置为管道
      Rep(0, l, P[Npos].low) {
        dp[i & 1][l] = INF;
      }
      Rep(P[Npos].high, l, m) {
        dp[i & 1][l] = INF;
      }
      Rep(1, l, m) {
        Ans = min(dp[i & 1][l], Ans);
      }
      if(Ans == INF) {
        cout << 0 << endl;
        cout << Npos - 1 << endl;
        return;
      }
      Npos++;
    }
  }
  cout << 1 << endl;
  cout << *min_element(dp[n & 1] + 1, dp[n & 1] + m + 1) << endl;
} 

int main(){
  frep;
  cin >> n >> m >> k;
  Rep(1, i, n) {
    cin >> x[i] >> y[i];
  }
  Rep(1, i, k) {
    cin >> p[i] >> L[i] >> R[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}

// // // // ?