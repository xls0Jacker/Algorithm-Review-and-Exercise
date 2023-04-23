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
const int INF = 1e9 + 7;

int t;
int n;
vector<int> A;
vector<int> B;

vector<int> ANSL;
vector<int> ANSR;
vector<int> Len;

void solve(){
  ANSL.clear();
  ANSR.clear();
  Len.clear();
  int L = 0, R = 1;
  rep(0, i, n) {
    rep(i + 1, j, n) {
      vector<int> C;
      C = A;
      sort(C.begin() + i, C.begin() + j + 1);
      bool f = false;
      Rep(i, k, j) {
        if(C[k] != B[k]) {
          f = true;
          break;
        }
      }
      if(!f) {
        if(j - i >= R - L) {
          ANSL.push_back(i);
          ANSR.push_back(j);
          Len.push_back(j - i);
          L = i;
          R = j;
        }
      }
    }
  }
  int maxLen = Len[Len.size() - 1];
  Rep(0, i, ANSL.size()) {
    if(ANSR[i] - ANSL[i] == maxLen) {
      cout << ANSL[i] + 1 << " " << ANSR[i] + 1 << endl;
    }
  }
}

int main(){
  frep;
  cin >> t;
  while(t--) {
    cin >> n;
    int temp;
    A.clear();
    B.clear();
    rep(0, i, n) {
      cin >> temp;
      A.push_back(temp);
    }
    rep(0, i, n) {
      cin >> temp;
      B.push_back(temp);
    }
    solve();
  }
  frepC;
  sys;
  return 0;
}