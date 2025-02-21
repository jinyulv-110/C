//���µ� 10 �����ݣ�ÿ���� 10 ������������������ǵĳ˻���ĩβ�ж��ٸ��㣿

#include <iostream>
#include <vector>

using namespace std;

// ����� (row, col) ���ûʺ��Ƿ�ȫ
bool isSafe(int row, int col, vector<int>& board) {
    for (int i = 0; i < row; ++i) {
        // ���ͬһ��
        if (board[i] == col) return false;
        // ���Խ���
        if (abs(board[i] - col) == abs(i - row)) return false;
    }
    return true;
}

// �ݹ麯����������ÿһ�з��ûʺ�
void solveNQueens(int row, int n, vector<int>& board, vector<vector<string>>& solutions) {
    if (row == n) {
        // �ҵ�һ���⣬����ת��Ϊ���̱�ʾ
        vector<string> solution(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            solution[i][board[i]] = 'Q';
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board)) {
            board[row] = col;  // ���ûʺ�
            solveNQueens(row + 1, n, board, solutions);  // �ݹ鵽��һ��
            board[row] = -1;  // ����
        }
    }
}

// ���������������п��ܵ�N�ʺ�������
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> board(n, -1);  // ��ʼ�����̣�-1��ʾδ���ûʺ�
    solveNQueens(0, n, board, solutions);
    return solutions;
}

int main() {
    int n;
    cout << "Enter the number of queens (N): ";
    cin >> n;

    vector<vector<string>> solutions = solveNQueens(n);

    cout << "Number of solutions: " << solutions.size() << endl;
    for (const auto& solution : solutions) {
        for (const string& row : solution) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
