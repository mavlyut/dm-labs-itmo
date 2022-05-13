#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef vector<int> vi;

bool f0(int s, string f) {
    return f[0] == '0';
}

bool f1(int s, string f) {
    return f[s - 1] == '1';
}

bool fs(int s, string f) {
    for (int i = 0; i < s; i++) {
        if (f[i] == f[s - i - 1]) {
            return false;
        }
    }
    return true;
}

bool domin(int i, int j) {
    while (i > 0 || j > 0) {
        if (i % 2 < j % 2) {
            return false;
        }
        i /= 2;
        j /= 2;
    }
    return true;
}

bool fm(int s, string f) {
    for (int i = 0; i < s; i++) {
        for (int j = 0; j < s; j++) {
            if (domin(i, j) && f[i] < f[j]) {
                return false;
            }
        }
    }
    return true;
}

int g(char s) {
    if (s == '0') {
        return 0;
    } else {
        return 1;
    }
}

bool fl(int s, string f) {
    vi a(s);
    for (int x = 0; x < s; ++x) {
        a[x] = g(f[0]);
        for (int y = x; y > 0; y = (y - 1) & x) {
            a[x] ^= g(f[y]);
        }
        if (x != 0 && x != 1 && x != 2 && x != 4 && x != 8 && x != 16 && x != 32 && a[x] == 1) {
            return false;
        }
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    bool r[5] = {false, false, false, false, false}; //01SML
    while (n--) {
        int s;
        string f;
        cin >> s >> f;
        s = pow(2, s);
        if (!f0(s, f)) r[0] = true;
        if (!f1(s, f)) r[1] = true;
        if (!fs(s, f)) r[2] = true;
        if (!fm(s, f)) r[3] = true;
        if (!fl(s, f)) r[4] = true;
    }
    if (r[0] && r[1] && r[2] && r[3] && r[4]) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}