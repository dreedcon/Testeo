#include <iostream>


#include "Rooms.h"
#include "Exits.h"
#include "Map.h"

using namespace std;

int main()
{
	char answer = '\0';
	
	minimap = ;

	printf("bienvenido al Zork EXTREME, estas a punto de comenzar tu aventura.\n\n");

	//gameloop
	while (true)
	{
		minimap->getInfo();
		printf("\n\nQue quieres hacer?\n\t");

		cin>>answer;

		system("cls");

		switch (minimap->GetType())
		{
		case KITCHEN:
			printf("\n\nEstas en la cocina\n");
			switch (answer)
			{
			case 'n':  minimap->MoveNorth(); break;
			case 's':  minimap->MoveSouth(); break;
			case 'w':  minimap->MoveWest(); break;
			case 'e':  minimap->MoveEast(); break;
			case '\0': break;

			default: printf("no puedes hacer eso\n");
			}
			break;
		case EXIT:
			printf("\n\nEstas en la entrada de la cocina\n");

			switch (answer)
			{
			case 'n':  minimap->MoveNorth(); break;
			case 's':  minimap->MoveSouth(); break;
			case 'w':  minimap->MoveWest(); break;
			case 'e':  minimap->MoveEast(); break;
			case 'q':  system("pause"); return 0;
			case '\0': break;

			default: printf("no puedes hacer eso\n");
			}

		}


	}

	

	system("pause");
}