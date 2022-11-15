/*********************************************************************
						MAIN PROGRAM													
--------------------------------------------------------------------*/

/*!		\Game of life´s main page by Joona Anttila
		\Section introduction
		\Date 04/20
		\Bug Testing bug tag.
		\Warning Teesting warning tag.
		\copyright GNU Public License.
*/                                                   
/**********************************************************************/

#include "header.h"




int main(void)
{
    int i, years, microseconds;
    struct cell board[MAX] [MAX] = {0, 0};
    initscr();
    start_color();
    init_pair(1, COLOR_RED, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
    
    curs_set(0);
	
	
	bkgd(COLOR_PAIR(2));
	attron(A_STANDOUT);
	move(1, 65);
	printw("Game of life");
	move(2, 10);
	printw("Give years:");
	scanw("%d" ,&years);
	move(3, 10);
	printw("Give time in microseconds:");
	scanw("%d" ,&microseconds);
	
	bkgd(COLOR_PAIR(2));
	draw_fence();
	bkgd(COLOR_PAIR(1));
    display_current_situation(board);

    for (i = 1; i <= years; i++)
    {
        refresh();
		
        calculate_future_situation(board);
        display_future_situation(board);
        usleep(microseconds);
    }
	

    getch();
    endwin();
}/* end of main */