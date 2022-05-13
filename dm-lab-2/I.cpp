/*#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <ctime>
using namespace std;
typedef vector<vector<int>> vvi;

string in, out1, out2;

bool isDeg2(int j) {
	return pow(2, (int)(log(j) / log(2))) == j;
}

class code {
private:
	string s;
	ofstream fout;

public:
	void run() {
		ifstream fin;
		fin.open(in);
		if (!fin.is_open() || !fout.is_open()) {
			throw -1;
		}
		fout.open(out1);
		fin >> s;
		go(1);
	}

	void run(string _s) {
		s = _s;
		go(2);
	}

	void go(int t) {
		int n = s.length(); 
		int m = 1;
		while ((int)(ceil(log(n + m + 1) / log(2))) != m) {
			m++;
		}
		vvi a(m + 2);
		int tmp = 0;
		for (int i = 0; i < m + 2; i++) {
			a[i].resize(n + m + 1);
			if (i == 0) {
				for (int j = 1; j <= n + m; j++) {
					a[i][j] = j;
				}
				continue;
			}
			if (i == 1) {
				for (int j = 1; j <= n + m; j++) {
					if (!isDeg2(j)) {
						a[i][j] = s[tmp++] - 48;
					}
				}
				continue;
			}
			for (int j = 1; j <= n + m; j++) {
				a[i][j] = a[0][j] % 2;
				a[0][j] /= 2;
			}
		}
		for (int j = 0; j < m; j++) {
			int ans = 0;
			for (int i = 1; i <= n + m; i++) {
				ans = (ans + a[1][i] * a[j + 2][i]) % 2;
			}
			a[1][pow(2, j)] = ans;
		}
		for (int i = 1; i <= n + m; i++) {
			(t == 1) ? fout : cout << a[1][i];
		}
		a.clear();
	}
};

class decode {
private:
	string s;
	ofstream fout;

public:
	void run() {
		ifstream fin;
		fin.open(out1);
		fout.open(out2);
		if (!fin.is_open() || !fout.is_open()) {
			throw -1;
		}
		fin >> s;
		go(1);
	}

	void run(string _s) {
		s = _s;
		go(2);
	}

	void go(int t) {
		int n = s.length();
		int m = (int)(ceil(log(n + 1) / log(2)));
		n -= m;
		vvi a(m + 2);
		for (int i = 0; i < m + 2; i++) {
			a[i].resize(n + m + 1);
			if (i == 0) {
				for (int j = 1; j <= n + m; j++) {
					a[i][j] = j;
				}
				continue;
			}
			if (i == 1) {
				for (int j = 1; j <= n + m; j++) {
					a[i][j] = s[j - 1] - 48;
				}
				continue;
			}
			for (int j = 1; j <= n + m; j++) {
				a[i][j] = a[0][j] % 2;
				a[0][j] /= 2;
			}
		}
		int q = 0, tmp = 1;
		for (int j = 0; j < m; j++) {
			int ans = 0;
			for (int i = 1; i <= n + m; i++) {
				ans = (ans + a[1][i] * a[j + 2][i]) % 2;
			}
			q += tmp * ans;
			tmp *= 2;
		}
		for (int j = 1; j <= n + m; j++) {
			if (!isDeg2(j)) {
				if (j == q) {
					(t == 1) ? fout : cout << (char)(97 - s[j - 1]);
				}
				else {
					(t == 1) ? fout : cout << s[j - 1];
				}
			}
		}
		a.clear();
	}
};

void init() {
	srand(time(NULL));
	in   = "C:\\Users\\User\\Desktop\\programming\\filesForHemming\\in.txt";
	out1 = "C:\\Users\\User\\Desktop\\programming\\filesForHemming\\out1.txt";
	out2 = "C:\\Users\\User\\Desktop\\programming\\filesForHemming\\out2.txt";
}

class test {
public:
	void run() {
		ofstream fout;
		fout.open(in);
		if (!fout.is_open()) {
			throw -1;
		}
		int n = rand() % 1 + 10;
		for (int i = 0; i < n; i++) {
			fout << rand() % 2;
		}
	}
};

class checkTest {
public:
	bool run(int cnt) {
		ifstream fin1(in);
		ifstream fin2(out2);
		if (!fin1.is_open() || !fin2.is_open()) {
			throw -1;
		}
		string s1, s2;
		fin1 >> s1;
		fin2 >> s2;
		if (s1 != s2) {
			cout << "Passed " << cnt << " tests. Failed in \n";
			cout << "	expected: " + s1 + '\n';
			cout << "	  actual: " + s2 + '\n';
		}
		return s1 == s2;
	}
};

class Test {
public:
	void run() {
		init();
		int st = clock(), cnt = -1;
		do {
			test().run();
			code().run();
			decode().run();
			cnt++;
			cout << cnt << "\n";
		} while (/*clock() - st < 300000 && checkTest().run(cnt));
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string t;
	cin >> t;
	if (t == "1" || t == "2") {
		string s;
		cin >> s;
		(t == "1") ? code().run(s) : decode().run(s);
	}
	else {
		try {
			Test().run();
		}
		catch (exception e) {
			cout << e.what();
		}
	}
	cout << '\n';

	return 0;
}
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
typedef vector<vector<int>> vvi;

string in, out1, out2;
vector<int> deg2;

bool isDeg2(int j) {
	for (int i : deg2) {
		if (i == j) {
			return true;
		}
	}
	return false;
}

class code {
public:
	void run(string s) {
		int n = s.length();
		int m = 2;
		while ((int)(ceil(log(n + m + 1) / log(2))) != m) {
			m++;
		}
		vvi a(m + 2);
		int tmp = 0;
		for (int i = 0; i < m + 2; i++) {
			a[i].resize(n + m + 1);
			if (i == 0) {
				for (int j = 1; j <= n + m; j++) {
					a[i][j] = j;
				}
				continue;
			}
			if (i == 1) {
				for (int j = 1; j <= n + m; j++) {
					if (!isDeg2(j)) {
						a[i][j] = s[tmp++] - 48;
					}
				}
				continue;
			}
			for (int j = 1; j <= n + m; j++) {
				a[i][j] = a[0][j] % 2;
				a[0][j] /= 2;
			}
		}
		for (int j = 0; j < m; j++) {
			int ans = 0;
			for (int i = 1; i <= n + m; i++) {
				ans = (ans + a[1][i] * a[j + 2][i]) % 2;
			}
			a[1][pow(2, j)] = ans;
		}
		for (int i = 1; i <= n + m; i++) {
			cout << a[1][i];
		}
	}
};

class decode {
public:
	void run(string s) {
		int n = s.length();
		int m = (int)(ceil(log(n + 1) / log(2)));
		n -= m;
		vvi a(m + 2);
		for (int i = 0; i < m + 2; i++) {
			a[i].resize(n + m + 1);
			if (i == 0) {
				for (int j = 1; j <= n + m; j++) {
					a[i][j] = j;
				}
				continue;
			}
			if (i == 1) {
				for (int j = 1; j <= n + m; j++) {
					a[i][j] = s[j - 1] - 48;
				}
				continue;
			}
			for (int j = 1; j <= n + m; j++) {
				a[i][j] = a[0][j] % 2;
				a[0][j] /= 2;
			}
		}
		int q = 0, tmp = 1;
		for (int j = 0; j < m; j++) {
			int ans = 0;
			for (int i = 1; i <= n + m; i++) {
				ans = (ans + a[1][i] * a[j + 2][i]) % 2;
			}
			q += tmp * ans;
			tmp *= 2;
		}
		for (int j = 1; j <= n + m; j++) {
			if (!isDeg2(j)) {
				if (j == q) {
					cout << (char)(97 - s[j - 1]);
				}
				else {
					cout << s[j - 1];
				}
			}
		}
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	deg2.push_back(1);
	for (int i = 0; i < 17; i++) {
		deg2.push_back(deg2[i] * 2);
	}
	int t;
	string s;
	cin >> t >> s;
	if (t == 1) {
		code().run(s);
	}
	else {
		decode().run(s);
	}
	cout << '\n';

	return 0;
}
