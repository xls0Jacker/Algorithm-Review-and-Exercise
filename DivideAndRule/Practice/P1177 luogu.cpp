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
// 基数排序

int n;
vector<string> f;
vector<int> ANS;

queue<string> q[10];// 0 1 2 3 4 5 6 7 8 9

void Prev(int MLen) {
  rep(0, i, n) {
    if(f[i].length() < MLen) {
      int res = MLen - f[i].length();
      string tmp = "";
      while(res--) {
        tmp += "0";
      }
      f[i] = tmp + f[i];
    }
  }
}

void End(int MLen) {
  rep(0, i, n) {
    ANS.push_back(stoi(f[i]));
  }
}

void solve(){
  int maxLen = -1;
  rep(0, i, n) {
    maxLen = max(maxLen, (int)f[i].size());
  }
  Prev(maxLen);
  int tmp = maxLen;
  while(tmp != 0) {
    tmp--;
    rep(0, i, n) {
      if(f[i][tmp] - '0' == 0) {
        q[0].push(f[i]);
      } else if(f[i][tmp] - '0' == 1) {
        q[1].push(f[i]);
      } else if(f[i][tmp] - '0' == 2) {
        q[2].push(f[i]);
      }else if(f[i][tmp] - '0' == 3) {
        q[3].push(f[i]);
      }else if(f[i][tmp] - '0' == 4) {
        q[4].push(f[i]);
      }else if(f[i][tmp] - '0' == 5) {
        q[5].push(f[i]);
      }else if(f[i][tmp] - '0' == 6) {
        q[6].push(f[i]);
      }else if(f[i][tmp] - '0' == 7) {
        q[7].push(f[i]);
      }else if(f[i][tmp] - '0' == 8) {
        q[8].push(f[i]);
      }else if(f[i][tmp] - '0' == 9) {
        q[9].push(f[i]);
      }
    }
    f.clear();
    rep(0, i, 10) {
      while(q[i].size()) {
        f.push_back(q[i].front());
        q[i].pop();
      }
    }
  }
  End(maxLen);
  bool flag = false;
  rep(0, i, n) {
    if(flag)
      cout << " " << ANS[i];
    else
      cout << ANS[i];
    flag = true;
  }
  cout << endl;
}

int main(){
  frep;
  cin >> n;
  string temp;
  rep(0, i, n) {
    cin >> temp;
    f.push_back(temp);
  }
  solve();
  frepC;
  sys;
  return 0;
}