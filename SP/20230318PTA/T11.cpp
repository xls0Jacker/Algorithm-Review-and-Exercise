#include<bits/stdc++.h>
using namespace std;
// #define TIE ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
const int maxn=10010;
vector<int>lis[maxn];
vector<int>tmp;
vector<int>ans;
int max_len=0;
int vis[maxn];
// int v[maxn];
int n,origin;
void dfs(int x,int deep){
    // if(v[x])return;
    int l=lis[x].size();
    if(max_len<deep){
        max_len=deep;
        ans.clear();
        ans=tmp;
    }
    for(size_t i=0;i<l;i++){
        // v[lis[x][i]]=1;
        tmp.push_back(lis[x][i]);
        dfs(lis[x][i],deep+1);
        // v[lis[x][i]]=0;
        tmp.pop_back();
    }
    return;
}
int find_origin(){
    for(int i=0;i<n;i++){
        if(!vis[i])return i;
    }
    return 0;
}
int main(){
    // TIE
    int cap,tmp;cin>>n;
    for(int i=0;i<n;i++){
        cin>>cap;
        for(int j=1;j<=cap;j++){
            cin>>tmp;
            lis[i].push_back(tmp);
            // pre[tmp].push_back(i);
            vis[tmp]=1;
        }
        sort(lis[i].begin(),lis[i].end());
    }
    int index=find_origin();
    // cout<<index<<endl;
    dfs(index,0);
    cout<<max_len+1<<endl;
    cout<<index;
    for(size_t i=0;i<ans.size();i++){
        if(i!=ans.size()-1)cout<<' '<<ans[i];
        else{
            cout<<' '<<ans[i];
        }
    }
    cout<<endl;
//     system("pause");
    return 0;
}
/*
10
3 6 4 8
0
0
0
2 5 9
0
1 7
1 2
0
2 3 1
*/
