/ ITNOA
// O(n) DP with Convex Hull Optimization by lnxdx, Mashhad, 2019
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1e6 + 10;
ll x[N];
struct CHDP {
	int j;
	vector<ll>m, b;
	CHDP(int n) { j = 0, m.reserve(n), b.reserve(n); }
	bool bad(int l1, int l2, int l3) {
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
		while (j < (int)m.size() - 1 &&
			m[j] * x + b[j] < m[j + 1] * x + b[j + 1])
			j++;
		return m[j] * x + b[j];
	}
	//ll query(ll x) { // Binary Search, O(log(n))
	//	int l = 0;
	//	int r = m.size() - 1;
	//	while (l<r) {
	//		int j = (l + r) / 2;
	//		if (m[j] * x + b[j] > m[j + 1] * x + b[j + 1])
	//			l = j + 1;
	//		else
	//			r = j;
	//	}
	//	return m[l] * x + b[l];
	//}
};
int main() {
	int t;
	scanf("%d", &t);
	while (t--)
	{
		int n, a, b, c;
		scanf("%d%d%d%d", &n, &a, &b, &c);
		for (int i = 1;i <= n;i++)
		{
			scanf("%lld", x + i);
			x[i] += x[i - 1];
		}
		ll ans = 0;
		CHDP dp(n + 1);
		dp.add(0, 0);
		for (int i = 1; i <= n; i++) {
			ans = dp.query(x[i]) + a*x[i] * x[i] + b*x[i] + c;
			dp.add(-2 * a*x[i], ans + a*x[i] * x[i] - b*x[i]);
		}
		printf("%lld\n", ans);
	}
} 
