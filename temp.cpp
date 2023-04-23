#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int head[300];
int to[10000];
int w[10000];
int jun[10000];
int next1[10000];
int dis[20000];
int cnt;
map<string, int> mp;
map<int, string> mmp;
void add(int a, int b, int c)
{
    cnt++;
    to[cnt] = b;
    w[cnt] = c;
    next1[cnt] = head[a];
    head[a] = cnt;
}
int vis[20000];
string be, en;
int v[20000];
int ans = 0;
vector<int >ss;
vector<int>  t;
int mindis;
int maxsum;
int maxrout;
void dfs(int x, int di,int rou)
{
    //cout << rou << endl;
    if (x == mp[en]&&di==mindis)
    {
        maxsum++;
        if (t.size() > ss.size())
        {
           // maxsum = 1;
            ss = t;
            maxrout = rou;
        }
        else if (t.size() == ss.size())
        {
            //maxsum++;
            if (rou > maxrout)
            {
                maxrout = rou;
                ss = t;
            }
        }
        else
        return;
    }
    for (int i = head[x]; i; i = next1[i])
    {
        int now = to[i];
        if (v[now] == 0)
        {
            v[now] = 1;
            t.push_back(now);
           // for (auto i : t) cout << mmp[i] << " ";
           // cout << endl;
            dfs(now, di + w[i],rou+jun[now]);
            v[now] = 0;
            t.pop_back();
        }
    }
}
int main()
{
  freopen("in.txt", "r", stdin);
  memset(dis, 0x3f3f3f3f, sizeof(dis));
  int n, k;
  cin >> n >> k;
  cin >> be >> en;
  // cout << be << en << endl;
  mp[be] = 1;
  mmp[1] = be;
  jun[1] = 0;
  for (int i = 2; i <= n; i++)
  {
    string s;
    cin >> s;
    int a;
    cin >> a;
    mp[s] = i;
    mmp[i] = s;
    jun[i] = a;
    }
   // for (auto i : mp) cout << i.first << " " << i.second << endl;
    while (k--)
    {
        string x, y;
        int c;
        cin >> x;
        cin >> y;
        cin >> c;
       // cout << x <<" "<< y <<" "<< c << endl;
        add(mp[x], mp[y], c);
        add(mp[y], mp[x], c);
    }
    //cout << cnt << endl;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
   // priority_queue<node> q;
    q.push(make_pair(0, mp[be]));
    //vector<int >t;
    //q.push({ t,0,0 });
    dis[mp[be]] = 0;
    while (!q.empty())
    {
        auto x = q.top();
        q.pop();
        int now = x.second;
        if (vis[now]) continue;
        vis[now] = 1;
        for (int i = head[now]; i; i = next1[i])
        {
            int v = to[i];
            if (dis[v] > dis[now] + w[i])
            {
                dis[v] = dis[now] + w[i];
                q.push(make_pair(dis[v], v));
            }
        }
    }
   // cout << dis[mp[en]] << endl;
    mindis = dis[mp[en]];
    t.push_back(1);
    dfs(1, 0,0);
    
    for (int i=0;i<(int)ss.size()-1;i++)
    {
        cout << mmp[ss[i]] << "->";
    }
    cout << mmp[ss[ss.size() - 1]] << endl;;
    cout << maxsum << " " << mindis << " " << maxrout;
    freopen("CON", "r", stdin);
    system("pause");
}
