#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int gcdIter(int n, int m) { 
	if (m > n) swap(m, n);
	while (m) {
		n %= m;
		swap(n, m); 
	}
	return n;
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	string s;
	cin >> s;
	int tmp = s.find(':');
	int n = stoi(s.substr(0, tmp));
	int m = stoi(s.substr(tmp + 1));
	int gcd = gcdIter(n, m);
	cout << n / gcd << ":" << m / gcd << "\n";
	return 0;
}