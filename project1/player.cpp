#include <iostream>
#include <string>
#include <utility>
#include <vector>

#include "player.hpp"

std::vector<std::pair<int, int>> Player::get_walls() { return walls; }

std::pair<int, int> Player::get_pos() { return std::make_pair(x, y); }

void Player::set_pos(std::pair<int, int> pos) {
    x = pos.first;
    y = pos.second;
}

int Player::left_walls_num() { return 10 - walls.size() / 3; }

void Player::move(std::vector<std::vector<std::pair<int, int>>> board_state) {
    char direction;
    std::cout << "Please input the direction you want to move (center is key "
        "\"j\"): ";
    while (1) {
        std::cin >> direction;
        std::pair<int, int> next_pos;
        switch (direction) {
            // 현재 위치는 (x,y) , next_pos 정하기
        ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
        case 'h':
            next_pos = std::make_pair(x, y - 2);
            break;
        case 'k':
            next_pos = std::make_pair(x, y + 2);
            break;
        case 'u':
            next_pos = std::make_pair(x - 2, y);
            break;
        case 'n':
            next_pos = std::make_pair(x + 2, y);
            break;
        case 'y':
            next_pos = std::make_pair(x - 2, y - 2);
            break;
        case 'b':
            next_pos = std::make_pair(x + 2, y - 2);
            break;
        case 'i':
            next_pos = std::make_pair(x - 2, y + 2);
            break;
        case 'm':
            next_pos = std::make_pair(x + 2, y + 2);
            break;
            ////////////////////////////////////////////////////////////

        default:
            std::cout << "Invalid input! Please input again: ";
            continue;
        }

        // 움직임이 board (0~16, 0~16) 을 넘어가지 않도록 하기
        if ((next_pos.first < 0) || (next_pos.first > 16) || (next_pos.second < 0) || (next_pos.second > 16)) {
            std::cout << "Invalid input! Please input again: ";
            continue;
        }

        next_pos = update_next_move(board_state, next_pos, direction);
        // next_pos로 실제로 움직일 수 있으면 움직인 후에 x,y update하기

        ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
        if ((next_pos.first != -1) && (next_pos.second != -1)) {
            x = next_pos.first;
            y = next_pos.second;
            break;
        }

        else {
            ////////////////////////////////////////////////////////////
            std::cout << "Invalid move! Please input again: ";
            continue;
        }
    }
}

