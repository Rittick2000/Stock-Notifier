#include<bits/stdc++.h>
#define f1 ios_base::sync_with_stdio(false);
#define f2 cin.tie(NULL);
#define f3 cout.tie(NULL);
#define ll long long
#define pb push_back
#define fr(a,b) for(int i=a;i<b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define vll vector<ll>
#define vpll vector<pair<ll,ll>>
#define all(v) v.begin(),v.end()
#define lb lower_bound
#define ub upper_bound
#define mod 1000000007
#define inf INT_MAX
using namespace std;
vector<ll> parent;
vector<ll> rankk;
void dsu(ll n)
{
	for(int i=0;i<n;i++)
	{
		parent.push_back(i);
		rankk.push_back(1);
	}
}
ll find_par(ll node)
{
	if(parent[node]==node)
		return node;
	else
		return parent[node]=find_par(parent[node]);
}
ll unionn(ll a,ll b)
{
	ll x=find_par(a);
	ll y=find_par(b);
	if(rankk[x]>rankk[y])
	{
		parent[y]=x;
		rankk[x]+=rankk[y];
	}
	else
	{
		parent[x]=y;
		rankk[y]+=rankk[x];
	}
	return max(rankk[x],rankk[y]);
}

int main()
{
	f1;
	f2;
	f3;	
	ll T;
	cin>>T;
	rep(tk,0,T)
	{
		ll n;
		cin>>n;
		vector<ll> u(n);
		vll v(n);
		dsu(n);
		fr(0,n-1)
		{
			cin>>u[i];
			u[i]--;
		}
		fr(0,n-1)
		{
			cin>>v[i];
			v[i]--;
		}
		ll m;
		cin>>m;
		//cout<<m<<endl;
		vll removes(m);
		fr(0,m)
		{
			cin>>removes[i];
			removes[i]--;
		}
		vector<ll> visited(n,1);
		for(auto &i:removes)
		{
			//cout<<i<<" ";
			visited[i]=0;
		}
		//cout<<endl;
		ll maxi=INT_MIN;
		for(int i=0;i<n-1;i++)
		{
			if(visited[i])
			{
				maxi=max(maxi,unionn(u[i],v[i]));
			}
		}
		vector<ll> ans(m);
		for(int i=m-1;i>=0;i--)
		{
			ans[i]=maxi;
			maxi=max(maxi,unionn(u[removes[i]],v[removes[i]]));
		}
		for(auto &i:ans)
			cout<<i<<" ";
		cout<<endl;
	}
	return 0;
}
