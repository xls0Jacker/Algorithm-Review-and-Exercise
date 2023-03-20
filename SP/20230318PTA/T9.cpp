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
const int NMAX = 1e3 + 5;// 稍微大一点

int a, b, n;// 第一项 第二项 结果数目

void solve(){
  vector<int> v;// 存储结果
  v.push_back(a);
  v.push_back(b);
  int i = 0;// 第一个乘数的位次
  while(v.size() < n){
    int Nnum = v[i] * v[i + 1];// 倒数两项的乘积
    if(Nnum >= 10) {
      string s = to_string(Nnum);
      string s1 = "";
      s1 += s[0];
      string s2 = "";
      s2 += s[1];
      int num1 = stoi(s1);
      int num2 = stoi(s2);
      v.push_back(num1);
      v.push_back(num2);
    } else {
      v.push_back(Nnum);
    }
    i++;
  }
  bool flag = false;
  rep(0, i, n) {
    if(flag)cout << " " << v[i];
    else
      cout << v[i];
    flag = true;
  }
  cout << endl;
}

int main(){
  frep;
  cin >> a >> b >> n;
  solve();
  frepC;
  sys;
  return 0;
}