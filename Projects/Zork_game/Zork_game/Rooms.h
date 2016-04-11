#ifndef ROOMS_H
#define ROOMS_H

#include "Cell.h"


struct Room : Cell
{

	Room(CELL_TYPE type) : Cell(type)
	{}

	void createroom(Cell* n, Cell* w, Cell* e, Cell* s)
	{
		int room = 0;
		bool flag = true;


		if (room == 0)
		{
			room++;

			while (flag){
				if (room == 1)
				{

					printf("you are in a dark and gloomy forest, \n is full of dangers , \n depending on where you go you will find one or the other \n\n");
					room++;
				}
				flag = false;
			}
		}
	}



};






#endif