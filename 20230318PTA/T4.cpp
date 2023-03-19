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
const int NMAX = 105;// 稍微大一点

int N, M;// 价格纪录的数目 预定价格
float f[NMAX];// 价格

void solve(){
  rep(0, i, N) {
    if(f[i] < M){
      cout << "On Sale! ";
      printf("%.1f", f[i]);
      cout << endl;
    }
  }
}

int main(){
  frep;
  cin >> N >> M;
  rep(0, i, N) {
    cin >> f[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}