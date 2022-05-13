#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, r;
    cin >> n;
    n = 1 << n;
    vector<int> a(n), f;
    vector<string> str;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s >> r;
        str.push_back(s);
        f.push_back(r);
    }
    for (int x = 0; x < n; ++x) {
        a[x] = f[0];
        for (int y = x; y > 0; y = (y - 1) & x) {
            a[x] ^= f[y];
        }
    }
    for (int i = 0; i < n; i++) {
        cout << str[i] << " " << a[i] << endl;
    }

    return 0;
}