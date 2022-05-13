#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    string s;
    cin >> s;
    vector<string> res;
    unsigned int n = s.length();
    res.reserve(n);
    for (int i = 0; i < n; i++) {
        res.push_back(s.substr(i, n) + s.substr(0, i));
    }
    sort(res.begin(), res.end());
    for (string i : res) {
        cout << i[n - 1];
    }

	return 0;
}