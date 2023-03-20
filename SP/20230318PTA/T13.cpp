#include"bits/stdc++.h"
using namespace std;
#define frep freopen("in.txt", "r", stdin)
#define frepC freopen("CON", "r", stdin)
#define sys system("pause")
#define rep(a, i, n) for (int i = a; i < n; i++)
#define Rep(a, i, n) for (int i = a; i <= n; i++)
#define per(a, i, n) for (int i = n; i > a; i--)
#define Per(a, i, n) for (int i = n; i >= a; i--)
typedef long long ll;
const int NMAX = 1e5 + 5;// 稍微大一点
const int MMAX = 1e5 + 5;// 稍微大一点

int N, M;// 剧情点 操作数
vector<int> v[NMAX];// 每个剧情点可去的剧情
int f[MMAX];// 指令
int c[MMAX];// 操作
int L[105];// 存档

void solve(){
  vector<int> ans;// 存档
  ans.clear();
  int pos = 1;// 当前剧情点的位置
  rep(0, i, M) {
    if(f[i] == 0) {
      pos = v[pos][c[i] - 1];// 更新位置
    } else if(f[i] == 1) {
      L[c[i] - 1] = pos;
      ans.push_back(pos);
    } else {
      pos = L[c[i] - 1];
    }
  }
  ans.push_back(pos);
  rep(0, i, ans.size()) {
    cout << ans[i] << endl;
  }
}

int main(){
  frep;
  cin >> N >> M;
  int K;// 选择数目
  Rep(1, i, N) {
    cin >> K;
    int temp;
    rep(0, j, K) {
      cin >> temp;
      v[i].push_back(temp);
    }
  }
  rep(0, i, M) {
    cin >> f[i] >> c[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}