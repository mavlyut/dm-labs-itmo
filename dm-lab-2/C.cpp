#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<string> vs;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<char> eq;
    int n = s.length();
    vs res(n);
    for (int i = 0; i < n; i++) {
        eq.push_back(s[i]);
        res[i] += s[i];
    }
    for (int i = 1; i < n; i++) {
        sort(res.begin(), res.end());
        for (int j = 0; j < n; j++) {
            res[j] = eq[j] + res[j];
        }
    }
    sort(res.begin(), res.end());
    cout << res[0];

    return 0;
}