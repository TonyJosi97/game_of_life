#include "../inc/gol_core_utils.h"

int init_board(uint32_t size, uint8_t ***Board) {

    uint32_t row_col_size;
    if(size == DEFAULT_INIT_SETUP)
        row_col_size = MAX_BOARD_DEFAULT_SIZE;
    else
        row_col_size = size;

    *Board = (uint8_t **)malloc(row_col_size * sizeof(uint8_t *));

    if(*Board) {
        for (uint32_t i=0; i < row_col_size; i++) {
            (*Board)[i] = (uint8_t *)malloc(row_col_size * sizeof(uint8_t)); 

            if((*Board)[i] == NULL)
                return 1;

        }
    }
    else
        return 1;

    for (uint32_t i = 0; i < row_col_size; i++) 
        for (uint32_t j = 0; j < row_col_size; j++) 
            (*Board)[i][j] = 0;

    return 0;

}

int fill_board_init_setup(uint32_t choice, uint8_t **Board) {

    if(choice == DEFAULT_INIT_SETUP) {
        /* default init for Exploder */
        /*
        Board[6][8] = 1;
        Board[7][8] = 1;
        Board[8][8] = 1;
        Board[9][8] = 1;
        Board[10][8] = 1;
        Board[6][10] = 1;
        Board[6][12] = 1;
        Board[7][12] = 1;
        Board[8][12] = 1;
        Board[9][12] = 1;
        Board[10][12] = 1;
        Board[10][10] = 1;
        */

        /* default init for Small Exploder */
        /*
        Board[9][8] = 1;
        Board[9][9] = 1;
        Board[9][10] = 1;
        Board[8][9] = 1;
        Board[10][8] = 1;
        Board[10][10] = 1;
        Board[11][9] = 1;
        */

        /* default init for 10 Cell Row */
        /*
        Board[10][5] = 1;
        Board[10][6] = 1;        
        Board[10][7] = 1;
        Board[10][8] = 1;        
        Board[10][9] = 1;
        Board[10][10] = 1;
        Board[10][11] = 1;
        Board[10][12] = 1;        
        Board[10][13] = 1;
        Board[10][14] = 1;
        */

        /* default init for Lightweight Spaceship */
        /*
        Board[8][8] = 1;
        Board[8][9] = 1;        
        Board[8][10] = 1;
        Board[8][11] = 1;        
        Board[9][7] = 1;
        Board[9][11] = 1;
        Board[10][11] = 1;
        Board[11][7] = 1;        
        Board[11][10] = 1;
        */

        /* default init for Gosper Glider Gun */
        /* NOTE: Increase the MAX_BOARD_DEFAULT_SIZE in gol.h to 80 or above 
        also increase MAX_NOOF_GENERATIONS to 200 or above */
        
        // left square 
        Board[10 + PIXEL_SIZE][10 + PIXEL_SIZE] = 1;
        Board[10 + PIXEL_SIZE][11 + PIXEL_SIZE] = 1;
        Board[11 + PIXEL_SIZE][10 + PIXEL_SIZE] = 1;
        Board[11 + PIXEL_SIZE][11 + PIXEL_SIZE] = 1;
        // left diamond 
        Board[10 + PIXEL_SIZE][19 + PIXEL_SIZE] = 1;
        Board[10 + PIXEL_SIZE][20 + PIXEL_SIZE] = 1;
        Board[11 + PIXEL_SIZE][18 + PIXEL_SIZE] = 1;
        Board[11 + PIXEL_SIZE][20 + PIXEL_SIZE] = 1;
        Board[12 + PIXEL_SIZE][18 + PIXEL_SIZE] = 1;
        Board[12 + PIXEL_SIZE][19 + PIXEL_SIZE] = 1;
        // glidr b/w diamonds 
        Board[12 + PIXEL_SIZE][26 + PIXEL_SIZE] = 1;
        Board[12 + PIXEL_SIZE][27 + PIXEL_SIZE] = 1;
        Board[13 + PIXEL_SIZE][26 + PIXEL_SIZE] = 1;
        Board[13 + PIXEL_SIZE][28 + PIXEL_SIZE] = 1;
        Board[14 + PIXEL_SIZE][26 + PIXEL_SIZE] = 1;
        // right diamond 
        Board[8 + PIXEL_SIZE][33 + PIXEL_SIZE] = 1;
        Board[8 + PIXEL_SIZE][34 + PIXEL_SIZE] = 1;
        Board[9 + PIXEL_SIZE][32 + PIXEL_SIZE] = 1;
        Board[9 + PIXEL_SIZE][34 + PIXEL_SIZE] = 1;
        Board[10 + PIXEL_SIZE][32 + PIXEL_SIZE] = 1;
        Board[10 + PIXEL_SIZE][33 + PIXEL_SIZE] = 1;
        // bottum glidr 
        Board[20 + PIXEL_SIZE][34 + PIXEL_SIZE] = 1;
        Board[20 + PIXEL_SIZE][35 + PIXEL_SIZE] = 1;
        Board[20 + PIXEL_SIZE][36 + PIXEL_SIZE] = 1;
        Board[21 + PIXEL_SIZE][34 + PIXEL_SIZE] = 1;
        Board[22 + PIXEL_SIZE][35 + PIXEL_SIZE] = 1;
        // right square 
        Board[8 + PIXEL_SIZE][44 + PIXEL_SIZE] = 1;
        Board[8 + PIXEL_SIZE][45 + PIXEL_SIZE] = 1;
        Board[9 + PIXEL_SIZE][44 + PIXEL_SIZE] = 1;
        Board[9 + PIXEL_SIZE][45 + PIXEL_SIZE] = 1;
        // glidr below right square 
        Board[15 + PIXEL_SIZE][45 + PIXEL_SIZE] = 1;
        Board[15 + PIXEL_SIZE][46 + PIXEL_SIZE] = 1;
        Board[16 + PIXEL_SIZE][45 + PIXEL_SIZE] = 1;
        Board[16 + PIXEL_SIZE][47 + PIXEL_SIZE] = 1;
        Board[17 + PIXEL_SIZE][45 + PIXEL_SIZE] = 1;
        

        /* default init for random live cells */
        /*
        srand(time(0)); 
        for (uint32_t i = PIXEL_SIZE; i < (MAX_BOARD_DEFAULT_SIZE - PIXEL_SIZE); i++) 
            for (uint32_t j = PIXEL_SIZE; j < (MAX_BOARD_DEFAULT_SIZE - PIXEL_SIZE); j++) 
                Board[i][j] = RAND_GEN(2);
        */
    }
    return 0;

}

