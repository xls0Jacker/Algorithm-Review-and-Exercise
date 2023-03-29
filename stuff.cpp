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

int f[] = {1, 2, 3};

void solve(){
  rep(0, i, 3) {
    cout << f[i] << " ";
  }
  cout << endl;
  while(next_permutation(f, f + 3)) {
    rep(0, i, 3) {
      cout << f[i] << " ";
    }
    cout << endl;
  }
}

int main(){
  frep;
  
  solve();
  frepC;
  sys;
  return 0;
}