// https://cses.fi/problemset/task/1633
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MOD = 1000000000+7;

int diceCombinations(int n){
    vector<int> dp(max(7, n+1), 0);
    dp[0]=0;
    dp[1]=1;
    dp[2]=2;
    dp[3]=4;
    dp[4]=8;
    dp[5]=16;
    dp[6]=32;
    for(int i=7;i<=n;i++){
        for(int j=1;j<=6;j++){
            dp[i]=(dp[i]+dp[i-j])%MOD;
        }
    }
    return dp[n];
}

int main(){
    int n;
    cin>>n;
    cout<<diceCombinations(n)<<endl;
    return 0;
}