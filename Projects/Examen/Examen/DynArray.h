#define DYN_ARRAY_BLOCK_SIZE 16

template<class value>
class DynArray
{

private:
	
	value* data;
	unsigned int capacity;
	unsigned int elements;

public:

	//constructures
	DynArray(){capacity=0, elements=0, data=NULL}
	DynArray(unsiged int){ capacity = 0; elements = 0; data = 0; }
	
	//destructores
	~DynArray(){ delete[] data; }

     //operators
	value& operator[](unsigned int index)const
	{
		if (index < elements)
		{
			return data[index];

		}
	}

	const value& operator[](unsigned int index)const
	{
		if (index < elements)
		{
			return data[index];
		}
	}
     
	//Data managements 

	void PushBack(const Value& element)
	{
		if (elements >= capacity)
		{
			Alloc(capacity + DYN_ARRAY_BLOCK_SIZE)
		}

		data[elements++] = element;
	}

	bool Pop(Value& result)
	{
		if (num_elements > 0)
		{
			result = data[--elements]
				return true;
		}
	     return false,
	}

	//pop de aleix y josep

	void Clear()
	{
		elements = 0;
	}

	
	bool insert(const Value& elements, unsigned int position)
	{
		if (position > elements)
			return false;
		
		if (position == element)
		{
			PushBack(elements)
				return true;
		}
		if (element + 1 > capacity)
			Alloc(capacity + DYN_ARRAY_BLOCK_SIZE);

		for (unsigned int i = element; i > poition; --i)
		{
			data[i] = data[i - 1];
			
		}
		data[position] = element;
		++num_elements;

		return truee;
	}



















};