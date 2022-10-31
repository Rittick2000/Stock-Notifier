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
bool check(vll &v,ll mid,ll l)
{
	if(v[0]-mid>=1)
		return false;
	for(int i=1;i<v.size();i++)
	{
		if(v[i-1]+mid<v[i]-mid)
			return false;
	}
	if(v[v.size()-1]+mid<l)
	return false;
	return true;
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
		ll n,l;
		cin>>n>>l;
		vll v(n);
		fr(0,n)
		cin>>v[i];
		ll low=1,high=1e9;
		ll ans=-1;
		while(low<=high)
		{
			ll mid=(low+high)/2;
			if(check(v,mid,l))
			{
				ans=mid;
				high=mid-1;
			}
			else
			{
				low=mid+1;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
