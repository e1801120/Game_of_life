/*********************************************************************
			F U N C T I O N    D E S C R I P T I O N
---------------------------------------------------------------------*/

/*!		\fn void calculate_future_situation(struct cell board[MAX] [MAX])
		\brief function calculates new population situation.
		\param board gamedata
		\return -

*/
/**********************************************************************/


#include "header.h"

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