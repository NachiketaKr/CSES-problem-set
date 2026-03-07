// https://cses.fi/problemset/task/1634/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD =10000000;

int minimisingCoins(int n, int x, vector<int>& arr){
    vector<vector<int>> dp(n+1, vector<int >(x+1, 0));
    for(int i=1;i<=x;i++){
        dp[0][i]=MOD;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=x;j++){
            if(j-arr[i-1]>=0){
                dp[i][j]=min(1+dp[i][j-arr[i-1]], dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
        }
    }
    return (dp[n][x]>=MOD)? -1: dp[n][x];
}

int main(){
    int n, x;
    cin>>n>>x;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int c;
        cin>>c;
        arr.push_back(c);
    }
    cout<<minimisingCoins(n, x, arr)<<endl;;
    return 0;
}