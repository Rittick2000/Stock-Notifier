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
void solve(vector<int> adj[],vector<int> &visited,int node,map<int,string> &mp2)
{
	visited[node]=1;
	cout<<mp2[node]<<endl;
	for(auto &i:adj[node])
	{
		if(!visited[i])
			solve(adj,visited,i,mp2);
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
		ll n;
		cin>>n;
		map<string,int> mp;
		map<int,string> mp2;
		vector<pair<int,int>> v;
		int ind=0;
		for(int i=0;i<n;i++)
		{
			string s1,s2;
			cin>>s1>>s2;
			if(mp.find(s1)==mp.end())
			{
				mp[s1]=ind;
				mp2[ind]=s1;
				ind++;
			}
			if(mp.find(s2)==mp.end())
			{
				mp[s2]=ind;
				mp2[ind]=s2;
				ind++;
			}
			v.pb({mp[s1],mp[s2]});
		}
		vector<int> adj[mp.size()];
		for(auto &i:v)
		{
			adj[i.first].pb(i.second);
		}
		string st;
		cin>>st;
		vector<int> visited(mp.size(),0);
		solve(adj,visited,mp[st],mp2);
	}
	return 0;
}
