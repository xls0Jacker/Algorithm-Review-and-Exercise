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
const int MMAX = 1e3 + 5;// 稍微大一点
const int SMAX = 1e8 + 5;// 稍微大一点
const int TMAX = 3 * 1e5 + 5;// 稍微大一点

int M, S, T;// 魔法初始值 道路距离 沉没时间

int dp[2][MMAX];// 第 i 秒时且魔法剩余 j 时能走的最远距离

const int cost = 10;// 魔法消耗值
const int pace_1 = 17;// 常规速度走的距离
const int pace_2 = 60;// 魔法走的距离
const int resume = 4;// 不动时的魔法回复

int shortest_time = -1;// 花费的最短时间
int longest_path = -1;// 行走的最长距离

void solve(){
  vector<int> Ans;// 用于存储已经大于 S 的时间值和距离
  Ans.clear();
  rep(0, i, T) {
    Rep(0, j, M) {
      if(j < 10) {
        dp[(i + 1) & 1][j] = max(dp[i & 1][j] + pace_1, dp[i & 1][j + resume]);
      } else {
        // dp[(i + 1) & 1][j] = max({dp[i & 1][j] + pace_1, dp[i & 1][j - cost] + pace_2, dp[i & 1][j + resume]});
        dp[(i + 1) & 1][j] = dp[i & 1][j - cost] + pace_2;
      }
      longest_path = max(longest_path, dp[(i + 1) & 1][j]);
      if(dp[(i + 1) & 1][j] >= S) {
        Ans.push_back(i + 1);
      }
    }
  }
  if(Ans.size() > 0) {
    sort(Ans.begin(), Ans.end());
    shortest_time = Ans[0];    
  }

  if(Ans.size() > 0) {
    cout << "Yes" << endl;
    cout << shortest_time << endl;
  } else {
    cout << "No" << endl;
    cout << longest_path << endl;
  }
}

int main(){
  frep;
  cin >> M >> S >> T;
  solve();
  frepC;
  sys;
  return 0;
}