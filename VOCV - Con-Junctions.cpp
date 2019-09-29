/ IN THE NAME OF GOD
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 15;
int MOD = 1e4 + 7;
vector<int>adj[N];
int dp[N][2], cnt[N][2];
int n;
int dfs(int u, bool lit, int par)
{
	if (dp[u][lit])
		return dp[u][lit];
	if (lit)
	{
		dp[u][1] = 1;
		cnt[u][1] = 1;
		for (int i = 0;i < adj[u].size();i++)
		{
			int v = adj[u][i];
			if (v - par)
			{
				dp[u][1] += min(dfs(v, 0, u), dfs(v, 1, u));
				int t = 0;
				if (dp[v][0] <= dp[v][1])
					t += cnt[v][0];
				if (dp[v][1] <= dp[v][0])
					t += cnt[v][1];
				cnt[u][1] = (cnt[u][1] * t) % MOD;
			}
		}
	}
	else
	{
		dp[u][0] = 0;
		cnt[u][0] = 1;
		for (int i = 0;i < adj[u].size();i++)
		{
			int v = adj[u][i];
			if (v - par)
			{
				dp[u][0] += dfs(v, 1, u);
				cnt[u][0] = (cnt[u][0] * cnt[v][1]) % MOD;
			}
		}
	}
	return dp[u][lit];
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		memset(dp, 0, sizeof dp);
		memset(cnt, 0, sizeof cnt);
		cin >> n;
		for (int i = 0;i <= n;i++)
			adj[i].clear();
		for (int i = 0;i < n - 1;i++)
		{
			int u, v;
			cin >> u >> v;
			u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		adj[0].push_back(n);
		adj[n].push_back(0);
		dfs(n, 1, -1);
		cout << dp[n][1] - 1 << ' ' << cnt[n][1] << "\n";
	}
}
 
