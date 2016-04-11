#include <iostream>
#include <string>
#include<stdlib.h>

#include "Extra_Content.h"

using namespace std;

int main()
{
	system("color A9");
	string write;
	string write1;
	
	printf("\n\n Welcome to Zork_Extreme You are in World, where many dangers will occur and     will die , but death is passing here , whether that luck with you .\n\n\t");

	//contruimos las habitaciones
	Father* kitchen = new Room(KITCHEN);
	Father* Hall = new Room(HALL);

	//lo mismo pero en las posiciones
	Father* Position = new Look(NORTH);
	Father* Position1 = new Look(EAST);
	
	//construimos the room kitchen 
	kitchen->room;
	kitchen->info = {"\n estas en la cocina, en ella encontraras comida, agua , y a lo mejor utensilios  de ayuda"};
	
	//construimos the room hall
	Hall->room;
	Hall->info = { "\n estas en la entrada no ves gran cosa, ves que hay una puerta y un ventana" };

	printf("%s, \n\n", kitchen->info); //imprimimos la room
	
	//construimos las posiciones
	Position->look;
	Position->info = { "\n al norte ves que hay un fregadero, dos tomates, y una cantimplora\n" };
	Position1->look;
	Position1->info = { "\n en el este ves que esta la salida de la cocina \n" };
	
	cin >> write;
	if (write == "north")
	{
		
	printf("%s, \n\n", Position->info); //imprimimos la descripcion de la posicion
	
	}
	else if (write == "east")
	{
	
	printf("%s, \n\n", Position1->info); //imprimimos la descripcion de la posicion

	}
	else if (write == "quit")
	{
		return getchar();
	}
	
	
	
	
	
	system("pause");

}