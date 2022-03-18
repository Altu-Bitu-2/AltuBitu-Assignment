#include <iostream>
#include <stack>
using namespace std;

stack<int> s[300001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n, p, line, pret, cnt=0;
	cin >> n >> p;
	
	for (int i = 0; i < n; i++) {
		cin >> line >> pret; 
		if (!s[line].empty()) { 
			while (!s[line].empty() && s[line].top() > pret ) { 
				s[line].pop(); 
				cnt++;
			}
			if (!s[line].empty() && s[line].top() == pret) 
				continue;
			s[line].push(pret);
			cnt++; 
		}
		else {
			s[line].push(pret);
			cnt++; 
		}
	}

	cout << cnt << "\n";

	return 0;
}