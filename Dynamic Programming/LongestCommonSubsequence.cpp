// https://cses.fi/problemset/task/3403/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void longestCommonSubsequence(int n, int m, vector<int>& arr1, vector<int>& arr2){

    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(arr1[i-1]==arr2[j-1]){
                dp[i][j]=1+dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }

    vector<int> LCS;
    int i=n, j=m;
    while(i>0 && j>0 && dp[i][j]>0){
        if(arr1[i-1] == arr2[j-1]){
            LCS.push_back(arr1[i-1]);
            i--;
            j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }   
    reverse(LCS.begin(), LCS.end());
    cout<<dp[n][m]<<endl;
    for(int k=0;k<LCS.size();k++){
        cout<<LCS[k]<<" ";
    }
    cout<<endl;
}

int main(){
    int n, m;
    cin>>n>>m;
    vector<int> arr1, arr2;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr1.push_back(x);
    }
    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        arr2.push_back(x);
    }
    longestCommonSubsequence(n, m, arr1, arr2);
    return 0;
}