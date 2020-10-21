/*input
5 5
2 1
2 5
1 5
5 4
3 5
*/
#include <bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define endl "\n"
#define ll long long int
#define vll vector<ll>
#define pll pair<long long, long long>
#define mod 1000000007
#define inf 9000000000000000001
#define rep(i,a,b)  for(ll i=a;i<b;i++)
#define repr(i,a,b) for(ll i=b-1;i>=a;i--) 
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define sz(x)  ((ll)x.size())
#define DEBUG
#ifdef DEBUG
#define dbg(x) cout << (#x) << " is " << (x) << endl
#else 
#define dbg(x)
#endif
#define N 200002

using namespace std;

vll adj[N];
ll vis[N];
ll col[N];
ll in[N];

void dfs(ll cur)
{
	vis[cur]=1;
	for(auto x: adj[cur])
	{
		if(!vis[x])
		{
			dfs(x);
			
		}
	}
}

int main()
{
	fastio
	ll T=1,n,m;string str;
	// cin>>T;
	// cin.ignore(); put after cin, just b4 a getline(cin, s) to avoid getline() directly getting \n
	while(T--)
	{
		ll tmp=0,sum=0,count=0; //tmp variable
		int flag=0;
		
		cin>>n;
		m = n-1;
		cin >> m;

		for(ll i =0;i<m;i++)
		{
			ll p,q;
			cin >> p >> q;
			p--;q--;
			adj[p].eb(q);
			in[q]++;
			// adj[q].eb(p);
		}

		queue <ll> q;

		for (int i = 0; i < n; ++i)
		{
			if(!in[i])
			{
				q.push(i);
				// dbg(i+1);
			}
			
		}
		vll topo;
		while(!q.empty())
		{
			ll cur = q.front();
			q.pop();
			topo.eb(cur);
			for(auto x:adj[cur])
			{
				in[x]--;
				if(!in[x]) q.push(x);
			}
		}

		if(sz(topo)<n)
		{
			cout << "graph has a cycle" << endl;
		}

		cout << "Topological order: " << endl;
		for (int i = 0; i < sz(topo); ++i)
		{
			cout << topo[i]+1 << " ";
		}cout << endl;




		
	}
	return 0;
}