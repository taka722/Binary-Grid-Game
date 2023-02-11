//Binary grid puzzle 
//2D array, pointer, structure
#include "bingrid.h"


#define BOARDSTR (MAX*MAX+1) // add another definition about 2D array. 

void printboard(board* brd);  
//when the one of three rule could be applied, the the one of the output can be oppsite 1 or 0. 
char return_opposite(char s); 
// Function for counting UNK
int count_unk(board* brd); 



// Given an input string, complete information for board
bool str2board(board* brd, char* str)
{
    //2d array size should be [even]*[even]
    switch(strlen(str)){
        
        case 2*2:
        brd->sz = 2;
        break;
        
        case 4*4:
        brd->sz = 4;
        break;
        
        case 6*6:
        brd->sz = 6;
        break;
        
        case 8*8:
        brd->sz = 8;
        break;
        
        case 10*10:
        brd->sz = 10;
        break;
        
        case 12*12:
        brd->sz = 12;
        break;
        
        case 14*14:
        brd->sz = 14;
        break;
        
        case 16*16:
        brd->sz = 16;
        break;
        
        default:
        return false;
    }
    for(int i = 0; i< brd->sz; i++){
        for(int a = 0; a < brd->sz; a++){
            brd->b2d[i][a] = str[i * brd->sz + a];
           /*  char a[100];
               char* p_a;
               p_a = a;  //p_aはaの先頭ポインタ
               p_a[4];  //a[4]と同じ意味
               p_a[10];  //a[10]と同じ意味
 */
        }
    }
    return true;    
}
// Given a board structure, create string version　
void board2str(char* str, board* brd)
{
    //initializing the array if it doesn't meet the condition. 
    if(brd->sz == 0 || brd->sz > MAX || brd->sz % 2 == 1){
        for(int a = 0; a < BOARDSTR; a++){
            str[a] = 0;
        }  
    }
    else{
        for(int i = 0; i < brd->sz; i++){
            for(int b = 0; b < brd-> sz; b++){
                str[i * brd->sz + b] = brd->b2d[i][b];
            }
        }
    }
}

//create the functions for return opposite outcome to reduce the if statement, because if we can apply the three rule, the one output should be opposite value of other values. 
char return_opposite(char s)
{
    if(s == ZERO){
        return ONE;
    }
    else if(s == ONE){
        return ZERO;
    }
    else{
        return s;
    }
}
//Counting UNK for checking if there is UNK in the output, it should be eliminated. I will call this function in solve_board function. 
int count_unk(board*brd)
{
    int ret = 0;
    for(int i = 0; i < brd->sz; i++){
        for(int j = 0; j < brd->sz; j++){
            if(brd->b2d[i][j] == UNK){
                ret++;
            }
        }
    }
    return ret;
} 

