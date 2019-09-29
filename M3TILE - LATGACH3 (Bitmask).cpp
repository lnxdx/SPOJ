// ITNOG
// O(n.2^3) Bitmask DP by lnxdx, Mashhad, 2018
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define bit(a , b) (((a)>>(b))&1)
#define bt(x) __builtin_popcount(x)
 
const int MAXN = 33;
const int MAXM = (1 << 3) + 13;
 
ll dp[MAXN][MAXM];
 
void solve(int n)
{
	memset(dp, 0, sizeof dp);
	dp[0][7] = 1;
 
	for (int i = 0; i <= n + 1; i++)
		for (int mask = 0; mask < (1 << 3); mask++)
		{
			for (int next_mask = 0; next_mask < (1 << 3); next_mask++)
			{
				int occ = next_mask | mask;
				if (bt(next_mask) + bt(mask) != bt(occ))
					continue;
 
				int T = 0;
				if (occ == 1 || occ == 4)
					T = 1;
				else if (occ == 7)
					T = 1;
 
				dp[i + 1][next_mask] += dp[i][mask] * T;
			}
		}
}
 
int main()
{
	solve(31);
 
	int n;
	while (cin >> n && (n != -1)) {
		cout << dp[n + 1][0] << "\n";
	}
}
 
