#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Board {
public:
    Board() {
        for (int i = 0; i < BOARD_LENGTH; i++) {
            std::vector<std::pair<int, int>> row;
            for (int j = 0; j < BOARD_LENGTH; j++) {
                row.push_back(std::make_pair(0, 0));
            }
            board.push_back(row);
        }
        // for red squares position
        int space = BOARD_LENGTH / 4;
        board[space][space] = std::make_pair(0, 1);
        board[space][BOARD_LENGTH - space - 1] = std::make_pair(0, 1);
        board[BOARD_LENGTH - space - 1][space] = std::make_pair(0, 1);
        board[BOARD_LENGTH - space - 1][BOARD_LENGTH - space - 1] =
            std::make_pair(0, 1);
    }
    std::vector<std::vector<std::pair<int, int>>> get_board();
    void print_board();
    void board_update(std::pair<int, int> player_1_pos,
        std::pair<int, int> player_2_pos,
        std::vector<std::pair<int, int>> player_1_walls,
        std::vector<std::pair<int, int>> player_2_walls);
    bool check_win(int player_id, std::pair<int, int> player_pos);
    bool check_red_pixel(std::pair<int, int> player_pos);

private:
    static const int BOARD_LENGTH = 17;
    std::vector<std::vector<std::pair<int, int>>> board;
};
