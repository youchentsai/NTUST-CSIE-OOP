#include<iostream>
#include<vector>
#include<string>

bool is_error = false;

bool isOutOfRange(int x, int y, int width, int height) {
	return x < 0 || x >= width || y < 0 || y >= height;
}

//squre
void draw_square(std::vector<std::vector<char>>& draw_board, int width, int x, int y) {
	using namespace std;
	int height = draw_board.size(), board_width = draw_board[0].size();
	if (isOutOfRange(x, y, board_width, height) || isOutOfRange(x + width - 1, y + width - 1, board_width, height)) {
		cout << "Out of range." << endl;
		is_error = true;
		return;
	}
	for (int i = y; i < width + y; i++) {
		for (int j = x; j < width + x; j++) {
			draw_board[i][j] = 'X';
		}
	}
}
//triango
void draw_triango(std::vector<std::vector<char>>& draw_board, int width, int x, int y, std::string dir) {
	using namespace std;
	int height = draw_board.size(), board_width = draw_board[0].size();
	if (isOutOfRange(x, y, board_width, height)) {
		cout << "Out of range." << endl;
		is_error = true;
		return;
	}
	if (dir == "LU") {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j <= i; j++) {
				if (isOutOfRange(x - j, y - (width - 1 - i), board_width, height)) {
					cout << "Out of range." << endl;
					is_error = true;
					return;
				}
				draw_board[y - (width - 1 - i)][x - j] = 'X';
			}
		}
	}
	else if (dir == "LD") {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j <= i; j++) {
				if (isOutOfRange(x - j, y + (width - 1 - i), board_width, height)) {
					cout << "Out of range." << endl;
					is_error = true;
					return;
				}
				draw_board[y + (width - 1 - i)][x - j] = 'X';
			}
		}
	}
	else if (dir == "RU") {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j <= i; j++) {
				if (isOutOfRange(x + j, y - (width - 1 - i), board_width, height)) {
					cout << "Out of range." << endl;
					is_error = true;
					return;
				}
				draw_board[y - (width - 1 - i)][x + j] = 'X';
			}
		}
	}
	else if (dir == "RD") {
		for (int i = 0; i < width; i++) {
			for (int j = 0; j <= i; j++) {
				if (isOutOfRange(x + j, y + (width - 1 - i), board_width, height)) {
					cout << "Out of range." << endl;
					is_error = true;
					return;
				}
				draw_board[y + (width - 1 - i)][x + j] = 'X';
			}
		}
	}
}
//line
void draw_line(std::vector<std::vector<char>>& draw_board, int x1, int y1, int x2, int y2) {
	using namespace std;
	int height = draw_board.size(), board_width = draw_board[0].size();
	if (isOutOfRange(x1, y1, board_width, height) || isOutOfRange(x2, y2, board_width, height)) {
		cout << "Out of range." << endl;
		is_error = true;
		return;
	}
	//Bresenham's Line Algorithm
	int dx = abs(x2 - x1), dy = abs(y2 - y1);
	int sx = (x1 < x2) ? 1 : -1;
	int sy = (y1 < y2) ? 1 : -1;
	int err = dx - dy;

	while (true) {
		draw_board[y1][x1] = 'X';
		if (x1 == x2 && y1 == y2) break;
		int e2 = 2 * err;
		if (e2 > -dy) { err -= dy; x1 += sx; }
		if (e2 < dx) { err += dx; y1 += sy; }
	}
}

int main() {
	using namespace std;
	while (true) {
		int draw_board_length = 0, draw_board_width = 0;
		cin >> draw_board_length >> draw_board_width;
		vector<vector<char>> drawBoard(draw_board_width, vector<char>(draw_board_length, '*'));
		string command = "";
		while (cin >> command) {
			if (command == "EXIT")
				return 0;
			int x = 0, y = 0, width = 0;

			if (command == "S") {
				cin >> width >> x >> y;
				draw_square(drawBoard, width, x, y);
			}
			else if (command == "L") {
				int x2 = 0, y2 = 0;
				cin >> x >> y >> x2 >> y2;
				draw_line(drawBoard, x, y, x2, y2);
			}
			else if (command == "T") {
				string direction = "";
				cin >> width >> x >> y >> direction;
				draw_triango(drawBoard, width, x, y, direction);
			}
			if (is_error) {
				is_error = false;
				cout << endl;
				continue;
			}
			for (int i = 0; i < drawBoard.size(); i++) {
				for (int j = 0; j < drawBoard[0].size(); j++) {
					cout << drawBoard[i][j];
				}
				cout << endl;
			}
			cout << endl;
		}
	}
	return 0;
}