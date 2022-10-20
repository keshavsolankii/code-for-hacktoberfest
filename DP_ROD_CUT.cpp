#include <bits/stdc++.h>
using namespace std;

int cutRod(int price[], int i, int n,vector<vector<int> >& dp){
	// base case
	if (i <= 0) {
		return n * price[0];
	}
	if (dp[i][n] != -1)
		return dp[i][n];

	int remCut = cutRod(price, i - 1, n,dp);
	int cut = INT_MIN;
	int rod_length = i + 1;

	if (rod_length <= n)
		cut = price[i]+ cutRod(price, i, n - rod_length,dp);

	return dp[i][n]=max(remCut, cut);
	
}
int main()
{
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    // int size = sizeof(arr) / sizeof(arr[0]);
	vector<vector<int> > dp(n,vector<int>(n + 1, -1));
    cout<<cutRod(arr,n-1,n,dp);
}

// Time Complexity: O(n^2)

// Space Complexity : O(n^2)+O(n)
