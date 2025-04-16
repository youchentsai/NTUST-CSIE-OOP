#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

const int R = 6, C = 6;
const int PR = R + 2, PC = C + 2; // padded board dimensions
// Directions: 0: up, 1: right, 2: down, 3: left.
int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};

char board[PR][PC]; // padded board; border cells are '0' (empty)

// Check if the path from (sy, sx) to (ty, tx) is connectable with at most 2 turns.
// Coordinates are in the padded board (1..6 are the original board cells).
bool canConnect(int sy, int sx, int ty, int tx) {
    // visited[y][x][dir] = minimal turns taken to reach (y,x) with direction dir.
    int visited[PR][PC][4];
    for (int i = 0; i < PR; i++)
        for (int j = 0; j < PC; j++)
            for (int k = 0; k < 4; k++)
                visited[i][j][k] = 1e9;

    // state: (y, x, direction, turns)
    struct State {
        int y, x, dir, turns;
    };
    queue<State> q;

    // From the starting cell, try all four directions.
    for (int d = 0; d < 4; d++) {
        int ny = sy + dy[d], nx = sx + dx[d];
        if (ny < 0 || ny >= PR || nx < 0 || nx >= PC)
            continue;
        // We can move if the next cell is empty or is the target cell.
        if ((ny == ty && nx == tx) || board[ny][nx] == '0') {
            visited[ny][nx][d] = 0;
            q.push({ny, nx, d, 0});
        }
    }

    while (!q.empty()) {
        auto cur = q.front();
        q.pop();

        // If we've reached the target cell, return true.
        if (cur.y == ty && cur.x == tx)
            return true;

        // Continue moving in all four possible directions.
        for (int d = 0; d < 4; d++) {
            int nt = cur.turns + ((d == cur.dir) ? 0 : 1);
            if (nt > 2)
                continue; // cannot exceed 2 turns.
            int ny = cur.y + dy[d], nx = cur.x + dx[d];
            // Move in the chosen direction step by step.
            while (ny >= 0 && ny < PR && nx >= 0 && nx < PC && ((ny == ty && nx == tx) || board[ny][nx] == '0')) {
                if (nt < visited[ny][nx][d]) {
                    visited[ny][nx][d] = nt;
                    q.push({ny, nx, d, nt});
                }
                // If we reached target, we can return true immediately.
                if (ny == ty && nx == tx)
                    return true;
                ny += dy[d];
                nx += dx[d];
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Initialize the padded board. The border cells are marked as '0' (empty).
    for (int i = 0; i < PR; i++) {
        for (int j = 0; j < PC; j++) {
            board[i][j] = '0';
        }
    }

    // Read the 6x6 board.
    for (int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            char ch;
            cin >> ch;
            board[i][j] = ch;
        }
    }

    // Process pairs until end-of-input.
    // The coordinates are given as (pos1.x, pos1.y, pos2.x, pos2.y).
    // Note: x corresponds to column and y to row. Our padded board indices:
    // (row, col) = (input_y + 1, input_x + 1)
    int x1, y1, x2, y2;
    while (cin >> x1 >> y1 >> x2 >> y2) {
        // Convert to padded board coordinates.
        int sy = y1 + 1, sx = x1 + 1;
        int ty = y2 + 1, tx = x2 + 1;

        // Check basic conditions: same tile and nonempty.
        if (sy == ty && sx == tx) {
            cout << "bad pair"
                 << "\n";
            continue;
        }
        if (board[sy][sx] == '0' || board[ty][tx] == '0') {
            cout << "bad pair"
                 << "\n";
            continue;
        }
        if (board[sy][sx] != board[ty][tx]) {
            cout << "bad pair"
                 << "\n";
            continue;
        }

        // Check if there is a legal path.
        if (canConnect(sy, sx, ty, tx)) {
            // If legal, remove the tiles.
            board[sy][sx] = board[ty][tx] = '0';
            cout << "pair matched"
                 << "\n";
        } else {
            cout << "bad pair"
                 << "\n";
        }
    }

    return 0;
}