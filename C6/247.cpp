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

int x_1, x_2, y_1, y_2;// 两个点的坐标

int gcd(int a, int b) {
  if(b == 0) return a;
  return gcd(b, a % b);
}

void solve(){
  if(x_1 == x_2 and y_1 == y_2) {
    cout << 0 << endl;
    return;
  }
  cout << gcd(abs(x_1 - x_2), abs(y_1 - y_2)) - 1 << endl;
}

int main(){
  frep;
  cin >> x_1 >> y_1 >> x_2 >> y_2;
  solve();
  frepC;
  sys;
  return 0;
}