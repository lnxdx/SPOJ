#include<bits/stdc++.h>
using namespace std;
#define W 23
int dp1[W]={1,1};
int dp2[W]={0,1};
int dp3[W]={0,1,1};
int dpr1(int n);
int dpr2(int n);
int dpr3(int n);
int dpr1(int n)
{
    if(dp1[n]==0)
        dp1[n]=dpr1(n-2)+dpr2(n)+dpr2(n-1)+dpr3(n-1);
    return dp1[n];
}
int dpr2(int n)
{
    if(dp2[n]==0)
        dp2[n]=dpr2(n-1)+dpr1(n-1);
    return dp2[n];
}
int dpr3(int n)
{
    if(dp3[n]==0)
        dp3[n]=dpr3(n-2)+dpr1(n-1);
    return dp3[n];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    dpr1(22);
    int t;
    cin>> t;
    int casi=1;
    while( t--)
    {
        int w;
        cin>> w;
        cout<< casi++<<' ' << dp1[w]<<"\n";
    }
} 
