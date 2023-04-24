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
const int INF = 0x3f3f3f3f;

int n;

struct pos{
  ll x, y;
};

pos v[NMAX];

void solve(){
  ll sum = 0;
  ll ans = INF;
  Rep(1, i, n) {
    Rep(1, j, n) {
      sum += abs((v[i].x + v[i].y) - (v[j].x + v[j].y)) + abs((v[i].x - v[i].y) - (v[j].x - v[j].y));
    }
    ans = min(ans, sum);
    sum = 0;
  }
  cout << ans / 2 << endl;
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