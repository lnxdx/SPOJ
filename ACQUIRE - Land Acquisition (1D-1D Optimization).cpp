// ITNOA
// O(n.log(n)) Greedy DP with 1D/1D Optimization by lnxdx, Mashhad, 2019
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int INF = 2e9 + 1;
ll INFLL = 9e18;
const int N = 5e4 + 10;
ll dp[N];
pair<int, int> a[N];
vector<pair<int, int>>b;
int n;
bool cmp(pair<int, int>a, pair<int, int > b) {
	if (a.first < b.first)return true;
	if (a.first == b.first)return a.second > b.second;
	return false;
}
ll w(int i, int x) {
	return (ll)b[i + 1].second*b[x].first;
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i].first >> a[i].second;
	sort(a + 1, a + n + 1, cmp);
	int minw = a[n].second;
	b.push_back(a[n]);
	for (int i = n - 1;i>0;i--)
		if (a[i].second >= minw)
		{
			b.push_back(a[i]);
			minw = a[i].second;
		}
	b.push_back({ -1,-1 });
	reverse(b.begin(), b.end());
 
	vector<pair<int, int>>v; // argmin vector = {x, i}
	v.push_back({ 0,0 });
	for (int i = 1;i < b.size();i++)
	{
		int k = (--lower_bound(v.begin(), v.end(), make_pair(i + 1, 0)))->second;
		dp[i] = dp[k] + w(k, i);
		for (int j = (int)v.size() - 1;j >= 0;j--)
		{
			int x = v[j].first;
			int k = v[j].second;
			if (x > i && dp[k] + w(k, x) > dp[i] + w(i, x))
				v.pop_back();
			else
			{
				int l = x + 1;
				int r = b.size();
				while (l<r)
				{
					int mid = (l + r) / 2;
					if (dp[i] + w(i, mid) <= dp[k] + w(k, mid))
						r = mid;
					else
						l = mid + 1;
				}
				if (r != b.size())
					v.push_back({ r,i });
				break;
			}
		}
	}
	cout << dp[b.size() - 1];
} 
