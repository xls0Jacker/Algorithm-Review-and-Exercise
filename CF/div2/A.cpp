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

int t;
string s;

void solve(){
  int cun = 1;
  if(s[0] == '0') {
    cout << 0 << endl;
  } else if(s.find('?') != string::npos) {
    if(s[0] == '?') {
      cun *= 9;
    }
    Rep(1, i, s.size()) {
      if(s[i] == '?') {
        cun *= 10;
      }
    }
    cout << cun << endl;
  } else {
    cout << cun << endl;
  }
}

int main(){
  frep;
  cin >> t;
  while(t--) {
    cin >> s;
    solve();
  }
  frepC;
  sys;
  return 0;
}