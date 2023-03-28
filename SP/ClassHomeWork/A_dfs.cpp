//************************************
//*八数码问题
//************************************
#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
#include<string>
#include<time.h>
using namespace std;
const int MAX_SIZE = 1e7 + 5;// 稍微大一点

struct P{
	int d;	//深度g(n)
	int w = 0;	//启发式信息h(n)
	int id;	//记录该节点的id，用于输出时找到该节点
	string s;	//状态
	friend bool operator <(const P &a,const P &b){//按f(n)=g(n)+h(n)大小排序
		return a.d+a.w>b.d+b.w;  //最大堆
	}
}p;
const int N=3;	//棋盘大小
const string t="123804765";  //目标状态
string stack[MAX_SIZE];		//记录搜索中的节点
string record[MAX_SIZE];		//从起点开始记录解路径
int father[MAX_SIZE];		//记录该节点的父节点
int top=0;					//stack的指针(生成结点每次放在 Open 表的前端 -- 栈)
priority_queue<P> pq;		//open表

map<string,bool> mp;		//记录该状态是否已经访问过：1访问过，0没有


// int calw(string s)//计算该状态的不在位数h(n)
// {
// 	int re=0;
// 	for(int i=0;i<9;i++) if(s[i]!=t[i]) re++;
// 	return re;
// }



// int calw(string s)//各数码移动到目标位置所需距离之和
// {
// 	int re=0;
// 	int j;
// 	for(int i=0;i<9;i++)
// 	{
// 		if(s[i]!=t[i] && s[i]!='0')
// 		{
// 			for(j=0;j<9;j++)
// 			{
// 				if(s[i]==t[j]) break;
// 			}
// 			re+=abs(i/3-j/3)+abs(i%3-j%3);
// 		}
// 	}
// 	return re;
// }


int solve()	//搜索过程
{
	P cur;
	int num_s=1;//生成的结点数（初始结点）
	while(!pq.empty()){
		cur=pq.top(); //open表
		pq.pop();
		if(cur.s==t) 
		{
			cout<<"生成结点数："<<num_s<<"\n";
			return cur.id;	//达到目标状态，返回当前节点的id
		}
		int x,y;
		int ops=0;
		while(cur.s[ops]!='0') ops++;
		x=ops/3,y=ops%3;  //空格所在位置
		int r=cur.id;
		if(x>0){          //空格向上移
			p.s=cur.s;// 临时量 用于交换位置
			swap(p.s[ops],p.s[ops-3]);
			if(!mp[p.s]){
        p.d = cur.d + 1, p.w = 0, p.id = top + 1;
        pq.push(p);
				num_s++;
				stack[++top]=p.s;
				father[top]=r;
				mp[p.s]=1;
			}
		}
		if(x<2){    //空格向下移
			p.s=cur.s;
			swap(p.s[ops],p.s[ops+3]);
			if(!mp[p.s]){
        p.d = cur.d + 1, p.w = 0, p.id = top + 1;
        pq.push(p);
				num_s++;
				stack[++top]=p.s;		
				father[top]=r;
				mp[p.s]=1;
			}
		}
		if(y>0){    //空格向左移
			p.s=cur.s;
			swap(p.s[ops],p.s[ops-1]);
			if(!mp[p.s]){
        p.d = cur.d + 1, p.w = 0, p.id = top + 1;
        pq.push(p);
				num_s++;
				stack[++top]=p.s;				
				father[top]=r;
				mp[p.s]=1;
			}
		}
		if(y<2){   //空格向右移
			p.s=cur.s;
			swap(p.s[ops],p.s[ops+1]);
			if(!mp[p.s]){
        p.d = cur.d + 1, p.w = 0, p.id = top + 1;
        pq.push(p);
				num_s++;
				stack[++top]=p.s;			
				father[top]=r;
				mp[p.s]=1;
			}
		}
	}

	return -1;
}

void print(int x)////从record表中输出当前搜索的节点
{
	int k=0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(record[x][k]=='0')
				printf("  ");
			else printf("%c ",record[x][k]);
			k++;
		}
		printf("\n");
	}
	printf("\n");
}
int main()
{
    time_t start,end;
		// freopen("in.txt", "r", stdin);
		int tt; //测试的组数
		cout << "请输入测试的组数:\n";
		cin >> tt;
		int num_c = 0;	 //扩展的结点数
		start = clock(); // 开始计时
		for (int k = 1; k <= tt; k++)
		{
			cout << "Case " << k << ":\n";
			int i, j;
			char a;
			p.s = "";
			for (i = 0; i < N; i++)
			{
				for (j = 0; j < N; j++)
				{
					cin >> a; //输入0～8数码
					p.s += a;
				}
			}
			p.d = 0, p.w = 0, p.id = 0;
			father[0] = -1;
			mp[p.s] = 1;
			stack[0] = p.s;
			pq.push(p);				//往open表中加入初始状态节点
			int id = solve(); //调用搜索过程
			if (id == -1)
			{
				cout << "无解！\n";
			}
			else
			{
				int c = -1;
				while (id >= 0)
				{ //把stack中存的节点按次序放入到record中
					record[++c] = stack[id];
					id = father[id];
				}
				end = clock(); // 计时结束
				num_c = c;
				double duration = ((double)(end - start)) / CLOCKS_PER_SEC; // 计算耗时
				cout << "扩展结点数：" << num_c << "\n";
				cout << "运行时间：" << duration << "秒\n";
				cout << "原图：" << endl;
				print(c); //输出初始节点
				cout << "移动过程: \n\n";
				for (i = c - 1; i >= 0; i--)
				{
					cout << "Step " << c - i << ":\n"; //输出当前搜索步骤
					print(i);													 //输出当前搜索的节点
				}
				cout << "移动结束！\n";
			}

			mp.clear();
			while (!pq.empty())
				pq.pop();
			top = 0;
			cout << endl;
	}
	// freopen("CON", "r", stdin);
	system("pause\n");
	return 0;
}