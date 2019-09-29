// IN THE NAME OF GOD
#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 6111;
int dp[N][N];
string s;
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		cin >> s;
		int n = s.size();
		for (int l = 1;l <= n;l++)
			for (int i = 0;i + l - 1 < n;i++)
			{
				int j = i + l - 1;
				if (l == 1)
					dp[i][j] = 0;
				else if (l == 2)
					dp[i][j] = (s[i] != s[j]);
				else if (s[i] == s[j])
					dp[i][j] = dp[i + 1][j - 1];
				else
					dp[i][j] = min(dp[i + 1][j], dp[i][j - 1]) + 1;
			}
		cout << dp[0][n - 1] << "\n";
	}
} 
