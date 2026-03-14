//https://cses.fi/problemset/task/1635

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

const int MOD = 1e9+7;
int helper(vector<int>& arr, int x, vector<int>& dp){
    if(x==0){
        return 1;
    }
    if(x<0)
        return 0;
    if(dp[x]!=-1)
        return dp[x]% MOD;
    int sum=0;
    for(int i=0; i<arr.size();i++){
        if(arr[i]<=x){
            sum=(sum+helper(arr, x-arr[i], dp))%MOD;
        }
    }
    return dp[x]=sum%MOD;
}
int coinsCombinationI(vector<int>& arr, int n, int x){
    vector<int> dp(x+1, -1);
    return helper(arr, x, dp);
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
    cout<<coinsCombinationI(arr, n, x)<<endl;
    return 0;
}