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
ll solve(vector<ll> adj[],ll node,vector<int> &visited)
{
	visited[node]=1;
	ll ans=1;
	for(auto &child:adj[node])
	{
		if(!visited[child])
			ans+=solve(adj,child,visited);
	}
	return ans;
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
		ll n,m;
		cin>>n>>m;
		vll a(m);
		fr(0,m)
		cin>>a[i];
		cin>>m;
		vll b(m);
		fr(0,m)
		cin>>b[i];
		vector<ll> adj[n+1];
		fr(0,m)
		{
			adj[a[i]].pb(b[i]);
			adj[b[i]].pb(a[i]);
		}
		ll ans=-1;
		vector<int> visited(n+1,0);
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				ans=max(ans,solve(adj,i,visited));
			}
		}
		cout<<ans<<endl;

	}
	return 0;
}
