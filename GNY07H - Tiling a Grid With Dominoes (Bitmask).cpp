// ITNOG
// O(n.2^4) Bitmask DP by lnxdx, Mashhad, 2018
 
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bit(a , b) (((a)>>(b))&1)
#define pop(x) __builtin_popcount(x)
 
const int MAXN = 25;
const int MAXM = (1 << 4) + 4;
 
ll dp[MAXN][MAXM];
 
void solve(int n, int m)
{
	memset(dp, 0, sizeof dp);
	int p = 1 << m;
	dp[0][p - 1] = 1;
 
	for (int i = 0; i <= n + 1; i++)
		for (int mask = 0; mask < p; mask++)
		{
			for (int next_mask = 0; next_mask < p; next_mask++)
			{
				int occ = next_mask | mask;
				if (pop(next_mask) + pop(mask) != pop(occ))
					continue;
 
				int t = 0;
				if (occ==0 || occ == 3 || occ == 12 || occ == 9 || occ == 15)
					t = 1;
 
				dp[i + 1][next_mask] += dp[i][mask] * t;
			}
		}
}
 
int main()
{
	solve(22,4);
 
	int t;
	cin >> t;
	int casi = 1;
	while (t--)
	{
		int n;
		cin >> n;
		cout << casi++ << ' ' << dp[n + 1][0] << "\n";
	}
}
 
