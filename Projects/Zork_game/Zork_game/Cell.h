#ifndef CELL_H
#define CELL_H


enum CELL_TYPE
{
	NOTHING = 0,
	KITCHEN,
	LIVING_ROOM,
	STAIRS,
	EXIT

};


struct Cell
{
	CELL_TYPE type;
	char* info;
	

	Cell(CELL_TYPE _type)
	{
		type = _type;
	}



	void setInfo(char* _info, int len)
	{
		info = new char[len];

		for (unsigned int i = 0; i < len; i++)
		{
			info[i] = _info[i];
		}
	}

};






#endif