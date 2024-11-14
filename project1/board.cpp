#include <algorithm>
#include <iostream>
#include <queue>
#include <stdio.h>
#include <string>
#include <utility>
#include <vector>

#include "board.hpp"
#define COLOR_RED "\033[31m"    /* Red */
#define COLOR_YELLOW "\033[33m" /* Yellow */
#define COLOR_BLUE "\033[34m"   /* Blue */
#define COLOR_GREEN "\033[32m"  /* Green */
#define COLOR_DEFAULT "\033[0m" /* Default */

std::vector<std::vector<std::pair<int, int>>> Board::get_board() {
    return board;
}

void Board::print_board() {
    // Visualizing the board, do not modify this function
    std::cout << "  ";
    printf("%5c", 65);
    for (int i = 1; i < BOARD_LENGTH / 2; i++) {
        printf("%6c", i + 65); // char을 우측정렬로 5개 출력
    }
    std::cout << std::endl;
    for (int i = 0; i < BOARD_LENGTH; i++) {
        if (i % 2 == 1)// 홀수; 벽 놓는 곳
            printf("%2d", (i + 1) / 2); // %2d : 뒤에 저장된 숫자를 빈칸 2개에 그대로 출력하는 것
        else
            printf("  ");
        for (int j = 0; j < BOARD_LENGTH; j++) {
            if (i % 2 == 1 || j % 2 == 1) { // (홀수, 홀수) (홀수, 짝수) (짝수, 홀수) 벽 놓는 공간
                if (board[i][j].second == 0) { // 벽 X 빨간 공간 X
                    std::cout << "   ";
                }
                else if (board[i][j].second == 2) { // 벽 O 빨간 공간 X
                    std::cout << COLOR_BLUE << " / " << COLOR_DEFAULT;
                }
            }
            else { // (짝수, 짝수)
                if (board[i][j].first == 0) { // 둘 다 없음
                    if (board[i][j].second == 1) // 빨간 공간
                        std::cout << COLOR_RED << " O " << COLOR_DEFAULT;
                    else // 아무것도 없음
                        std::cout << " O ";
                }
                else if (board[i][j].first == 1) { // Player 1
                    std::cout << COLOR_YELLOW << " X " << COLOR_DEFAULT;
                }
                else if (board[i][j].first == 2) { // Player 2
                    std::cout << COLOR_GREEN << " X " << COLOR_DEFAULT;
                }
            }
        }
        std::cout << std::endl;
    }
}


void Board::board_update(std::pair<int, int> player_1_pos,
    std::pair<int, int> player_2_pos,
    std::vector<std::pair<int, int>> player_1_walls,
    std::vector<std::pair<int, int>> player_2_walls) {

    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
    for (int i = 0; i < BOARD_LENGTH; i++)
        for (int j = 0; j < BOARD_LENGTH; j++)
            board[i][j].first = 0;
    board[player_1_pos.first][player_1_pos.second].first = 1;
    board[player_2_pos.first][player_2_pos.second].first = 2;
    for (int i = 0; i < player_1_walls.size(); i++) {
        board[player_1_walls[i].first][player_1_walls[i].second].second = 2;
    }
    for (int i = 0; i < player_2_walls.size(); i++) {
        board[player_2_walls[i].first][player_2_walls[i].second].second = 2;
    }
    ///////////////// IMPLEMENT YOUR CODE HERE ////////////////
}

bool Board::check_win(int player_id, std::pair<int, int> player_pos) {

    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
    if (player_id == 0) {
        if (player_pos.second == 16) return true;
        else return false;
    }
    else if (player_id == 1) {
        if (player_pos.second == 0) return true;
        else return false;
    }
    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////

}

bool Board::check_red_pixel(std::pair<int, int> player_pos) { // 

    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////
    if ((player_pos.first == 4) || (player_pos.first == 12)) {
        if ((player_pos.second == 4) || (player_pos.second == 12)) return true;
        else return false;
    }
    else return false;
    ///////////////// IMPLEMENT YOUR CODE HERE /////////////////

}
