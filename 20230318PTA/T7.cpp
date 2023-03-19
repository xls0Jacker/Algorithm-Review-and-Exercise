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
const int NMAX = 35;// 稍微大一点

int N, M;// 题目数量 当前做了几道
string S[NMAX];// 题目描述

void solve(){
  int counter = 0;// 需要做的题目位次
  string ans;// 答案
  rep(0, i, N) {
    // cout << S[i] << endl;
    if(S[i].find("qiandao") != string::npos or S[i].find("easy") != string::npos){
      // cout << S[i].find("qiandao") << " " << S[i].find("easy") << endl;
      continue;
    }
    counter++;
    if(counter > M) {
      ans = S[i];
    }
  }
  if(counter <= M) {
    cout << "Wo AK le" << endl;
  } else {
    cout << ans << endl;
  }
}

int main(){
  frep;
  cin >> N >> M;
  cin.get();
  rep(0, i, N) {
    getline(cin, S[i]);
  }
  solve();
  frepC;
  sys;
  return 0;
}