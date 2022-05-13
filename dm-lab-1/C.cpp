#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class FunctionalElement {
private:
	int m;
	vector<int> Enters;
	vector<int> F;
	int depth;
	int definition;

public:
	void inElement(int m, vector<int> Enters, vector<int> F, int depth) {
		this->m = m;
		this->Enters = Enters;
		this->F = F;
		this->depth = depth;
	}

	int getM() {
		return m;
	}

	int getDepth() {
		return depth;
	}

	int getDefinition() {
		return definition;
	}

	vector<int> getEnters() {
		return Enters;
	}

	vector<int> getF() {
		return F;
	}

	void setDefinition(int x) {
		definition = x;
	}

	void setDefinition(int x, int i) {
		definition = F[x];
	}
};

int main() {
	int n, x = 0;
	cin >> n;
	vector<FunctionalElement> a(n);
	for (int i = 0; i < n; i++) {
		int m, depth = 0;
		cin >> m;
		vector<int> ent, f;
		for (int j = 0; j < m; j++) {
			int qw;
			cin >> qw;
			ent.push_back(qw - 1);
			depth = max(depth, a[ent[j]].getDepth());
		}
		if (m == 0) {
			x++;
		} else {
			depth++;
			for (int j = 0; j < pow(2, m); j++) {
				int l;
				cin >> l;
				f.push_back(l);
			}
		}
		a[i].inElement(m, ent, f, depth);
	}
	cout << a[n - 1].getDepth() << endl;
	for (int i = 0; i < pow(2, x); i++) {
		int s = i, k = pow(2, x - 1);
		for (int j = 0; j < n; j++) {
			if (a[j].getM() == 0) {
				a[j].setDefinition(s / k % 2);
				s %= k;
				k /= 2;
			} else {
				int w = 0;
				for (int k : a[j].getEnters()) {
					w = w * 2 + a[k].getDefinition();
				}
				a[j].setDefinition(w, 1);
			}
		}
		cout << a[n - 1].getDefinition();
	}

	return 0;
}