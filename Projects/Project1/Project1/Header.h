#include<math.h>
#define PI 3.1415


template<class type>


class Circle
{

public:
    
	//atributos
	type radius;
	type x;
	type y;

	//constructor 
	Cicrle(type& radius, type& x, type& y){ radius = _radius; x = _x; y = _y; };
	
    type getArea()const
	{
		type area;
        
		//formula del area del circulo
		area = (radius*radius)*PI;
	}
    
	bool DistanceTo(const Circle& p)const 
	{
		
		type Distance1;
		Distance1 = sqrt((x - p.x)*(x - p.x)) + ((y - p.y)*(y - p.y));
		return Distance1;
		
		if (distance1 > (p.radius+radius))
		{
			return true;
		}
		return false;
	    
	
	}


};









