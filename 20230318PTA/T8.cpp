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
const int NMAX = 2 * 1e4 + 5;// 稍微大一点

int N;// 学生的总人数
int f[NMAX];// 学生的能力值

void solve(){
  sort(f, f + N);
  int MinNum = f[0];// 最小数值
  int MaxNum = f[N - 1];// 最大数值
  int MinP = 0;// 最少人数
  int MaxP = 0;// 最大人数
  rep(0, i, N) {
    if(f[i] == MinNum) {
      MinP++;
    } else {
      break;
    }
  }
  Per(0, i, N - 1) {
    if(f[i] == MaxNum) {
      MaxP++;
    } else {
      break;
    }
  }
  cout << MinNum << " " << MinP << endl;
  cout << MaxNum << " " << MaxP << endl;
}

int main(){
  frep;
  cin >> N;
  rep(0, i, N) {
    cin >> f[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}