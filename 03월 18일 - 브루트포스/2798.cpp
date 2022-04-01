#include <iostream>
using namespace std;

int N, M;
int arr[101];
int answer = 0;

void card() {
	for (int i = 0; i < N - 2 ; i++) 
		for (int j = i + 1; j < N - 1; j++) 
			for (int k = j + 1; k < N; k++) 
				if (arr[i] + arr[j] + arr[k] <= M) 
					answer = max(answer, arr[i] + arr[j] + arr[k]);
}

int main() {

	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	card();

	cout << answer << "\n";

	return 0;
}
