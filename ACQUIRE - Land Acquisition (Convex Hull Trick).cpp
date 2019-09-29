// ITNOA
// O(n.log(n)) Greedy DP with Convex Hull Trick by lnxdx, Mashhad, 2019
// This code solves SPOJ ACQUIRE - Land Acquisition (USACO Mar08)
// https://wcipeg.com/wiki/Convex_hull_trick
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define double long double
const int N = 5e4 + 10;
pair<int, int> a[N];
vector<pair<int, int>>b; // b[j + 1].second = slope (m), b[i].first = input query (x)
				   /*
				   Slopes should be in non-increasing order to solve using O(log(n)) 'query' method.
				   If x's be also non-decreasing you can use O(1) (amortized) 'query' method.
				   */
int n;
bool cmp(pair<int, int>a, pair<int, int > b) {
	if (a.first < b.first)return true;
	if (a.first == b.first)return a.second > b.second;
	return false;
}
struct CHT {
	int j;
	vector<ll>m, b; // slope and y-intercept
	CHT() :j(0) {}
	// Returns true if either line l1 or line l3 is always better than line l2.
	bool bad(int l1, int l2, int l3) {
		/*
		Intersection(l1,l2) has x-coordinate (b1-b2)/(m2-m1).
		Intersection(l1,l3) has x-coordinate (b1-b3)/(m3-m1).
		Set the former greater than the latter, and cross-multiply to ...
		... eliminate division.
		*/
		// Equality is needed when the lines are concurrent.		
		// return (b[l3] - b[l1])*(m[l1] - m[l2]) <= (b[l2] - b[l1])*(m[l1] - m[l3]); // Possible overflow
		return ((double)b[l3] - b[l1]) / (m[l1] - m[l3]) <= ((double)b[l2] - b[l1]) / (m[l1] - m[l2]);
	}
	void add(ll m_, ll b_) { // O(1)
		m.push_back(m_);
		b.push_back(b_);
		while (m.size() >= 3 && bad(m.size() - 3, m.size() - 2, m.size() - 1)) {
			m.erase(m.end() - 2);
			b.erase(b.end() - 2);
		}
	}
	/*
	Returns the minimum y-coordinate of any intersection between a given vertical ...
	... line and the lower envelope
	*/
	ll query(ll x) { // Two Pointers, O(1)
		j = min(j, (int)m.size() - 1);
		while (j < (int)m.size() - 1 &&
			m[j] * x + b[j] > m[j + 1] * x + b[j + 1]) // > for minimization, < for maximization
			j++;
		return m[j] * x + b[j];
	}
	/* ll query(ll x) { // Binary Search, O(log(n))
		int l = 0;
		int r = m.size() - 1;
		while (l < r) {
			int j = (l + r) / 2;
			if (m[j] * x + b[j] > m[j + 1] * x + b[j + 1])
				l = j + 1;
			else
				r = j;
		}
		return m[l] * x + b[l];
	} */
};
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1,cmp);
	int minw = a[n].second;
	b.push_back(a[n]);
	for (int i = n - 1;i>0;i--)
		if (a[i].second >= minw)
		{
			b.push_back(a[i]);
			minw = a[i].second;
		}
	reverse(b.begin(), b.end());

	ll ans = 0;
	CHT dp;
	dp.add(b[0].second, 0);
	for (int i = 0; i<b.size(); i++) {
		ans = dp.query(b[i].first);
		dp.add(b[i + 1].second, ans);
	}
	cout << ans;
}
