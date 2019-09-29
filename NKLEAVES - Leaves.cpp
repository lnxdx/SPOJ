// ITNOA
// O(k.n) DP with Convex Hull Trick by lnxdx, Mashhad, 2019
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e5 + 10;
const int K = 13;
int s[N];
ll sp[N];
ll dp[K][N];
struct CHT {
	int j;
	vector<ll>m, b; // Slope and y-intercept
	CHT() :j(0) {}
	bool bad(int l1, int l2, int l3) { // Possible overflow
		return (b[l3] - b[l1])*(m[l1] - m[l2]) <= (b[l2] - b[l1])*(m[l1] - m[l3]);
	}
	void add(ll m_, ll b_) { // O(1)
		m.push_back(m_);
		b.push_back(b_);
		while (m.size() >= 3 && bad(m.size() - 3, m.size() - 2, m.size() - 1)) {
			m.erase(m.end() - 2);
			b.erase(b.end() - 2);
		}
	}
	ll query(ll x) { // Two Pointers, O(1)
		j = min(j, (int)m.size() - 1);
		while (j < (int)m.size() - 1 && m[j] * x + b[j] > m[j + 1] * x + b[j + 1]) // > for minimization
			j++;
		return m[j] * x + b[j];
	}
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	for (int i = 1;i <= n;i++)
	{
		cin >> s[i];
		sp[i] = sp[i - 1] + s[i] * (ll)i;
		s[i] += s[i - 1];
	}
	for (int i = 1;i <= n;i++)
		dp[1][i] = (sp[i] - sp[0]) - (ll)1 * (s[i] - s[0]);
	for (int l = 2;l <= k;l++)
	{
		CHT ch;
		ch.add(-(l), dp[l - 1][l - 1] + (ll)l*s[l - 1] - sp[l - 1]);
		for (int i = l + 1;i <= n;i++)
		{
			dp[l][i] = ch.query(s[i]) + sp[i];
			ch.add(-(i), dp[l - 1][i - 1] + (ll)i*s[i - 1] - sp[i - 1]);
		}
	}
	cout << dp[k][n] << "\n";
}
