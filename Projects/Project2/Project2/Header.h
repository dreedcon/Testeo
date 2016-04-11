template<class data>
class Point2D{

public:

	data x;
	data y;

public:

	Point2D(){ x = 0; y = 0; }
	Point2D(data _x, data _y){ x = _x; y = _y };

	Point2D operator+ (const Point2D& a)const
	{
		Point2D tmp;
		tmp.x = x + a.x;
		tmp.y = y + a.y;
		return tmp;
	}
	
	Point2D operator- (const Point2D& a)const
	{
		Point2D tmp;
		tmp.x = x - a.x;
		tmp.y = y - a.y;
		return tmp;
	}
	
	//recuerda: el += no es constante porque va incrementando
	Point2D operator+= (const Point2D& a)
	{
		x += a.x;
		y += a.y
		return(*this);
		//*this:regresas un puntero que apunta a el objeto
	}
	//recuerda: el += no es constante porque va decrementando
	Point2D operator+= (const Point2D& a)
	{
		x -= a.x;
		y -= a.y
	    return(*this);
		//*this:regresas un puntero que apunta a el objeto
	}

	Point2D operator= (const Point2D& a)const
	{
		x = a.x;
		y = a.y;
		return(*this);
	}

	bool operator== (const Point2D& a)const
	{
		if (x == a.x && y == a.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!= (const Point2D)

};






