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
const int NMAX = 1e5 + 1;
const int INF = 1e9 + 7;

int n;

struct pos{
  int x, y;
};

pos v[NMAX];

void solve(){
  int ans = -INF;
  int maxxy = -INF;
  int maxx_y = -INF;
  int minxy = INF;
  int minx_y = INF;
  Rep(1, i, n) {
    maxxy = max(maxxy, v[i].x + v[i].y);
  }
  Rep(1, i, n) {
    maxx_y = max(maxx_y, v[i].x - v[i].y);
  }
  Rep(1, i, n) {
    minxy = min(minxy, v[i].x + v[i].y);
  }
  Rep(1, i, n) {
    minx_y = min(minx_y, v[i].x - v[i].y);
  }
  ans = max(abs(maxxy - minxy), abs(maxx_y - minx_y));
  cout << ans << endl;
}

int main(){
  frep;
  cin >> n;
  Rep(1, i, n) {
    cin >> v[i].x >> v[i].y;
  }
  solve();
  frepC;
  sys;
  return 0;
}