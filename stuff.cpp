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

void solve(){
  int l = 0, r = 1e9 + 1;
  int n;
  while(l <= r) {
    int mid = (l + r) / 2;
    cout << mid << endl;
    cin >> n;
    if(n == 0) {
      return;
    } else if(n == 1){
      r = mid + 1;
    } else if(n == -1) {
      l = mid;
    } else {
      return;
    }
  }
}

int main(){
  frep;
  solve();
  frepC;
  sys;
  return 0;
}