void clear_board(uint32_t size_arg, uint8_t val, uint8_t **Board) {

    uint32_t row_col_size;
    uint8_t intlzr;
    
    if(size_arg == DEFAULT_INIT_SETUP)
        row_col_size = MAX_BOARD_DEFAULT_SIZE;
    else
        row_col_size = size_arg;

    if(val == 0)
        intlzr = 0;
    else
        intlzr = 1;

    for (uint32_t i = 0; i < row_col_size; i++) 
        memset(Board[i], intlzr, row_col_size);

}

void free_board(uint32_t size_arg, uint8_t ***Board) {

    uint32_t row_col_size;
    
    if(size_arg == DEFAULT_INIT_SETUP)
        row_col_size = MAX_BOARD_DEFAULT_SIZE;
    else
        row_col_size = size_arg;

    for (uint32_t i = 0; i < row_col_size; i++) {
        free((*Board)[i]);
        (*Board)[i] = NULL;
    }

    free(*Board);
    *Board = NULL;

}

int init_temp_board(tboard_t *tboard) {

    int ret_code = 0;

    ret_code |= init_board(DEFAULT_INIT_SETUP, &(tboard->rule_1_temp_board));
    ret_code |= init_board(DEFAULT_INIT_SETUP, &(tboard->rule_2_temp_board));
    ret_code |= init_board(DEFAULT_INIT_SETUP, &(tboard->rule_3_temp_board));

    return ret_code;

}

void free_temp_board(tboard_t *tboard) {

    free_board(DEFAULT_INIT_SETUP, &(tboard->rule_1_temp_board));
    free_board(DEFAULT_INIT_SETUP, &(tboard->rule_2_temp_board));
    free_board(DEFAULT_INIT_SETUP, &(tboard->rule_3_temp_board));

}


#ifndef _WIN32
    int sleep_in_ms(long ms) {

        struct timespec ts;
        int res;

        ts.tv_sec = ms / 1000;
        ts.tv_nsec = (ms % 1000) * 1000000;

        do {
            res = nanosleep(&ts, &ts);
        } while (res);

        return res;
    }
#endif