std::pair<int, int> Player::update_next_move( // 이동 후 위치를 표시
    std::vector<std::vector<std::pair<int, int>>> board_state,
    std::pair<int, int> next_pos, char direction) {

    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////

    switch (direction) {
    case 'h':
        if (board_state[next_pos.first][next_pos.second + 1].second != 2) { // 벽 존재 X
            if (board_state[next_pos.first][next_pos.second].first == 0) // 상대가 존재 X
                return next_pos;
            else {// 상대 존재
                if (next_pos.second - 2 >= 0) { // 상대를 건너뛴 움직임이 board 좌표 내에 존재할 때
                    if (board_state[next_pos.first][next_pos.second - 1].second != 2) // 한 칸 뛴 벽 존재 X
                        return std::make_pair(next_pos.first, next_pos.second - 2);
                    else return std::make_pair(-1, -1);
                }
                else // 상대를 건너뛴 움직임이 board 좌표 내에 존재 X // only 상대가 자기 쪽 벽에 있을 때
                    return std::make_pair(-1, -1);
            }
        }
        else // 벽 존재
            return std::make_pair(-1, -1);
    case 'k':
        if (board_state[next_pos.first][next_pos.second - 1].second != 2) { // 벽 존재 X
            if (board_state[next_pos.first][next_pos.second].first == 0) // 상대가 존재 X
                return next_pos;
            else {// 상대 존재
                if (next_pos.second + 2 <= 16) { // 상대를 건너뛴 움직임이 board 좌표 내에 존재할 때
                    if (board_state[next_pos.first][next_pos.second + 1].second != 2) // 한 칸 뛴 벽 존재 X
                        return std::make_pair(next_pos.first, next_pos.second + 2);
                    else return std::make_pair(-1, -1);
                }
                else // 상대를 건너뛴 움직임이 board 좌표 내에 존재 X
                    return std::make_pair(-1, -1);
            }
        }
        else // 벽 존재
            return std::make_pair(-1, -1);
    case 'u':
        if (board_state[next_pos.first + 1][next_pos.second].second != 2) { // 벽 존재 X
            if (board_state[next_pos.first][next_pos.second].first == 0) // 상대가 존재 X
                return next_pos;
            else {// 상대 존재
                if (next_pos.first - 2 >= 0) { // 상대를 건너뛴 움직임이 board 좌표 내에 존재할 때
                    if (board_state[next_pos.first - 1][next_pos.second].second != 2) // 한 칸 뛴 벽 존재 X
                        return std::make_pair(next_pos.first - 2, next_pos.second);
                    else return std::make_pair(-1, -1);
                }
                else // 상대를 건너뛴 움직임이 board 좌표 내에 존재 X
                    return std::make_pair(-1, -1);
            }
        }
        else // 벽 존재
            return std::make_pair(-1, -1);
    case 'n':
        if (board_state[next_pos.first - 1][next_pos.second].second != 2) { // 벽 존재 X
            if (board_state[next_pos.first][next_pos.second].first == 0) // 상대가 존재 X
                return next_pos;
            else {// 상대 존재
                if (next_pos.first + 2 <= 16) { // 상대를 건너뛴 움직임이 board 좌표 내에 존재할 때
                    if (board_state[next_pos.first + 1][next_pos.second].second != 2) // 한 칸 뛴 벽 존재 X
                        return std::make_pair(next_pos.first + 2, next_pos.second);
                    else return std::make_pair(-1, -1);
                }
                else // 상대를 건너뛴 움직임이 board 좌표 내에 존재 X
                    return std::make_pair(-1, -1);
            }
        }
        else // 벽 존재
            return std::make_pair(-1, -1);
    case 'y': // 상대가 있어야 함
        if (board_state[next_pos.first + 2][next_pos.second].first != 0) { // 상대가 h에 존재
            if ((next_pos.second == 0) || (board_state[next_pos.first + 2][next_pos.second - 1].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first + 1][next_pos.second].second != 2) && (board_state[next_pos.first + 2][next_pos.second + 1].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1);
        }
        else if (board_state[next_pos.first][next_pos.second + 2].first != 0) { // 상대가 u에 존재
            if ((next_pos.first == 0) || (board_state[next_pos.first - 1][next_pos.second + 2].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first][next_pos.second + 1].second != 2) && (board_state[next_pos.first + 1][next_pos.second + 2].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1);
        }
        else // 상대가 h에도 u에도 없음
            return std::make_pair(-1, -1);
    case 'b':
        if (board_state[next_pos.first - 2][next_pos.second].first != 0) { // 상대가 h에 존재
            if ((next_pos.second == 0) || (board_state[next_pos.first - 2][next_pos.second - 1].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first - 1][next_pos.second].second != 2) && (board_state[next_pos.first - 2][next_pos.second + 1].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1);
        }
        else if (board_state[next_pos.first][next_pos.second + 2].first != 0) { // 상대가 n에 존재
            if ((next_pos.first == 16) || (board_state[next_pos.first + 1][next_pos.second + 2].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first][next_pos.second + 1].second != 2) && (board_state[next_pos.first - 1][next_pos.second + 2].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1);
        }
        else // 상대가 h에도 n에도 없음
            return std::make_pair(-1, -1);
    case 'i':
        if (board_state[next_pos.first + 2][next_pos.second].first != 0) { // 상대가 k에 존재
            if ((next_pos.second == 16) || (board_state[next_pos.first + 2][next_pos.second + 1].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first + 1][next_pos.second].second != 2) && (board_state[next_pos.first + 2][next_pos.second - 1].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1); // 상대 너머 벽이 없음
        }
        else if (board_state[next_pos.first][next_pos.second - 2].first != 0) { // 상대가 u에 존재
            if ((next_pos.first == 0) || (board_state[next_pos.first - 1][next_pos.second - 2].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first][next_pos.second + 1].second != 2) && (board_state[next_pos.first + 1][next_pos.second + 2].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1);
        }
        else // 상대가 k에도 u에도 없음
            return std::make_pair(-1, -1);
    case 'm':
        if (board_state[next_pos.first - 2][next_pos.second].first != 0) { // 상대가 k에 존재
            if ((next_pos.second == 0) || (board_state[next_pos.first - 2][next_pos.second + 1].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first - 1][next_pos.second].second != 2) && (board_state[next_pos.first - 2][next_pos.second - 1].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1);
        }
        else if (board_state[next_pos.first][next_pos.second - 2].first != 0) { // 상대가 n에 존재
            if ((next_pos.first == 0) || (board_state[next_pos.first + 1][next_pos.second - 2].second == 2)) { // 맞은 편에 board boundary거나 벽이 있어야 함
                if ((board_state[next_pos.first][next_pos.second - 1].second != 2) && (board_state[next_pos.first - 1][next_pos.second - 2].second != 2)) // 벽이 두 개가 다 없어야함
                    return next_pos;
                else return std::make_pair(-1, -1); // 둘 중 하나라도 벽이 있으면 오류
            }
            else return std::make_pair(-1, -1);
        }
        else // 상대가 k에도 n에도 없음
            return std::make_pair(-1, -1);
        ////////////////////////////////////////////////////////////
    default:
        return std::make_pair(-1, -1);
    }
}

