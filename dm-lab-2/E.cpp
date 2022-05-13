#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> dict;
    string s, buf;
    cin >> s;
    int ind = 27;
    for (int i = 0; i < 26; i++) {
        buf = char(i + 'a');
        dict[buf] = 1 + i;
    }
    buf = "";
    for (char i : s) {
        if (dict[buf + i] != 0) {
            buf += i;
        } else {
            cout << dict[buf] - 1 << " ";
            dict[buf + i] = ind++;
            buf = i;
        }
    }
    cout << dict[buf] - 1;

    return 0;
}
