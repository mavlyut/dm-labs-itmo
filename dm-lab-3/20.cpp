#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <stack>
using namespace std;
typedef vector<int> vi;
typedef long long ll;

ostream& operator << (ostream& out, vi& p) {
    for (int i : p) {
        out << i << " ";
    }
    out << '\n';
    return out;
}

istream& operator >> (istream& in, vi& p) {
    for (int & i : p) {
        in >> i;
    }
    return in;
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

    string s;
    cin >> s;
    unsigned int n = s.length();
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
    int bal = 0, balS = 0;
    stack<int> opened;
    for (int i = 0; i < n; i++) {
        switch (s[i]) {
            case '(':
                bal++;
                balS++;
                opened.push(1);
                break;
            case ')':
                if (balS + 1 <= n - i - 1) {
                    k += dp[n - i - 1][bal + 1] * (ll) pow(2, (n - i - bal - 2) / 2);
                }
                bal--;
                balS--;
                opened.pop();
                break;
            case '[':
                if (balS + 1 <= n - i - 1) {
                    k += dp[n - i - 1][bal + 1] * (ll) pow(2, (n - i - bal - 2) / 2);
                }
                if (balS > 0 && opened.top() == 1) {
                    k += dp[n - i - 1][bal - 1] * (ll) pow(2, (n - i - bal) / 2);
                }
                bal++;
                opened.push(2);
                break;
            case ']':
                if (balS + 1 <= n - i - 1) {
                    k += dp[n - i - 1][bal + 1] * (ll) pow(2, (n - i - bal - 2) / 2);
                }
                if (balS > 0 && opened.top() == 1) {
                    k += dp[n - i - 1][bal - 1] * (ll) pow(2, (n - i - bal) / 2);
                }
                if (bal - balS + 1 <= n - i - 1) {
                    k += dp[n - i - 1][bal + 1] * (ll) pow(2, (n - i - bal - 2) / 2);
                }
                bal--;
                opened.pop();
                break;
        }
    }
    cout << k;

    cout << endl;
    return 0;
}