// Given a board, apply all rules repatedly - return true if solved, false otherwise
bool solve_board(board* brd)
{
    for(int a = 0; a < brd->sz*brd->sz; a++){
        if(brd->sz > 2){   // The size of array should be more than 2 to apply the rule of Pair and Oxo. 
            for(int i = 0; i < brd->sz; i++){
            //checking the first three char (From the Left end side)
                if(brd->b2d[i][0] == brd->b2d[i][1] && brd->b2d[i][0] != UNK){
                    brd->b2d[i][2] = return_opposite(brd->b2d[i][1]);
                }
            //checking the last three char (From the Right end side)
                if(brd->b2d[i][brd->sz-1] ==  brd->b2d[i][brd->sz-2] && brd->b2d[i][brd->sz-1] != UNK){
                    brd->b2d[i][brd->sz-3] = return_opposite(brd->b2d[i][brd->sz-2]);
                }
            //considering the rest of board. 
                for(int j = 1; j < brd->sz - 2; j++){
                    if(brd->b2d[i][j] == brd->b2d[i][j+1] && brd->b2d[i][j] != UNK){
                        brd->b2d[i][j-1] = return_opposite(brd->b2d[i][j]);
                        brd->b2d[i][j+2] = return_opposite(brd->b2d[i][j]);
                    }
                }   
            }

            //Pair - Considering the column
            for(int i = 0; i<brd->sz; i++){
            // Considering the first three char of the column (Upper end)
                if(brd->b2d[0][i] == brd->b2d[1][i] && brd->b2d[0][1] != UNK){
                    brd->b2d[2][i] = return_opposite(brd->b2d[1][i]); 
                }
            // Considering the last three char of the column  (Lower end)
                if(brd->b2d[brd->sz-1][i] ==  brd->b2d[brd->sz-2][i] && brd->b2d[brd->sz-1][i] != UNK){
                    brd->b2d[brd->sz-3][i] = return_opposite(brd->b2d[brd->sz-2][i]);
                }
            
            //considering the rest of 2d array
                for(int j = 1; j < brd->sz-2; j++){
                    if(brd->b2d[j][i] == brd->b2d[j+1][i] && brd->b2d[j][i] != UNK){
                        brd->b2d[j-1][i] = return_opposite(brd->b2d[j][i]);
                        brd->b2d[j+2][i] = return_opposite(brd->b2d[j][i]);
                    }
                }
            }
        
        //2. Oxo - rule.
        // Considering the row. 
            for(int i = 0; i < brd->sz; i++){
                for(int j = 0; j < brd->sz - 2; j++){
                    if(brd->b2d[i][j] == brd->b2d[i][j+2] && brd->b2d[i][j] != UNK){
                        brd->b2d[i][j+1] = return_opposite(brd->b2d[i][j+2]);
                    }
                }
            }
        // Considering the column. 
            for(int i = 0; i < brd->sz; i++){
                for(int j = 0; j < brd->sz - 2; j++){
                    if(brd->b2d[j][i] == brd->b2d[j+2][i] && brd->b2d[j][i] != UNK){
                        brd->b2d[j+1][i] = return_opposite(brd->b2d[j+2][i]);
                    }
                }
            }
        }
        //3. Count rule. 
        // row
        for(int i = 0; i < brd->sz; i++){
            int num0 = 0;  // variable to count the number of 0
            int num1 = 0;  // variable to count the number of 1
            //Counting how many numbers do they have 0 or 1. 
            for(int j = 0; j < brd->sz; j++){
                if(brd->b2d[i][j] == ZERO){
                    num0++;
                }
                else if(brd->b2d[i][j] == ONE){
                    num1++;
                }
            }
            // if num0 is larger than num1. 
            if(num0 >= brd->sz / 2){
                for(int j = 0; j < brd->sz; j++){
                    if(brd->b2d[i][j] == UNK){
                        brd->b2d[i][j] = ONE;
                    }
                }
            }
            // if num1 is laarger than num0
            if(num1 >= brd->sz / 2){
                for(int j = 0; j < brd->sz; j++){
                    if(brd->b2d[i][j] == UNK){
                        brd->b2d[i][j] = ZERO;
                    }
                }
            }
        }
        //counting for colunn. it is the almost same things about the row. 
        for(int i = 0; i < brd->sz; i++){
            int num0 = 0; 
            int num1 = 0;
            for(int j = 0; j < brd->sz; j++){
                if(brd->b2d[j][i] == ZERO){
                    num0++;
                }
                else if(brd->b2d[j][i] == ONE){
                    num1++;
                }
            }
            if(num0 >= brd->sz/2){
                for(int j = 0; j < brd->sz; j++){
                    if(brd->b2d[j][i] == UNK){
                        brd->b2d[j][i] = ONE;
                    }
                }
            }
            if(num1 >= brd->sz/2){
                for(int j = 0; j < brd->sz; j++){
                    if(brd->b2d[j][i] == UNK){
                        brd->b2d[j][i] = ZERO;
                    }
                }
            }
        }
    }
    //it should not be the output which has '.' in the board.
    if(count_unk(brd) != 0){ 
        return false;
    } 
    else{ 
        printboard(brd);
        return true; 
    } 
}

void printboard(board* brd)   
{
    for(int i = 0; i < brd->sz; i++){
        for(int j = 0; j < brd->sz; j++){
            printf("%c ", brd->b2d[i][j]);
        }
        printf("\n"); 
    }
    printf("\n"); 

}

//test for each functions; i need test functions more than one. 
void test(void)
{
   board b;
   //char str[BOARDSTR];
    // String Invalid
/*    assert(str2board(&b, "")==false);

   // Not an even size x even size board
   assert(str2board(&b, "...1.0...")==false);

  // An empty board still gives a 'sensible' string
   b.sz = 0;
   board2str(str, &b);
   assert(strcmp(str, "")==0);

   // Solvable 2x2 Board

   assert(str2board(&b, ".0.."));
   assert(solve_board(&b)==true);    
   board2str(str, &b);
   assert(strcmp(str, "1001")==0);

   // Solvable 4x4 Board
   assert(str2board(&b, "...1.0......1..1"));
   assert(solve_board(&b)==true);
   board2str(str, &b);
   assert(strcmp(str, "0101101001101001")==0);

   // Solvable4x4 Board
   assert(str2board(&b, "....0.0....1..0."));
   assert(solve_board(&b)==true);
   board2str(str, &b);
   assert(strcmp(str, "1010010100111100")==0);

   // Unsolvable 4x4 Board
   assert(str2board(&b, "...1.0.........1"));
   assert(solve_board(&b)==false);

   // Solvable 6x6 Board
   assert(str2board(&b, "1...1...0.....00...1................"));
   assert(solve_board(&b)==true);
   board2str(str, &b);
   assert(strcmp(str, "101010100101010011011010101100010101")==0);

   // Unsolvable 6x6 Board
   assert(str2board(&b, "....0...1.....11...0................"));
   assert(solve_board(&b)==false);

   // Solvable 8x8 Board
   assert(str2board(&b, "0.............0.00...1.....00.......0.....0..1.......00........."));
   assert(solve_board(&b)==true);
   board2str(str, &b);
   assert(strcmp(str, "0101011010011001001011010110011010010011110011000110100110110010")==0); */
   
   
   
   //checking the return_oppsite function.
   assert(return_opposite(ZERO) == ONE);
   assert(return_opposite(ONE) == ZERO);
   
   //testing funciton count_unk
   assert(str2board(&b, ".0.."));
   assert(count_unk(&b)==3);
   assert(str2board(&b, "...1.0......1..1"));
   assert(count_unk(&b)== 12);
   assert(str2board(&b, "1...1...0.....00...1................"));
   assert(count_unk(&b)== 30);
   
   
   
}
