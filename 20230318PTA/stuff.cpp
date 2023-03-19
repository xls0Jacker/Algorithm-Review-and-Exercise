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

int f[] = {1, 3, 5, 2, 2, 7, 9, 5};

void solve(){
  sort(f, f + 8);
  rep(0, i, 8) {
    cout << f[i] << " ";
  }
  cout <<endl;
  cout << unique(f, f + 8) - f << endl;
  rep(0, i, 8) {
    cout << f[i] << " ";
  }
  cout <<endl;
}

int main(){
  frep;
  
  solve();
  frepC;
  sys;
  return 0;
}