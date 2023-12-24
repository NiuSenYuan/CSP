/*
8分解法
dfs+剪枝
*/
#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
const int N=110;
int n,m,l,k;
vector<pair<int,int> >g[N];
bool vis[N];
bool flag[N];
int U[5010];
int V[5010];
int D[5010];
int C[N];
int ans=0;
void dfs(int u,int num,int len)
{
	vis[C[u]]=true;
	if(u==n-1)
	{
		ans=max(ans,len);
		vis[C[u]]=false;
		return;
	}
	for(auto v:g[u])
	{
		if(flag[v.first]||vis[C[v.first]])continue;
		if(num+1<=l)
		{
			flag[v.first]=true;
			dfs(v.first,num+1,len+v.second);
			flag[v.first]=false;
		}
	}
	vis[C[u]]=false;
}
int main()
{
	cin>>n>>m>>l>>k;
	for(int i=0;i<n;i++) cin>>C[i];
	for(int i=0;i<m;i++) cin>>U[i];
	for(int i=0;i<m;i++) cin>>V[i];
	for(int i=0;i<m;i++) cin>>D[i];
	for(int i=0;i<m;i++)
	{
		g[U[i]].push_back({V[i],D[i]});
	}
	dfs(0,1,0);
	cout<<ans<<endl;
	return 0;
}
