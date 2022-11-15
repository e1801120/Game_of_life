/***************************************************************************
 *   Copyright (C) 2020 by Joona Anttila   *
 *   jonttu.anttila@hotmail.com   *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

/*********************************************************************

 1.  NAME
	Game of life

 2.  DESCRIPTION
	Program shows you current "population" and then it calculates neighbours for each cell and some cells survive and some die
	If the cell has 0-1 neighbours the cell will die. 4 or more cell will die. 2-3 the cell will survive.
	And if empty cell has three neighbours a new "character" is born.

 3.  VERSIONS
       Original:
         11.3.2020 / Joona Anttila

       Version history:

**********************************************************************/


/*-------------------------------------------------------------------*
*    HEADER FILES                                                    *
*--------------------------------------------------------------------*/
#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>

/*-------------------------------------------------------------------*
*    GLOBAL VARIABLES AND CONSTANTS                                  *
*--------------------------------------------------------------------*/
/* Control flags */


/* Global constants */
#define MAX 41

/* Global variables */

/* Global structures */
struct cell
{
    int current;
    int future;
};



/*-------------------------------------------------------------------*
*    FUNCTION PROTOTYPES                                             *
*--------------------------------------------------------------------*/
void display_current_situation(struct cell board[MAX] [MAX]);
void calculate_future_situation(struct cell board[MAX] [MAX]);
void display_future_situation(struct cell board[MAX] [MAX]);
void draw_fence(void);

/*********************************************************************
*    MAIN PROGRAM                                                      *
**********************************************************************/
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

/*********************************************************************
*    FUNCTIONS                                                       *
**********************************************************************/
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void display_current_situation(struct cell board [MAX] [MAX])
 DESCRIPTION: This function display current "population" from given array places.

	Input:
	Output:
  Used variables: int l, m;
  Used global constants: #define MAX
  Used global structures: struct cell board[MAX] [MAX]
 REMARKS when using this function:
*********************************************************************/
void draw_fence(void)
{
	int i;
	
	for(i = 0; i < 41; i++)
	{
		move(2, 50+i);
		printw("#");
		move(2+i, 90);
		printw("#");
		move(2+i, 50);
		printw("#");
		move(42, 50+i);
		printw("#");
	}
}
/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void display_current_situation(struct cell board [MAX] [MAX])
 DESCRIPTION: This function display current "population" from given array places.

	Input:
	Output:
  Used variables: int l, m;
  Used global constants: #define MAX
  Used global structures: struct cell board[MAX] [MAX]
 REMARKS when using this function:
*********************************************************************/

void display_current_situation(struct cell board[MAX] [MAX])
{
    int l, m;
    board[15][20].current = 1;
    board[16][20].current = 1;
    board[17][18].current = 1;
    board[17][21].current = 1;
    board[17][22].current = 1;
    board[18][21].current = 1;
    board[18][22].current = 1;

    for (l = 1; l < MAX - 1; l++)
    {
        for (m = 1; m < MAX - 1; m++)
        {
            move(l + 2, m + 50);

            if (board[l][m].current == 1)
            {
                printw("0");
            }
            else
            {
                printw(".");
            }
        }

        
    }
}


/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void calculate_future_situation(struct cell board [MAX] [MAX])
 DESCRIPTION: This function calculates future situation from given rules.

	Input:
	Output:
  Used variables: int l, m, i, j, aliveNeighbours;
  Used global constants: #define MAX
  Used global structures: struct cell board[MAX] [MAX]
 REMARKS when using this function:
*********************************************************************/
void calculate_future_situation(struct cell board[MAX] [MAX])
{
    int i, j;
    int l, m;
    int aliveNeighbours = 0;

    for (l = 1; l < MAX - 1; l++)
    {
        for (m = 1; m < MAX - 1; m++)
        {
            for (i = -1; i <= 1; i++)
            {
                for (j = -1; j <= 1; j++)
                {
                    aliveNeighbours = aliveNeighbours + board[l + i][m + j].current;
                }
            }

            aliveNeighbours = aliveNeighbours - board[l][m].current;

            if ((board[l][m].current == 1) && (aliveNeighbours < 2))
            {
                board[l][m].future = 0;
            }
            else if ((board[l][m].current == 1) && (aliveNeighbours > 3))
            {
                board[l][m].future = 0;
            }
            else if ((board[l][m].current == 0) && (aliveNeighbours == 3))
            {
                board[l][m].future = 1;
            }
            else
			{
                board[l][m].future = board[l][m].current;
			}
				aliveNeighbours = 0;
        }
    }
}

/*********************************************************************
	F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------
 NAME: void display_future_situation(struct cell board [MAX] [MAX])
 DESCRIPTION: This function prints future situation.

	Input:
	Output:
  Used variables: int l, m;
  Used global constants: #define MAX
  Used global structures: struct cell board[MAX] [MAX]
 REMARKS when using this function:
*********************************************************************/
void display_future_situation(struct cell board[MAX] [MAX])
{
    int l, m;
    

    for (l = 1; l < MAX - 1; l++)
    {
        for (m = 1; m < MAX - 1; m++)
        {
            board[l][m].current = board[l][m].future;
            move(l + 2, m + 50);

            if (board[l][m].current == 1)
                printw("0");
            else
                printw(".");
        }

        
    }
}











