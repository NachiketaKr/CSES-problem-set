// https://cses.fi/problemset/task/1094
#include <iostream>
#include <vector>
using namespace std;


long long increasingArray(vector<int> arr) {
    long long mnMoves=0;
    for(int i=1;i<arr.size();i++){
        if(arr[i]<arr[i-1]){
            mnMoves+=(long long)(arr[i-1]-arr[i]);
            arr[i]=arr[i-1];
        }
    }
    return mnMoves;
}
int main() {
    int n;
    cin >> n;
    vector<int> arr;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    cout<<increasingArray(arr);
    return 0;
}