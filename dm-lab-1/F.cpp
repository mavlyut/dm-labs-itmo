#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

vpii getAllIndexOfSingle(vvi& a, int n, int k) {
    vpii ans;
    for (int i = 0; i < k; i++) {
        int num = 0, num1 = 0, index;
        for (int j = 0; j < n; j++) {
            if (a[i][j] == 0 || a[i][j] == 1) {
                num++;
                index = j;
            } else if (a[i][j] == 2) {
                num1++;
            }
        }
        if (num == 1 && num1 == 0) {
            ans.emplace_back(i, index);
        }
    }
    return ans;
}

string khorn(vvi& a, int n, int k) {
    vpii indexOfSingle = getAllIndexOfSingle(a, n, k);
    if (indexOfSingle.empty()) {
        return "NO";
    }
    for (pii index : indexOfSingle) {
        int add = (a[index.first][index.second] == 1);
        for (int i = 0; i < k; i++) {
            if (a[i][index.second] == 0) {
                a[i][index.second] = 2 + add;
            } else if (a[i][index.second] == 1) {
                a[i][index.second] = 3 - add;
            }
            bool isEmpty = true;
            int numOfZero = 0;
            for (int j = 0; j < n; j++) {
                if (a[i][j] != -1) {
                    isEmpty = false;
                }
                if (a[i][j] == -1 || a[i][j] == 3) {
                    numOfZero++;
                }
            }
            if (numOfZero == n && !isEmpty) {
                return "YES";
            }
        }
    }
    return khorn(a, n, k);
}

void solve() {
    vector<vector<int>> a;
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        vector<int> tmp(n);
        for (int j = 0; j < n; j++) {
            cin >> tmp[j];
        }
        a.push_back(tmp);
    }
    cout << khorn(a, n, k);
}

int main() {
    solve();

    return 0;
}