#include <stdio.h>
#include <stdlib.h>

#define GAME_OVER NULL

int zero, choice, result, player1_turn = NULL, player2_turn = NULL;

struct player {
    int score;
} player1, player2;

struct BOARD {
    int board_elements[9];
} board;

void draw_board(void) {
    system("clear");
    for(zero = 0; zero < 9; zero++) {
        printf(board.board_elements[zero] != '_' ? "\033[0;32m" : "\033[0m");
        printf(zero == 2 || zero == 5 ? "%c\n" : "%c ", board.board_elements[zero]);
    }
    if(check_winner() != 0) {
        printf("\033[0;32m");
        printf(check_winner() == 1 ? "\n\nPlayer 1 Won!\n" : "\n\nPlayer 2 Won!\n");
        exit(1);
    }
}

int check_winner(void) {
    if
    (
        // Horizantal
        board.board_elements[0] == board.board_elements[1] && board.board_elements[1] == board.board_elements[2] && board.board_elements[0] != '_' ||
        board.board_elements[3] == board.board_elements[4] && board.board_elements[4] == board.board_elements[5] && board.board_elements[3] != '_' ||
        board.board_elements[6] == board.board_elements[7] && board.board_elements[7] == board.board_elements[8] && board.board_elements[6] != '_' ||
        // Vertical
        board.board_elements[0] == board.board_elements[3] && board.board_elements[3] == board.board_elements[6] && board.board_elements[0] != '_' ||
        board.board_elements[1] == board.board_elements[4] && board.board_elements[4] == board.board_elements[7] && board.board_elements[1] != '_' ||
        board.board_elements[2] == board.board_elements[5] && board.board_elements[5] == board.board_elements[8] && board.board_elements[2] != '_' ||
        // Crossed
        board.board_elements[0] == board.board_elements[4] && board.board_elements[4] == board.board_elements[8] && board.board_elements[0] != '_' ||
        board.board_elements[2] == board.board_elements[4] && board.board_elements[4] == board.board_elements[6] && board.board_elements[2] != '_'
    ) {
        if(player1_turn != NULL) {
            return 1;
        }
        else {
            return 2;
        }
    }
    return 0;
}

int is_moveable(move) {
    return board.board_elements[move - 1] == '_' ? 1 : 0;
}

void play_player1(void) {
    player2_turn = NULL;
    printf("\033[0m");
    printf("\n\nPlayer1, Your Choice?\n");
    scanf(" %d", &choice);
    result = is_moveable(choice);
    if(result == 0) {
        printf("\nPlayer1, You can't move to %d. Player 2 Won!\n", choice);
        exit(1);
    }
    board.board_elements[choice - 1] = 'x';
    player1_turn = 1;
    draw_board();
}

void play_player2(void) {
    player1_turn = NULL;
    printf("\033[0m");
    printf("\n\nPlayer2, Your Choice?\n");
    scanf(" %d", &choice);
    result = is_moveable(choice);
    if(result == 0) {
        printf("\nPlayer2, You can't move to %d. Player 1 Won!\n", choice);
        exit(1);
    }
    board.board_elements[choice - 1] = 'y';
    player2_turn = 1;
    draw_board();
}

void play(void) {
    zero = 0;
    do {
        board.board_elements[zero] = '_';
        zero += 1;
    } while(zero < 9);
    draw_board();
    while(!GAME_OVER) {
        play_player1();
        play_player2();
    }
}
