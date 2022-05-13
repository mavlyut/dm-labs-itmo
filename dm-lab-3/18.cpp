#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

ostream& operator << (ostream& out, const vector<vector<ll>>& a) {
    for (const vector<ll>& i : a) {
        for (ll j : i) {
            out << j << " ";
        }
        out << '\n';
    }
    return out;
}

vector<ll> c;
ll C(int n) {
    if (c[n] == -1) {
        if (n == 0) {
            c[n] = 1;
        } else {
            c[n] = C(n - 1) * (4 * n - 2) / (n + 1);
        }
    }
    return c[n];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string psp;
    cin >> psp;
    unsigned int n = psp.length();
    c = vector<ll>(n, -1);

    vector<vector<ll>> dp(n, vector<ll>(n + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        if (i % 2 == 0) {
            dp[i][0] = C(i / 2);
        }
        for (int j = 1; j < n; j++) {
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
        }
    }

    ll k = 0;
    int bal = 0;
    for (int i = 0; i < n; i++) {
        k += (psp[i] == '(') ? 0 : dp[n - i - 1][bal + 1];
        bal += (psp[i] == '(') ? 1 : -1;
    }

    cout << k;

    return 0;
}
