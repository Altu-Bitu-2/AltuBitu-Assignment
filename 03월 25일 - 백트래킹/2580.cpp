#include <iostream>
using namespace std;

int sudoku[10][10];

bool check_row[10][10]; 
bool check_col[10][10]; 
bool check_square[10][10]; 

int get_square(int row, int col){
    return (row/3)*3 + (col/3);
}

void print(){
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cout << sudoku[i][j] << ' ';
        }
        cout << '\n';
    }
}

bool solve(int num){
    if(num == 81) { // 마지막이라면 출력
        print();
        return true;
    }
    
    int x = num / 9; // 행 
    int y = num % 9; // 열
    
    if(sudoku[x][y] != 0){
        return solve(num+1);
    } else {
        for(int i=1; i<=9; i++){
            if(!check_row[x][i] && !check_col[y][i] && !check_square[get_square(x, y)][i]){
                check_row[x][i] = true;
                check_col[y][i] = true;
                check_square[get_square(x, y)][i] = true;
                sudoku[x][y] = i;
                
                if(solve(num+1)){
                    return true;
                }
                check_row[x][i] = false; // 다시 돌려놓기
                check_col[y][i] = false;
                check_square[get_square(x, y)][i] = false;
                sudoku[x][y] = 0;
            }
        }
    }
    
    return false;
}

int main(void){
    
    for(int i=0; i<9; i++){
        for(int j=0; j<9; j++){
            cin >> sudoku[i][j];
            
            // 0이 아니라면 행, 열, 3x3에 값 체크하기
            if(sudoku[i][j] != 0){
                check_row[i][sudoku[i][j]] = true;
                check_col[j][sudoku[i][j]] = true;
                check_square[get_square(i, j)][sudoku[i][j]] = true;
            }
        }
    }
    
    // 0번 칸부터 채우기 시작
    solve(0);
    return 0;
}