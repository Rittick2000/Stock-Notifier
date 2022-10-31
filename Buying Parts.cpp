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
ll solve(vll &v,ll pos,ll n,ll p,vector<vector<ll>> &dp)
{
	if(pos>=n and p>0)
		return inf;
	if(p==0)
		return 0;
	if(dp[n][p]!=-1)
		return dp[n][p];
	ll taken=inf;
	if(pos<n-1)
	{
		taken=max(v[pos+1]-v[pos],solve(v,pos+2,n,p-1,dp));
	}
	ll not_taken=solve(v,pos+1,n,p,dp);
	return dp[n][p]=min(taken,not_taken);
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
		ll p,n;
		cin>>p;
		cin>>n;
		vll v(n);
		fr(0,n)
		cin>>v[i];
		sort(all(v));
		vector<vector<ll>> dp(n+1,vector<ll> (p+1,-1));
		ll ans=solve(v,0,n,p,dp);
		cout<<ans<<endl;
	}
	return 0;
}
