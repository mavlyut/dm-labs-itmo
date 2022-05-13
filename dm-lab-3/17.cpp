#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef long long ll;
ifstream fin;
 
ostream& operator<< (ostream& out, vi& a) {
    for (int i = 0; i < a.size(); i++) {
        out << i << " " << a[i] << endl;
    }
    return out;
}
 
ostream& operator<< (ostream& out, vector<pii>& a) {
    for (int i = 0; i < a.size(); i++) {
        out << i << " " << a[i].first << " " << a[i].second << endl;
    }
    return out;
}
 
int n;
ll k;
vector<vector<ll>> d;
 
void gen(string p, int bal) {
    if (p.length() == 2 * n) {
        if (k == 0) {
            cout << p;
            return;
        }
        k--;
    }
    if (bal + 1 <= 2 * n - p.length() - 1) {
        ll t = d[2 * n - p.length() - 1][bal + 1];
        if (k >= t) {
            k -= t;
        }
        else {
            gen(p + "(", bal + 1);
            return;
        }
    }
    if (bal > 0) {
        ll t = d[2 * n - p.length() - 1][bal - 1];
        if (k >= t) {
            k -= t;
        }
        else {
            gen(p + ")", bal - 1);
            return;
        }
    }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    fin.open("input.txt");
 
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
    gen("", 0);
 
    return 0;
}
