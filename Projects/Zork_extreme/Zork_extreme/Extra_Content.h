#ifndef ROOM_H
#define ROOM_H

//Los enum de las varibles
enum Allrooms
{
	 KITCHEN,
	 HALL,
};

enum Positions
{
	NORTH,
	SOUTH,
	EAST,
	WEST,

};

//Class father es la jefa las demas iran heredando de esta (o esa es la idea)

class Father
{
public:
	
	//de momento sera todo publico para no complicarnos poco a poco sergio
	
	Allrooms room;
	Positions  look;
	char* info;
	
  
	

};

//class Room es una clase que esta heredando las cosas de la de father

class Room : public Father
{
public:
	
	Room(Allrooms _room)
	{
		room = _room;

	}
    
	void setinfo(char* _info, int lenght)
	{
		info = new char[lenght];

		for (unsigned int i = 0; i < lenght; i++)
		{
			info[i] = _info[i];
		}
	}
  

}; 


//lo mismo que con la de Room pero esta es con las posiciones

class Look : public Father
{
public:
	
	Look(Positions _look)
	{
		look = _look;
	}
	
	void setinfo(char* _info, int lenght)
	{
		info = new char[lenght];

		for (unsigned int i = 0; i < lenght; i++)
		{
			info[i] = _info[i];
		}
	}

};

//la clase exit aun esta en construccion pero la idea es que herede de room y father porque la salida es la antrada a otra room 

class Exit : Room
{

	Exit(Allrooms room) : Room(room) {}

};





#endif