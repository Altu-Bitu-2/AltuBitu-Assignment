#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(string s1, string s2) {
	if (s1.length() != s2.length())
		return s1.length() < s2.length();

	int sum_a = 0, sum_b = 0;

	for (int i = 0; i < s1.length(); i++)
		if (s1[i] >= '0' && s1[i] <= '9')
			sum_a += (s1[i] - '0');

	for (int i = 0; i < s2.length(); i++) 
		if (s2[i] >= '0' && s2[i] <= '9')
			sum_b += (s2[i] - '0');
		
	if (sum_a != sum_b)
		return sum_a < sum_b;

	return s1 < s2;
	
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);

	int n;
	cin >> n;
	string arr[51];

	for (int i = 0; i < n; i++)
		cin >> arr[i];
	
	sort(arr, arr + n, cmp);

	for (int i = 0; i < n; i++)
		cout << arr[i] << "\n";

	return 0;
}