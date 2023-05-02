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
const int NMAX = 4e5 + 1;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n;

struct pos{
  ll x, y;
};

pos v[NMAX];

bool cmp(pos a, pos b) {
  if(a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

ll LLen(pos a, pos b) {
  return pow(a.x - b.x, 2) + pow(a.y - b.y, 2);
}

void solve(){
  sort(v + 1, v + n + 1, cmp);
  ll ans = -INF;
  int k = 0;
  if(n == 2) {
    cout << LLen(v[1], v[2]) << endl;
    return;
  }
  Rep(1, i, n) {
    Per(1, j, n) {
      if(i == j) {
        break;
      }
      k++;
      if(k > 12000) {
        return;
      }
      ans = max(ans, LLen(v[i], v[j]));
    }
  }
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