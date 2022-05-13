#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<long long> a(n);
    vector<int> f(pow(2, n));
    for (int i = 0; i < f.size(); i++) {
        f[i] = -1;
    }
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long b;
    cin >> b;
    for (int i = 0; i < 33; i++) {
        int ans = 0;
        for (int j = 0; j < n; j++) {
            ans = 2 * ans + a[j] % 2;
            a[j] /= 2;
        }
        if (f[ans] == -1 || f[ans] == b % 2) {
            f[ans] = b % 2;
            b /= 2;
        }
        else {
            cout << "Impossible";
            return 0;
        }
    }
    int cnt1 = 0;
    for (int i : f) {
        cnt1 += (i == 1);
    }
    if (cnt1 == 0) {
        cout << "1&~1";
        return 0;
    } 
    int num = 0;
    for (int i = 0; i < pow(2, n); i++) {
        if (f[i] == 1) {
            if (cnt1 > 1) {
                if (num > 0) {
                    cout << "|";
                }
                cout << "(";
            }
            int q = i;
            for (int k = n; k > 0; k--) {
                if (q % 2 == 0) {
                    cout << "~";
                }
                cout << k;
                if (k != 1) {
                    cout << "&";
                }
                q /= 2;
            }
            if (cnt1 > 1) {
                cout << ")";
            }
            num++;
        }
    }

    return 0;
}