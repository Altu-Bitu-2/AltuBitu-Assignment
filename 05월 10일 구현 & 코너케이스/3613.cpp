#include <iostream>

using namespace std;

bool isCpp(string str) { // c++ 형식인지 반환하는 함수
    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) { // 대문자가 있으면 안 됨
            return false;
        
        }
        if (str[i] == '_' && (i == 0 || i == str.size() - 1 || str[i - 1] == '_')) {
        //  첫 or 마지막 글자가 '_' 또는 '_'가 연속 등장
            return false; // c++ 형식 아니므로 false 리턴
        }
    
    }
    return true; 

}

bool isJava(string str) {
    return !isupper(str[0]) && str.find('_') == string::npos;
    // 첫 글자가 대문자거나, '_'가 있으면 안 됨
}

string toCpp(string str) { // java-> cpp
    string result;

    for (int i = 0; i < str.size(); i++) {
        if (isupper(str[i])) {
            result += '_'; // 대문자라면 앞에 _ 삽입
        }
        result += tolower(str[i]); // 소문자로 바꿔서 넣기
    }
    return result; // cpp 로 변환한 스트링 반환
}

string toJava(string str) { // cpp =>java
    string result;

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '_') { //'_' 라면 
            result += toupper(str[i + 1]); // 그 다음 글자를 대문자로 바꿔서 삽입 
            i++; // 인덱스 증가
            continue; // 다음으로 넘어가기
        }
        result += str[i]; //나머지 글자는 그냥 삽입
    }
    return result; // java로 변환한 스트링 반환
}



int main() {
    string str;

    cin >> str;

    bool is_cpp = isCpp(str);
    bool is_java = isJava(str);

    if (is_cpp && is_java) { //두 형식에 모두 부합하면 그냥 출력
        cout << str;
    }
    else if (is_cpp) { //c++ 형식이라면 java로 바꿔서 출력
        cout << toJava(str);
    }
    else if (is_java) { //java 형식이라면 c++로 바꿔서 출력
        cout << toCpp(str);
    }
    else { //둘 다 아니라면 에러
        cout << "Error!";
    }
    return 0;

}