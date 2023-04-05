#include"bits/stdc++.h"
#include"iostream"
using namespace std;
#define rep(a,i,n) for(int i=a;i<n;i++)
#define per(a,i,n) for(int i=n;i>a;i--)
#define Rep(a,i,n) for(int i=a;i<=n;i++)
#define Per(a,i,n) for(int i=n;i>=a;i--)
#define frep freopen("in.txt","r",stdin)
#define frepC freopen("CON","r",stdin)
#define sys system("pause")
typedef long long ll;

int N;// 字符串的长度
string S;// S 串的字符
string T;// 生成的 T 串

// 每次找正序和逆序字符串中字典序小的字符串，取出其头部加入 T 中
void solve(){
  string S_hat = S;
  reverse(S_hat.begin(), S_hat.end());// 逆序字符串
  while(S.length() != 0){
    if(S <= S_hat) {
      T += S[0];// 加入头部至 T 串
      S.erase(S.begin() + 0);// 删除 S 串头部
      S_hat.erase(S_hat.begin() + S_hat.length() - 1);
    } else {
      T += S_hat[0];
      S.erase(S.begin() + S.length() - 1);
      S_hat.erase(S_hat.begin() + 0);
    }
  }
  /// 计数器
  // 每当到 80 清零
  int counter = 0;
  rep(0, i, N){
    counter++;
    cout << T[i];
    if(counter == 80){
      counter = 0;// 归零
      cout << endl;
    }
  }
}

int main(){
  frep;
  cin >> N;
  char tmp;
  rep(0, i, N){
    cin >> tmp;
    S += tmp;
  }
  solve();
  frepC;
  sys;
  return 0;
}