#include <iostream>
#include <vector>
using namespace std;

bool trans(vector<vector<int>> a) {
    int n = a.size();
    bool f = true;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 1) {
                for (int k = 0; k < n; k++) {
                    if (i != j && i != k && j != k && a[j][k] == 1) f &= a[i][k];
                    if (!f) break;
                }
            }
            if (!f) break;
        }
        if (!f) break;
    }
    return f;
}

int main() {
    int n, i, j, tmp;
    cin >> n;
    vector<vector<int>> a(n), b(n), c(n);
    bool refl =  true, antiRefl = true, simm = true, antiSimm = true;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> tmp;
            a[i].push_back(tmp);
            c[i].push_back(0);
            if (i == j) {
                refl &= (tmp == 1);
                antiRefl &= (tmp == 0);
            } else if (i > j) {
                simm &= (tmp == a[j][i]);
                antiSimm &= (tmp + a[j][i] <= 1);
            }
        }
    }
    cout << refl << " " << antiRefl << " " << simm << " " << antiSimm << " " << trans(a) << endl;
    refl = true; antiRefl = true; simm = true; antiSimm = true;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cin >> tmp;
            b[i].push_back(tmp);
            if (i == j) {
                refl &= (tmp == 1);
                antiRefl &= (tmp == 0);
            } else if (i > j) {
                simm &= (tmp == b[j][i]);
                antiSimm &= (tmp + b[j][i] <= 1);
            }
        }
    }
    cout << refl << " " << antiRefl << " " << simm << " " << antiSimm << " " << trans(b) << endl;

    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                c[i][k] |= a[i][j] & b[j][k];
            }
        }
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << c[i][j] << " ";
        cout << endl;
    }

    return 0;
}