void Player::place_wall(
    std::vector<std::vector<std::pair<int, int>>> board_state) {
    int wall_x, wall_y;
    char wall_y_char;
    char direction;
    std::cout
        << "Please input the position of the wall coordinate and direction: ";
    while (1) {
        bool valid = true;
        std::cin >> wall_x >> wall_y_char >> direction;

        if ((1 > wall_x || wall_x > 8 || 'A' > wall_y_char ||
            wall_y_char > 'H') ||
            (direction != 'v' && direction != 'h')) {
            valid = false;
            std::cout << "Invalid wall! Please input again: ";
        }
        else {
            wall_x = wall_x * 2 - 1;
            wall_y = (wall_y_char - 'A') * 2 + 1;

            std::pair<int, int> wall_start;
            std::pair<int, int> wall_end;

            ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
            // wall_start, wall_end 좌표 지정
            if (direction == 'v') { // vertical ; row 변함
                wall_start = std::make_pair(wall_x - 1, wall_y);
                wall_end = std::make_pair(wall_x + 1, wall_y);
            }
            else { // horizontal : column 변함
                wall_start = std::make_pair(wall_x, wall_y - 1);
                wall_end = std::make_pair(wall_x, wall_y + 1);
            }
            // if 3개 중 하나라도 이미 wall 설정되어 있으면 valid = false


            if ((board_state[wall_start.first][wall_start.second].second == 2) || (board_state[wall_x][wall_y].second == 2) || (board_state[wall_end.first][wall_end.second].second == 2))
                valid = false;

            if (valid == false) {
                std::cout << "Invalid wall! Please input again: ";
                continue;
            }
            ////////////////////////////////////////////////////////////
            // Create and update board state after adding the new wall
            std::vector<std::vector<std::pair<int, int>>> next_board_state;

            ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
            // next_board_state.assign(board_state.size(), vector<std::pair<int, int>>(board_state.size()));
            next_board_state = board_state;

            next_board_state[wall_x][wall_y].second = 2;
            if (direction == 'v') { // vertical ; row 변함
                next_board_state[wall_x - 1][wall_y].second = 2;
                next_board_state[wall_x + 1][wall_y].second = 2;
            }
            else {
                next_board_state[wall_x][wall_y - 1].second = 2;
                next_board_state[wall_x][wall_y + 1].second = 2;
            }
            ////////////////////////////////////////////////////////////

            // Check if the new wall does not block off a player
            if (check_valid_board_state(next_board_state) == false)
                valid = false;

            if (valid == false) {
                std::cout << "Invalid wall! Please input again: ";
            }
            else if (valid == true) { // 벽 3개 추가
                walls.push_back(wall_start);
                walls.push_back(wall_end);
                walls.push_back(std::make_pair(wall_x, wall_y));
                break;
            }
        }
    }
}

