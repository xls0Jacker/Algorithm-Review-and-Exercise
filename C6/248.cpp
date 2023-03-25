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

int a, b, x, y;// 骰子初始值 (x1 - x3, x2 - x4)

// 返回值为 gcd(a, b)
int exgcd(int a, int b, int &x, int &y) {
  int d = a;
  if(b != 0) {
    d = exgcd(b, a % b, y, x);
    y -= (a / b) * x;
  } else {
    x = 1, y = 0;
  }
  return d;
}

void solve(){
  int gcd = exgcd(a, b, x, y);
  if(gcd != 1) {
    cout << "-1" << endl;
    return;
  }
  if(x > 0) {
    cout << x << " " << 0 << " " << 0 << " " << -y << endl;
  } else {
    cout << 0 << " " << y << " " << -x << " " << 0 << endl;
  }
}

int main(){
  frep;
  cin >> a >> b >> x >> y;
  solve();
  frepC;
  sys;
  return 0;
}