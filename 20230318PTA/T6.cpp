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

int f[24];// 不同时间的心情
vector<int> v;// 网友询问的时间点

void solve(){
  rep(0, i, v.size()) {
    if(f[v[i]] > 50) {
      cout << f[v[i]];
      cout << " Yes" << endl;
    } else {
      cout << f[v[i]];
      cout << " No" << endl;
    }
  }
}

int main(){
  frep;
  rep(0, i, 24) {
    cin >> f[i];
  }
  int temp;
  while(cin >> temp and temp >= 0 and  temp < 24) {
    v.push_back(temp);
  }
  solve();
  frepC;
  sys;
  return 0;
}