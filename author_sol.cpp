#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tt;
	cin >> tt;
	while (tt--) {
		string s;
		cin >> s;
		vector<int> d(3);
		// check if the first and last letters are the same (by find their numerical value)
		int x = s[0] - 'A';
		int y = s.back() - 'A';
		if (x == y) {
			// if yes, then output NO and continue the while-loop
			cout << "NO\n";
			continue;
		}
		// otherwise, set the corresponding letters with the numerical equivalent:
		// 1 is equal to the opening bracket and -1 is equal to the closing bracket
		d[x] = 1; d[y] = -1;
		// check if the occurrences of the opening bracket is exactly half
		if (count(s.begin(), s.end(), 'A' + x) == (int) s.size() / 2) {
			// if yes, then set the remaining letter as the closing bracket (or equal to -1)
			d[3 ^ x ^ y] = -1;
		} else {
			// 'n' = string size
			// otherwise, set the remaining letter as the opening bracket (to achieve 'n' / 2)
			d[3 ^ x ^ y] = 1;
		}
		int bal = 0;
		bool checker = true;
		for (char c : s) {
			// calculate the summation of all elements
			bal += d[c - 'A'];
			if (bal < 0) {
				// if 'bal' is less than 0, then set 'checker' to false and break 
				// the loop (the sequence is not balanced)
				checker = false;
				break;
			}
		}
		// check if 'checker' is equal to true and 'bal' is equal to 0
		cout << (checker && bal == 0 ? "YES" : "NO") << '\n';
	}
	return 0;
}
