#include"bits/stdc++.h"
using namespace std;
#define frep freopen("in.txt", "r", stdin)
#define frepC freopen("CON", "r", stdin)
#define sys system("pause")
#define rep(a, i, n) for (int i = a; i < n; i++)
#define Rep(a, i, n) for (int i = a; i <= n; i++)
#define per(a, i, n) for (int i = n; i > a; i--)
#define Per(a, i, n) for (int i = n; i >= a; i--)
typedef long long ll;

string S;// 输入的时间

void solve(){
  string s;// 子串（前两位）
  if(S.size() == 4) {
    s = S.substr(0, 2);
    int num = stoi(s);
    if(num < 22) {// 20 开头
      S.insert(2, "-");
      S.insert(0, "20");
      cout << S << endl;
      return;
    } else {
      S.insert(2, "-");
      S.insert(0, "19");
      cout << S << endl;
      return;
    }
  } else {
    S.insert(4, "-");
    cout << S << endl;
    return;
  }
}

int main(){
  frep;
  cin >> S;
  solve();
  frepC;
  sys;
  return 0;
}