// https://cses.fi/problemset/task/1633
#include <iostream>
#include <vector>
using namespace std;


int missingNumber(vector<int> arr) {
    vector<bool> vis(arr.size()+1, 0);
   for(int i=0;i<arr.size();i++){
        vis[arr[i]-1]=1;
   }
   for(int i=0;i<arr.size()+1;i++){
    if(!vis[i])
        return i+1;
   }
   return 1;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n-1;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<missingNumber(arr);
    return 0;
}