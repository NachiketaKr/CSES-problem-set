// https://cses.fi/problemset/task/1744
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int rectangleCutting(int a, int b){
    if(a>b)
        return rectangleCutting(b, a);
    vector<vector<int>> dp(a+1, vector<int>(b+1, 0));

    for(int i=1;i<=a;i++){
        for(int j=1;j<=b;j++){
            if(i==j){
                dp[i][j]=0;
                continue;
            }
            int mn=INT_MAX;
            for(int k=1;k<j;k++){
                mn = min(mn, 1+dp[i][k]+dp[i][j-k]);
            }
            for(int k=1;k<i;k++){
                mn = min(mn, 1+dp[i-k][j]+dp[k][j]);
            }
            dp[i][j]=mn;
        }
    }
    return dp[a][b];
}
int main() {

    int a, b;
    cin>>a>>b;
    cout<<rectangleCutting(a, b)<<endl;
    return 0;
}