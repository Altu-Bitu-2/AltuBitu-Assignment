#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1000001;

int is_prime[MAX] = {0};

void isPN() {
	for (int i = 2; i * i <= MAX; i++) 
		if (is_prime[i] == 0)  // 소수라면 0
			for (int j = i * i; j <= MAX; j += i)
				is_prime[j] = 1; // 소수가 아니면 1
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	int t;
	isPN();
	while (1) {
		cin >> t;
		if (t == 0) break;
		int flag = 0;
		for (int i = 3; i <= t/2 ;i += 2) {
			if (is_prime[i] == 0 && is_prime[t - i] == 0) {
				cout << t << " = " << i << " + " << t - i << "\n";
				flag = 1; break;
			}
		}
		if (flag == 0) cout << "Goldbach's conjecture is wrong.";
	}

	return 0;
}