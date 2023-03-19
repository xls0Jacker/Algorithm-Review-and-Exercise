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
const int NMAX = 1e4 + 5;// 稍微大一点

int N, M;// 模块数目 模块的输出个数
string S[NMAX];// 模块输出
string s[NMAX];// 去重输出

typedef pair<int, string> P;

P Q[NMAX];

bool cmp(P a, P b) {
  return a.first > b.first;
}

void solve(){
  sort(s, s + N);
  // rep(0, i, N) {
  //   cout << S[i] << endl;
  // }
  // cout << endl;
  int Difnum = unique(s, s + N) - s;// 计算不同输出的数目
  // rep(0, i, Difnum) {
  //   cout << s[i] << endl;
  // }
  // cout << endl;
  rep(0, i, Difnum) {
    int num = 0;// 输出数目
    rep(0, j, N) {
      if(s[i] == S[j]) {
        num++;
      }
    }
    Q[i] = P(num, s[i]);
  }
  sort(Q, Q + Difnum, cmp);
  cout << Difnum << endl;
  rep(0, i, Difnum) {
    cout << Q[i].first << " " << Q[i].second << endl;
  }
}

int main(){
  frep;
  cin >> N >> M;
  cin.get();
  rep(0, i, N) {
    getline(cin, S[i]);
    s[i] = S[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}