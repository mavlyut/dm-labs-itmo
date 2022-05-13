#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;

int main() {
    int n;
    cin >> n;
    vector<string> a;
    for (int i = 0; i < pow(2, n); i++) {
        int b;
        string f;
        cin >> f >> b;
        if (b == 1) {
            a.push_back(f);
        }
    }
    if (a.size() == 0) {
        cout << n + 2 << endl;
        cout << "1 " << 1 << endl;
        cout << "2 " << 1 << " " << n + 1 << endl;
        return 0;
    }
    cout << (a.size() + 2) * n - 1 << endl;
    for (int i = 1; i <= n; i++) {
        cout << "1 " << i << endl;
    }
    for (int i = 0; i < a.size(); i++) {
        for (int j = 1; j < n; j++) {
            cout << "2 ";
            if (j == 1) {
                if (a[i][j - 1] == '0') {
                    cout << n + j;
                } else {
                    cout << j;
                }
            } else {
                cout << 3 * n + (n - 1) * (i - 1) + j - 2;
            }
            cout << " ";
            if (a[i][j] == '0') {
                cout << n + j + 1;
            } else {
                cout << j + 1;
            }
            cout << endl;
        }
    }
    int end = 3 * n + (n - 1) * (a.size() - 1) - 2;
    for (int i = 1; i < a.size(); i++) {
        cout << "3 ";
        if (i == 1) {
            cout << 3 * n - 1;
        } else {
            cout << end + i;
        }
        cout << " ";
        cout << 3 * n - 1 + (n - 1) * i << endl;
    }

    return 0;
}