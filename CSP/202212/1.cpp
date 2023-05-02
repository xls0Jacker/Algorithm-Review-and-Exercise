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
const int NMAX = 55;

int n;
double I;
double f[NMAX];

void solve(){
  double sum = 0;
  Rep(0, i, n) {
    if(f[i] > 0) {
      sum += f[i] * pow(1 + I, -i);
    } else {
      sum += f[i] * pow(1 + I, -i);
    }
  }
  cout << sum << endl;
}

int main(){
  frep;
  cin >> n >> I;
  Rep(0, i, n) {
    cin >> f[i];
  }
  solve();
  frepC;
  sys;
  return 0;
}