bool Player::check_valid_board_state(
    std::vector<std::vector<std::pair<int, int>>> board_state) {
    // valid[0]: whether player 0 can reach the desination
    // valid[1]: whether player 1 can reach the desination
    bool valid[2] = { false, false };
    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
    int answer_1 = 0;
    int answer_2 = 0;
    if (player_id == 0) { // 오른쪽 => 아래 => 위 => 왼쪽 순으로 검사
        dfs_1(x, y, board_state, answer_1);
        valid[0] = answer_1;
        if (valid[0] == false) return false;
        for (int i = 0; i < board_state.size(); i += 2)
            for (int j = 0; j < board_state[0].size(); j += 2) {
                if (board_state[i][j].first == 2) { // 상대의 위치를 찾고, 그 위치에서 dfs 실행
                    dfs_2(i, j, board_state, answer_2);
                    valid[1] = answer_2;
                    break;
                }
            }
    }

    if (player_id == 1) { // 왼쪽 => 아래 => 위 => 오른쪽 순으로 검사
        for (int i = 0; i < board_state.size(); i += 2)
            for (int j = 0; j < board_state[0].size(); j += 2) {
                if (board_state[i][j].first == 1) { // 상대의 위치를 찾고, 그 위치에서 dfs 실행
                    dfs_1(i, j, board_state, answer_1);
                    valid[0] = answer_1;
                    if (valid[0] == 0) return false;
                }
            }
        dfs_2(x, y, board_state, answer_2);
        valid[1] = answer_2;
    }
    ////////////////////////////////////////////////////////////
    return (valid[0] && valid[1]);
}

void Player::dfs_1(int row, int col, std::vector<std::vector<std::pair<int, int>>> board_state, int& result) {
    int delRow[] = { 0,2,-2,0 };
    int delCol[] = { 2,0,0,-2 };


    if (result == 1) return;
    if (col == 16) { result = 1; return; } // 도착지점 도착 종료
    for (int i = 0; i < 4; i++) { // 현재 노드와 연결되어 있는 칸들을 네 방면으로 탐색
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow <= board_state.size() && ncol >= 0 && ncol <= board_state[0].size() && board_state[nrow][ncol].first != 1) {  // 이동하려는 곳이 방문되지 않았고, board size 안에 있는지 확인
            if (board_state[nrow - (delRow[i] / 2)][ncol - (delCol[i] / 2)].second != 2) { // 벽에 안막혀있으면
                board_state[nrow][ncol].first = 1; // 한 번 도달한 곳은 (1,0)으로 바꾸기
                dfs_1(nrow, ncol, board_state, result);
                if (result == 1) return;
                else {
                    board_state[nrow][ncol].first = 0;
                }
            }
        }
    }

}
void Player::dfs_2(int row, int col, std::vector<std::vector<std::pair<int, int>>> board_state, int& result) {
    int delRow[] = { 0,-2,2,0 };
    int delCol[] = { -2,0,0,2 };

    if (result == 1) return;
    if (col == 0) { result = 1; return; } // 도착지점에 도착
    for (int i = 0; i < 4; i++) { // 네 방면으로 탐색
        int nrow = row + delRow[i];
        int ncol = col + delCol[i];

        if (nrow >= 0 && nrow <= board_state.size() && ncol >= 0 && ncol <= board_state[0].size() && board_state[nrow][ncol].first != 2) {  // 이동하려는 곳이 방문되지 않았고, board size 안에 있는지 확인
            if (board_state[nrow - (delRow[i] / 2)][ncol - (delCol[i] / 2)].second != 2) { // 그 사이에 벽이 없으면!
                board_state[nrow][ncol].first = 2; // 한 번 도달한 곳은 (2,0)으로 바꾸기     
                dfs_2(nrow, ncol, board_state, result);
                if (result == 1) return;
                else {
                    board_state[nrow][ncol].first = 0;
                }
            }
        }
    }
}