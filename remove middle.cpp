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
		string s;
		cin>>s;
		map<char,vector<int>> mp;
		for(int i=0;i<s.size();i++)
		{
			mp[s[i]].pb(i);
		}
		for(auto &i:mp)
		{
			int n=i.second.size();
			if(n%2==0)
			{
				s[i.second[n/2]]='$';
				s[i.second[(n/2)-1]]='$';
			}
			else
			{
				s[i.second[n/2]]='$';
			}
		}
		for(auto &i:s)
		{
			if(i!='$')
				cout<<i;
		}
		cout<<endl;
	}
	return 0;
}
