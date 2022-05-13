#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> vi;

ostream& operator << (ostream& out, vi& p) {
    for (int i : p) {
        out << i << "+";
    }
    return out;
}

int n, r;
vector<vi> dp;

int getDp(int i, int j) {
    if (i < 0 || j < 0 || i > n || j > n) {
        return 0;
    }
    return dp[i][j];
}

void preCalc() {
    // dp[n][k] - количество способов разбить n на слагаемые >= k
    // dp[i][j] = dp[i - j][j] + dp[i][j - 1]
    // dp[k][k] = 1
    // dp[n][k] = 0 if k > n
    dp[0][0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = n; j >= 0; j--) {
            if (j == i) {
                dp[i][j] = 1;
            } else if (j > i) {
                dp[i][j] = 0;
            } else {
                dp[i][j] = getDp(i - j, j) + getDp(i, j + 1);
            }
        }
    }
}

void gen(vi p, int last, int sum) {
    if (n == sum) {
        r--;
    }
    for (int c = last; c <= n; c++) {
        if (sum + c <= n) {
            int t = getDp(n - sum - c, c);
            if (r < t) {
                p.push_back(c);
                gen(p, c, sum + c);
                return;
            }
            r -= t;
        }
    }
    if (r == 0) {
        cout << p << n - sum;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> r;
    dp = vector<vi>(n + 1, vi(n + 1, 0));

    preCalc();
    gen(vi(0), 1, 0);

    return 0;
}
