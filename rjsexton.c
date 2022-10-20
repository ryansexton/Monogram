#include <stdio.h>
#include <unistd.h>
#include <ncurses.h>

#define WHITE 1
#define BLACK 0
#define GREEN 2

void draw_grid(uint16_t pixels[8][8]){
    for(int y=0; y<8; y++){
        move(y,0);
        for(int x=0; x<8; x++){
            if(pixels[7-x][y]){
                attron(COLOR_PAIR(pixels[7-x][y]));
                addch('#');
                attroff(COLOR_PAIR(pixels[7-x][y]));
            } else{
                addch(' ');
            }
        }
    }
    refresh();
}

void fill_pixels(uint16_t pixels[8][8], uint16_t color){
    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            pixels[i][j] = color;
        }
    }
}

int main(void) {
    // uint16_t means "non-negative two-byte integer"
    uint16_t pixel[8][8];

    // Starts drawing in the terminal
    initscr();
    start_color();
    /* This means consider WHITE to mean
     * foreground is COLOR_WHITE (i.e., white) and 
     * background is also COLOR_WHITE.
     * The value of WHITE was #defined above.
     * The value of COLOR_WHITE is #defined in
     * ncurses.h. You can aslo use:
     * COLOR_BLACK
     * COLOR_RED
     * COLOR_GREEN
     * COLOR_YELLOW
     * COLOR_BLUE
     * COLOR_MAGENTA
     * COLOR_CYAN
     * but you probably also want to define your own, for example
     * #define RED 2
     */
    init_pair(WHITE, COLOR_WHITE, COLOR_WHITE);
    init_pair(BLACK, COLOR_BLACK, COLOR_BLACK);
    init_pair(GREEN, COLOR_GREEN, COLOR_GREEN);

    fill_pixels(pixel,BLACK);
   // Top of R
   pixel[6][1]=WHITE;
   pixel[5][1]=WHITE;
   pixel[4][1]=WHITE;
   pixel[3][1]=WHITE;
   pixel[2][1]=WHITE;
   pixel[6][2]=WHITE;
   pixel[2][2]=WHITE;
   pixel[1][2]=WHITE;

   //Middle of R
   pixel[6][3]=WHITE;
   pixel[2][3]=WHITE;
   pixel[1][3]=WHITE;
   pixel[6][4]=WHITE;
   pixel[3][4]=WHITE;
   pixel[2][4]=WHITE;
   pixel[1][4]=WHITE;
   pixel[6][5]=WHITE;
   pixel[5][5]=WHITE;
   pixel[4][5]=WHITE;
   pixel[3][5]=WHITE;

   //Bottom of R
   pixel[6][6]=WHITE;
   pixel[4][6]=WHITE;
   pixel[3][6]=WHITE;
   pixel[2][6]=WHITE;
   pixel[6][7]=WHITE;
   pixel[3][7]=WHITE;
   pixel[2][7]=WHITE;
   pixel[1][7]=WHITE;

   // see: man 3 sleep
   draw_grid(pixel);
   sleep(2);
   
   fill_pixels(pixel,WHITE);
   //Top of S
   pixel[7][0]=GREEN;
   pixel[0][0]=GREEN;
   pixel[4][2]=GREEN;
   pixel[3][2]=GREEN;
   pixel[2][2]=GREEN;
   pixel[1][2]=GREEN;
   pixel[0][2]=GREEN;
   pixel[6][0]=GREEN;
   pixel[1][0]=GREEN;
   pixel[7][1]=GREEN;
   pixel[0][1]=GREEN;
   pixel[7][2]=GREEN;
   pixel[5][0]=GREEN;
   pixel[4][0]=GREEN;
   pixel[3][0]=GREEN;
   pixel[2][0]=GREEN;
   pixel[6][1]=GREEN;

   //Middle of S
   pixel[0][3]=GREEN;
   pixel[7][4]=GREEN;
   pixel[7][5]=GREEN;
   pixel[6][5]=GREEN;
   pixel[5][5]=GREEN;
   pixel[4][5]=GREEN;
   pixel[3][5]=GREEN;
   pixel[7][3]=GREEN;
   pixel[7][4]=GREEN;
   pixel[0][4]=GREEN;
   pixel[0][5]=GREEN;
   pixel[1][3]=GREEN;
   pixel[6][4]=GREEN;

   //Bottom of S
   pixel[7][7]=GREEN;
   pixel[0][7]=GREEN;
   pixel[7][6]=GREEN;
   pixel[0][6]=GREEN;
   pixel[1][7]=GREEN;
   pixel[6][7]=GREEN;
   pixel[5][7]=GREEN;
   pixel[4][7]=GREEN;
   pixel[3][7]=GREEN;
   pixel[2][7]=GREEN;
   pixel[1][6]=GREEN;

   draw_grid(pixel);
   sleep(2);

   // endwin() should only be called once/program
   endwin();
   return 0;
}
