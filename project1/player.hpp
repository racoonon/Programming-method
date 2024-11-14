#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Player {
public:
    Player() {}
    Player(int id_, int x_, int y_) {
        player_id = id_;
        x = x_;
        y = y_;
    }
    int left_walls_num();
    std::pair<int, int> get_pos();
    void set_pos(std::pair<int, int> pos);
    std::vector<std::pair<int, int>> get_walls();
    void move(std::vector<std::vector<std::pair<int, int>>> board_state);
    std::pair<int, int>
        update_next_move(std::vector<std::vector<std::pair<int, int>>> board_state,
            std::pair<int, int> next_pos, char direction);
    void place_wall(std::vector<std::vector<std::pair<int, int>>> board_state);
    bool check_valid_board_state(
        std::vector<std::vector<std::pair<int, int>>> board_state);

    void dfs_1(int row, int col, std::vector<std::vector<std::pair<int, int>>> board_state, int& result);
    void dfs_2(int row, int col, std::vector<std::vector<std::pair<int, int>>> board_state, int& result);

private:
    int player_id;
    int x;
    int y;
    std::vector<std::pair<int, int>> walls;
};
