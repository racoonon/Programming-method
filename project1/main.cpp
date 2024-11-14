#include <iostream>
#include <string>
#include <Windows.h>
#include <utility>
#include <vector>

#include "board.hpp"
#include "calculator.hpp"
#include "player.hpp"

#define COLOR_RED "\033[31m"    /* Red */
#define COLOR_YELLOW "\033[33m" /* Yellow */
#define COLOR_BLUE "\033[34m"   /* Blue */
#define COLOR_GREEN "\033[32m"  /* Green */
#define COLOR_DEFAULT "\033[0m" /* Default */

class Quoridor {
  public:
    Quoridor() {
        players[0] = Player(0, 8, 0);
        players[1] = Player(1, 8, 16);
    }
    char get_press_key(int player_id);
    void run();

  private:
    Board board;
    Player players[2];
    Calculator calculator;
};

char Quoridor::get_press_key(int player_id) {
    char press;
    if (player_id == 0) {
        std::cout << "Player" << COLOR_YELLOW << " 1" << COLOR_DEFAULT
                  << "'s turn.";
    } else if (player_id == 1) {
        std::cout << "Player" << COLOR_GREEN << " 2" << COLOR_DEFAULT
                  << "'s turn.";
    }
    std::cout << " You have " << players[player_id].left_walls_num()
              << COLOR_DEFAULT << " walls left."
              << "\n"
              << "Press 1 to move your piece and Press 2 to place a wall: ";
    while (1) {
        std::cin >> press;
        if (press == '1')
            break;
        else if (press == '2') {
            if (players[player_id].left_walls_num() > 0)
                break;
            else {
                std::cout
                    << "You don't have any walls left! Please input again: ";
                continue;
            }
        } else {
            std::cout << "Invalid press! Please input again: ";
            continue;
        }
    }
    return press;
}

void Quoridor::run() {

    system("clear");
    std::cout << "Quoridor game start!" << std::endl;
    int player_id = 0;
    while (true) {
        system("clear");
        board.board_update(players[0].get_pos(), players[1].get_pos(),
                           players[0].get_walls(), players[1].get_walls());
        board.print_board();
        std::pair<int, int> prev_player_pos = players[player_id].get_pos();
        char press = get_press_key(player_id);
        // move a pawn
        if (press == '1') {
            players[player_id].move(board.get_board());
        }
        // place a wall
        else if (press == '2') {
            players[player_id].place_wall(board.get_board());
        }
        
        // If player is in the red pixel, solve the calculator problem
        if (board.check_red_pixel(players[player_id].get_pos()) == true) {
            system("clear");
            board.board_update(players[0].get_pos(), players[1].get_pos(),
                               players[0].get_walls(), players[1].get_walls());
            board.print_board();
            std::cout << "You are in the red pixel! You have to solve the "
                      << "problem!" << std::endl;
            std::cout << "Player " << (player_id + 1) % 2 + 1 << " make a "
                      << "problem for Player " << player_id + 1 << ": ";
            // Pass if solve the calculation problem
            if (calculator.query() == true) {
                std::cout << "You solved the problem! You can stay in the red "
                          << "pixel!" << std::endl;
            } else {
                std::cout
                    << "You failed to solve the problem! So you went back to "
                    << "the previous place" << std::endl;
                players[player_id].set_pos(prev_player_pos);
            }
            
           // sleep(3000);
        }

        if (board.check_win(player_id, players[player_id].get_pos()) == true) {
            system("clear");
            board.board_update(players[0].get_pos(), players[1].get_pos(),
                               players[0].get_walls(), players[1].get_walls());
            board.print_board();
            std::cout << "Player" << player_id + 1 << " wins!" << std::endl;
            break;
        }
        player_id = (player_id + 1) % 2;
        system("cls");
    }
}

int main() {
    Quoridor game = Quoridor();
    game.run();
    return 0;
}
