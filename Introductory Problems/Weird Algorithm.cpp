// https://cses.fi/problemset/task/1633
#include <iostream>
#include <vector>
using namespace std;

void prt(vector<long long>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
vector<long long> weirdAlgorithm(int n) {
    vector<long long> sequence;
    long long x = n;
    sequence.push_back(x);
    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else
            x = 3 * x + 1;
        sequence.push_back(x);
    }
    return sequence;
}
int main() {
    int n;
    cin >> n;
    vector<long long> sequence = weirdAlgorithm(n);
    prt(sequence);
    return 0;
}