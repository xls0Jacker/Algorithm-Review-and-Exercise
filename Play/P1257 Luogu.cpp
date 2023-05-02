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
const int NMAX = 1e4 + 1;
const ll INF = 0x3f3f3f3f3f3f3f3f;

int n;

struct pos{
  double x, y;
};

pos P[NMAX];

double Len(pos a, pos b) {
  return sqrt(pow(a.x - b.x, 2) + pow(a.y - b.y, 2));
}

bool cmp(pos a, pos b) {
  if(a.x == b.x) {
    return a.y < b.y;
  } else {
    return a.x < b.x;
  }
}

void solve(){
  sort(P, P + n, cmp);
  double ans = INF;
  // ll count = 0;
  rep(0, i, n){
    rep(i + 1, j, n) {
      ans = min(ans, Len(P[i], P[j]));
    }
  }
  printf("%.4lf\n", ans);
}

int main(){
  frep;
  cin >> n;
  rep(0, i, n) {
    cin >> P[i].x >> P[i].y;
  }
  solve();
  frepC;
  sys;
  return 0;
}