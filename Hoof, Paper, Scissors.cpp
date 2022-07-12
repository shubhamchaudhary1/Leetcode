// Problem: Problem 2. Hoof, Paper, Scissors
// Contest: USACO - USACO 2017 January Contest, Gold
// URL: http://www.usaco.org/index.php?page=viewproblem2&cpid=694
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MX=1e5+5;

int dp[MX][25][3];
int A[MX];

int32_t main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		char a; cin>>a;
		if(a=='H') A[i]=0;
		if(a=='P') A[i]=1;
		if(a=='S') A[i]=2;
	}
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
		{
			for(int k=0;k<3;k++)
			{
				if(k==A[i]) dp[i][j][k]++;
				dp[i+1][j+1][0]=max(dp[i+1][j+1][0],dp[i][j][k]);
				dp[i+1][j+1][1]=max(dp[i+1][j+1][1],dp[i][j][k]);
				dp[i+1][j+1][2]=max(dp[i+1][j+1][2],dp[i][j][k]);
				dp[i+1][j][k]=max(dp[i+1][j][k],dp[i][j][k]);
			}
		}
	}
	int ans=0;
	for(int i=0;i<3;i++)
	{
		ans=max(ans,dp[n-1][k][i]);
	}
	cout<<ans<<endl;
}

