#include <bits/stdc++.h>

using namespace std;

#define DEBUG(x) cerr << #x << ": " << x << "\n"
using i64 = long long;
using u32 = unsigned int;

static constexpr char WHITE = 'W', BLACK = 'B', EMPTY = '.';

static constexpr int BOARD_SIZE = 8;
char board[BOARD_SIZE][BOARD_SIZE];
int main() {
    char player;
    cin >> player;
    assert(player == WHITE || player == BLACK);
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++){
            cin >> board[i][j];
            assert(board[i][j] == WHITE || board[i][j] == BLACK || board[i][j] == EMPTY);
        }
    int answer = 0;
    for (int col = 0; col < BOARD_SIZE; col++) {
        if (player == BLACK) {
            if (board[1][col] == BLACK && board[2][col] == EMPTY && board[3][col] == EMPTY && 
                ((col > 0 && board[3][col - 1] == WHITE) || (col + 1 < BOARD_SIZE && board[3][col + 1] == WHITE)))
                answer++;
        }
        else {
            if (board[BOARD_SIZE - 2][col] == WHITE && board[BOARD_SIZE - 3][col] == EMPTY && board[BOARD_SIZE - 4][col] == EMPTY &&
                ((col > 0 && board[BOARD_SIZE - 4][col - 1] == BLACK) || (col + 1 < BOARD_SIZE && board[BOARD_SIZE - 4][col + 1] == BLACK)))
                answer++;
        }
    }
    cout << answer << "\n";
    return 0;
}
