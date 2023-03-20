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

int N, K, M;// 总字数 每分钟能看多少 看了多少分钟

void solve(){
  cout << N - K * M << endl;
}

int main(){
  frep;
  cin >> N >> K >> M;
  solve();
  frepC;
  sys;
  return 0;
}