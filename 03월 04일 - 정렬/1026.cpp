#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n, sum=0;
	cin >> n;

	int A[51], B[51];

	for (int i = 0; i < n; i++)
		cin >> A[i];
	for (int i = 0; i < n; i++)
		cin >> B[i];
	
	sort(A, A + n);
	sort(B, B + n, greater<>());

	for (int i = 0; i < n; i++)
		sum += A[i] * B[i];

	cout << sum << "\n";
	return 0;
}