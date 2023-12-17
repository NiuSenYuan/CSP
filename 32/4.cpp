#include <iostream>
#include <deque>
#include <cstring>
#include <algorithm>
using namespace std;
const long long mod=998244353;
const int N=1e5+10;
long long zl[N][5];
int n,m;
typedef struct Matrix{
	long long m[3][3];
}mat;
mat Mulmat(const mat& p1,const mat& p2)
{
	mat res;
	for(int i=1;i<=2;i++)
	{
		for(int j=1;j<=2;j++)
		{
			res.m[i][j]=0;
			for(int k=1;k<=2;k++)
			{
				res.m[i][j]+=(p1.m[i][k]*p2.m[k][j]+mod)%mod;
			}
			res.m[i][j]=(res.m[i][j]+mod)%mod;
		} 
	}
	return res;
}
deque<mat>d;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		int v;
		scanf("%d",&v);
		zl[i][0]=v;
		if(v<=2)
		{
			scanf("%lld%lld%lld%lld",&zl[i][1],&zl[i][2],&zl[i][3],&zl[i][4]);
		}
	}
	for(int j=1;j<=m;j++)
	{
		int v;
		scanf("%d",&v);
		if(v==1)
		{
			int id,ins;
			scanf("%d%d",&id,&ins);
			zl[id][0]=ins;
			if(ins<=2)
			{
				scanf("%lld%lld%lld%lld",&zl[id][1],&zl[id][2],&zl[id][3],&zl[id][4]);
			}
		}
		else
		{
			mat res;
			int l,r,vis=0;
			scanf("%d%d",&l,&r);
			for(int i=l;i<=r;i++)
			{
				res.m[1][1]=zl[i][1];
				res.m[1][2]=zl[i][2];
				res.m[2][1]=zl[i][3];
				res.m[2][2]=zl[i][4];				
				if(zl[i][0]==1)
				{
					d.push_front(res);
					vis=1;
				}
				else if(zl[i][0]==2)
				{
					d.push_back(res);
					vis=2;
				}
				else
				{
					if(vis)
					{
						if(vis==1)d.pop_front();
						else d.pop_back();
					}
					vis=0;
				}
			}
			res.m[1][1]=res.m[2][2]=1;
			res.m[1][2]=res.m[2][1]=0;
			while(d.size())
			{
				res=Mulmat(res,d.front());
				d.pop_front();
			}
			printf("%lld %lld %lld %lld\n",res.m[1][1],res.m[1][2],res.m[2][1],res.m[2][2]);
		}
	}
	return 0;
}
