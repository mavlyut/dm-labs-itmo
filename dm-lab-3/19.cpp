#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<char> vc;
typedef long long ll;

int n;
ll k;
vector<vector<ll>> d;

void gen(string p, int balC, int balS, vc opened) {
    if (p.length() == 2 * n) {
        if (k == 0) {
            cout << p << endl;
            return;
        }
        k--;
    }
    int tmpPowOpen = (2 * n - p.length() - 2 - balS - balC) / 2;
    int tmpPowClose = (2 * n - p.length() - balS - balC) / 2;
    ll tOpen = d[2 * n - p.length() - 1][balC + balS + 1] * pow(2, tmpPowOpen);
    ll tClose = 0;
    if (balC > 0 || balS > 0) {
        tClose = d[2 * n - p.length() - 1][balC + balS - 1] * pow(2, tmpPowClose);
    }
    if (balS + balC + 1 <= 2 * n - p.length() - 1) {
        if (k >= tOpen) {
            k -= tOpen;
        }
        else {
            opened.push_back('(');
            gen(p + '(', balC + 1, balS, opened);
            return;
        }
    }
    if (balC > 0 && opened[opened.size() - 1] == '(') {
        if (k >= tClose) {
            k -= tClose;
        }
        else {
            opened.pop_back();
            gen(p + ')', balC - 1, balS, opened);
            return;
        }
    }
    if (balS + balC + 1 <= 2 * n - p.length() - 1) {
        if (k >= tOpen) {
            k -= tOpen;
        }
        else {
            opened.push_back('[');
            gen(p + '[', balC, balS + 1, opened);
            return;
        }
    }
    if (balS > 0 && opened[opened.size() - 1] == '[') {
        if (k >= tClose) {
            k -= tClose;
        }
        else {
            opened.pop_back();
            gen(p + ']', balC, balS - 1, opened);
            return;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> n >> k;
    d = vector<vector<ll>>(100, vector<ll>(100));
    d[0][0] = 1;
    for (int i = 0; i < 2 * n; i++) {
        for (int j = 0; j <= n; j++) {
            if (j + 1 <= n) {
                d[i + 1][j + 1] += d[i][j];
            }
            if (j > 0) {
                d[i + 1][j - 1] += d[i][j];
            }
        }
    }

    gen("", 0, 0, vc());

    return 0;
}
