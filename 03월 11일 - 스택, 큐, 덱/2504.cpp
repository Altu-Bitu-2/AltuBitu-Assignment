#include <iostream>
#include <stack>
using namespace std;

string s;


int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> s;
	stack <char> st;
	int answer = 0, temp = 1;

	for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            temp *= 2;
            st.push('(');
        }
        else if (s[i] == '[') {
            temp *= 3;
            st.push('[');
        }
        else if (s[i] == ')') {
            if (st.empty() || st.top() != '(') {   //올바르지 못한 괄호열
                answer = 0;
                break;
            }
            if (s[i - 1] == '(') {
                answer += temp;
                temp /= 2;
                st.pop();
            }
            else {
                temp /= 2;
                st.pop();
            }
        }
        else if (s[i] == ']') {
            if (st.empty() || st.top() != '[') {   //올바르지 못한 괄호열
                answer = 0;
                break;
            }
            if (s[i - 1] == '[') {
                answer += temp;
                temp /= 3;
                st.pop();
            }
            else {
                temp /= 3;
                st.pop();
            }
        }
	}
	if (!st.empty()) answer = 0; // 스택이 비어있지 않다면 올바르지 못한 괄호열
	cout << answer << "\n";

	return 0;
}