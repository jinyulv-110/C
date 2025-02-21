//如下的 10 行数据，每行有 10 个整数，请你求出它们的乘积的末尾有多少个零？

#include <iostream>
#include <vector>

using namespace std;

// 检查在 (row, col) 放置皇后是否安全
bool isSafe(int row, int col, vector<int>& board) {
    for (int i = 0; i < row; ++i) {
        // 检查同一列
        if (board[i] == col) return false;
        // 检查对角线
        if (abs(board[i] - col) == abs(i - row)) return false;
    }
    return true;
}

// 递归函数，尝试在每一行放置皇后
void solveNQueens(int row, int n, vector<int>& board, vector<vector<string>>& solutions) {
    if (row == n) {
        // 找到一个解，将其转换为棋盘表示
        vector<string> solution(n, string(n, '.'));
        for (int i = 0; i < n; ++i) {
            solution[i][board[i]] = 'Q';
        }
        solutions.push_back(solution);
        return;
    }

    for (int col = 0; col < n; ++col) {
        if (isSafe(row, col, board)) {
            board[row] = col;  // 放置皇后
            solveNQueens(row + 1, n, board, solutions);  // 递归到下一行
            board[row] = -1;  // 回溯
        }
    }
}

// 主函数，返回所有可能的N皇后解决方案
vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> solutions;
    vector<int> board(n, -1);  // 初始化棋盘，-1表示未放置皇后
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
