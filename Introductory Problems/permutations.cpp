// https://cses.fi/problemset/task/1070
#include <iostream>
#include <vector>
using namespace std;

void prt(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
vector<int> permutations(int n) {
    vector<int> sequence;
    for(int i=2;i<=n;i+=2){
        sequence.push_back(i);
    }
    for(int i=1;i<=n;i+=2){
        sequence.push_back(i);
    }
    return sequence;
}
int main() {
    int n;
    cin >> n;
    if(n==3 || n==2){
        cout<<"NO SOLUTION"<<endl;
    }
    else{
        vector<int> sequence = permutations(n);
        prt(sequence);
    }
    return 0;
}