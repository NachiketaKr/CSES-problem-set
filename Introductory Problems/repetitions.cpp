// https://cses.fi/problemset/task/1069
#include <climits>
#include <iostream>
#include <string>
using namespace std;

int repetitions(string s) {
    int i = 1;
    int mx = INT_MIN;
    int cnt = 1;
    while (i < s.size()) {
        if (s[i] == s[i - 1]) {
            cnt++;
        } else {
            mx = max(cnt, mx);
            cnt = 1;
        }
        i++;
    }
    return max(mx, cnt);
}
int main() {
    string s;
    cin >> s;
    cout << repetitions(s) << endl;
    return 0;
}