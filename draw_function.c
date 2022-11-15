/*********************************************************************
			F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/

/*!		\fn void draw_fence(void)
		\brief function draws fence around the game board.
		\param -
		\return -

*/
/**********************************************************************/


#include "header.h"

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
---------------------------------------------------------------------*/

/*!		\fn void display_current_situation(struct cell board[MAX] [MAX])
		\brief function display the situation of population on gameboard.
		\param board gamedata
		\return -

*/
/**********************************************************************/



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
---------------------------------------------------------------------*/
 
 /*!	\fn void display_future_situation(struct cell board[MAX] [MAX])
		\brief function will save the future situation and move it to current function.
		\param board gamedata
		\return -

*/
/**********************************************************************/
 
 
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
