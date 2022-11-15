#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

#define MAX 41

struct cell
{
    int current; /**< This current includes current gamedata situation */
    int future;	/**< This future icludes future gamedata situation */
};

void display_current_situation(struct cell board[MAX] [MAX]);
void calculate_future_situation(struct cell board[MAX] [MAX]);
void display_future_situation(struct cell board[MAX] [MAX]);
void draw_fence(void);
