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
		if(n<=0)
			return 0;
		if(n==1)
			return 1;
		if(n==2)
			return 2;
		if(n==3)
			return 2;
		else
		{
			vector<int> dp(n+1);
			dp[0]=0;
			dp[1]=1;
			dp[2]=1;
			dp[3]=2;
			for(int i=4;i<=n;i++)
				dp[i]=dp[i-1]+dp[i-3];
			cout<<dp[n]<<endl;
		}
	}
	return 0;
}
