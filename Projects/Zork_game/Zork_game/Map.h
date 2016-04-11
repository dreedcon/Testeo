#ifndef MAP_H
#define MAP_H

#include "Cell.h"

struct Map
{
	int x, y, map;
	Cell* cells[5][5];

	inline Map()
	{
		for (unsigned int i = 0; i < 5; i++)
		{
			for (unsigned int j = 0; j < 5; j++)
			{
				cells[i][j] = NULL;
			}
		}
		LoadMap1();
	}
	
	void LoadMap1()
	{
		FreeMap();

		map = 1;
		x = 2;
		y = 2;

		//load map
		cells[0][0] = NULL;			cells[1][0] = NULL;				cells[2][0] = NULL;					cells[3][0] = NULL;			cells[4][0] = NULL;
		cells[0][1] = NULL;			cells[1][1] = NULL;				cells[2][1] = new Room(KITCHEN);	cells[3][1] = NULL;			cells[4][1] = NULL;
		cells[0][2] = NULL;			cells[1][2] = NULL;				cells[2][2] = new Room(KITCHEN);	cells[3][2] = NULL;			cells[4][2] = NULL;
		cells[0][3] = NULL;			cells[1][3] = NULL;				cells[2][3] = new Room(EXIT);		cells[3][3] = NULL;			cells[4][3] = NULL;
		cells[0][4] = NULL;			cells[1][4] = NULL;				cells[2][4] = NULL;					cells[3][4] = NULL;			cells[4][4] = NULL;


		cells[2][2]->setInfo("te encuentras en la cocna que por lo que ves ahora esta un poco desordenada, ya que eres un vago que no limpias tu casa, un poquito de por favor...", 150);
		cells[2][1]->setInfo("ves en la cocina una serie de instrumentos que puedes ver o coger, desde comida o agua", 100);
		cells[2][3]->setInfo("FSEFSEF", 10);
	}

	void MoveNorth()
	{
		if (cells[x][y + 1] != NULL)
		{
			y++;
		}
		else
		{
			printf("No puedes ir mas al norte\n\n");
		}
	}
	void MoveEast()
	{
		x++;
	}
	void MoveWest()
	{
		x--;
	}
	void MoveSouth()
	{ 
		if (cells[x][y - 1] != NULL)
		{
			y--;
		}
		else
		{
			printf("No puedes ir mas al sur\n\n");
		}
		
	}

	void getInfo()
	{
		printf(" %s", cells[x][y]->info);
	}

	CELL_TYPE GetType()
	{
		return cells[x][y]->type;
	}

private:
	void FreeMap()
	{
		// libera el mapa
	
		delete LoadMap1();
	}

	void LoadNewMap()
	{
		switch (map)
		{

		}
	}


};


extern Map* minimap = NULL;





#endif