//https://cses.fi/problemset/task/1636

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MOD = 1e9+7;

int coinsCombinationII(vector<int>& arr, int n, int x){
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
    for(int i=1;i<=n;i++){
        dp[i][0]=1;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(arr[i-1]<=j){
                dp[i][j]=(dp[i-1][j]+dp[i][j-arr[i-1]])% MOD;
            }
            else
                dp[i][j]=dp[i-1][j]%MOD;
        }
    }
    return dp[n][x]%MOD;
}

int main() {
    int n, x;
    cin>>n>>x;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int t;
        cin>>t;
        arr.push_back(t);
    }
    cout<<coinsCombinationII(arr, n, x)<<endl;
    return 0;
}
