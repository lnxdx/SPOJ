#include <iostream>
using namespace std;
long long dp[10000][100];
int main()
{ 
    long long N;
    cin>>N; 
    while(N--)
	{
		long long m , n ;
		cin >> m >> n ;	 
		for (int i = 0 ; i  <=9 ; i ++ )	 
			for(int j =1 ; j<=n ; j++ )
			{ 
				if(i==0)
					dp[j][0] = 1;
				else if(j==1)
					dp[j][i] = i+1;
				else
					dp[j][i] = dp[j-1][i] + dp[j][i-1];	 
			}
	   cout<<m<<" "<<dp[n][9]<<endl;
   }
}
