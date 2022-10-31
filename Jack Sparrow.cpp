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
ll dfs(vector<ll> adj[],vector<int> &visited,ll node,ll &ans,vector<ll> &colors)
{
	visited[node]=1;
	vector<ll> temp;
	for(auto &child:adj[node])
	{
		if(!visited[child] and colors[child]==colors[node])
		{
			temp.push_back(dfs(adj,visited,child,ans,colors));
		}
	}
	if(temp.empty())
	{
		ans=max(ans,1LL);
		return 1;
	}
	else if(temp.size()==1)
	{
		ans=max(ans,1+temp[0]);
		return 1+temp[0];
	}
	else
	{
		auto it=max_element(all(temp));
		ll maxi1=(*it);
		temp.erase(it);
		it=max_element(all(temp));
		ll maxi2=(*it);
		ans=max(ans,1+maxi1+maxi2);
		return 1+max(maxi1,maxi2);
	}
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
		ll n,no_of_color;
		cin>>n>>no_of_color;
		vector<ll> colors(n+1);
		for(int i=1;i<=n;i++)
		{
			cin>>colors[i];
		}
		vector<ll> adj[n+1];
		for(int i=1;i<n;i++)
		{
			ll a,b;
			cin>>a>>b;
			adj[a].push_back(b);
			adj[b].push_back(a);
		}
		vector<int> visited(n+1,0);
		ll ans=INT_MIN;
		for(int i=1;i<=n;i++)
		{
			if(!visited[i])
			{
				dfs(adj,visited,i,ans,colors);
				//cout<<ans<<"  "<<i<<" "<<colors[i]<<endl;
			}
			
		}
		cout<<ans<<endl;
	}
	return 0;
}
