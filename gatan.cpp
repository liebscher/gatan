// my first program in C++
#include <iostream>
#include <cstdlib>
#include <time.h>

std::string viz_row (int width, char rowTiles[], int size) {
    std::string viz = "";
    int q = width - size + 1;
    while (q > 0) {
        viz += "__";
        q--;
    }

    for (int w = 0; w < size; w++) {
        viz += "_";
        viz += rowTiles[w];
        viz += "__";
    }

    int e = width - size + 1;
    while (e > 0) {
        viz += "__";
        e--;
    }

    return viz;
}

std::string build_row (int row, int max_rows, char tiles[]) {
    if (max_rows % 2 != 1) {
        throw 1;
    }

    int half = (max_rows-1) / 2;

    if (row < half && row > 1) {

        int start = 0;
        for (int i = 1; i <= row; i++) {
            start += i;
        }

        char rowTiles [row+1];
        for (int j = 0; j < row + 1; j++) {
            rowTiles[j] = tiles[start + j];
        }

        return viz_row(half, rowTiles, row + 1);

    } else if (row == half)
    {
        int start = 0;
        for (int i = 1; i <= row; i++) {
            start += i;
        }

        char rowTiles [row+1];
        for (int j = 0; j < row + 1; j++) {
            rowTiles[j] = tiles[start + j];
        }
        return viz_row(half, rowTiles, row + 1);

    } else if (row > half && row < max_rows - 2)
    {
        int start = (half + 1) * (half / 2) + 1;
        for (int i = row - half; i > 0; i--) {
            start += half - i + 1;
        }

        char rowTiles [max_rows - row];

        for (int j = 0 ; j < max_rows - row; j++) {
            rowTiles[j] = tiles[start + j];
        }

        return viz_row(half, rowTiles, max_rows - row);

    }
    
    return "";
}

void shuffle (char arr[], int n) {
    // Fisher-Yates shuffle
    for (int i = n-1; i > 0; i--) {
        int j = rand() % n;
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main() {

    const char WOOD = 'D';
    const char WHEAT = 'W';
    const char SHEEP = 'S';
    const char BRICK = 'B';
    const char ROCK = 'R';

    const int nElements = 19;
    char board[19] = 
        { WOOD,  WOOD,  WOOD,  WOOD, 
          SHEEP, SHEEP, SHEEP, SHEEP, 
          WHEAT, WHEAT, WHEAT, WHEAT, 
          BRICK, BRICK, BRICK, 
          ROCK,  ROCK,  ROCK,
          'X' };

    srand (time(NULL));
    shuffle(board, nElements);

    char padded_board[19 + 3 + 3];
    char BLANK = '.';
    for (int p = 0; p < 19 + 3 + 3; p++) {
        if (p < 3 || p >= 19 + 3) {
            padded_board[p] = BLANK;
        } else {
            padded_board[p] = board[p - 3];
        }
        // std::cout << padded_board[p];
    }

    // std::cout << "\n";

    int rows = 9;

    for (int i = 0; i < rows; i++) {
        try {
            std::cout << build_row(i, rows, padded_board);
            std::cout << '\n';
        } catch(int e) {
            std::cout << "An exception occurred: " + std::to_string(e) + "\n";
            return 0;
        }
    }

    std::cout << '\n';


}
