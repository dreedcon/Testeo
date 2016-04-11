//--------------------------------------------------
//Array que se realocata dinamicamente   -----------
//--------------------------------------------------
#ifndef _P2DYNARRAY_H_
#define _P2DYNARRAY_H_

#include "Utilities.h"
#include <assert.h>

#define DYN_ARRAY_BLOCK_SIZE 16

template <class VAR>
class p2DynArray
{

private:
	//propiedades ---------------------------------------------------- 
	
	VAR* data = nullptr;
	uint mem_capacoty = 0;
	uint num_elements = 0;

	//funcion para allocatar un nuevo tamaño para el array y copia todas las datas
	void Alloc(uint _capacity)
	{
		VAR* tmp = data;
		data = new VAR[_capacity];

			mem_capacoty = _capacity;
		    num_elements = MIN(mem_capacoty, num_elements);

			for (uint i = 0; i < num_elements; ++i)
			{
				data[i] = tmp[i];
			}
			RELEASE_ARRAY(tmp);
	}

public:

	//constructors ------------------------------------------------
	
	//alocata una capacidad generica
	p2DynArray()
	{
		Alloc(DYN_ARRAY_BLOCK_SIZE);
	}

	//allocata una capacidad que nostros le pasamos 
	p2DynArray(uint capacity)
	{
		Alloc(capacity);
	}

	//Destructor -----------------------------------------------------
	~p2DynArray()
	{
		RELEASE_ARRAY(data);
	}


	//operators ------------------------------------------------------
	
	//buscamos uno de los elementos y devolvemos una referencia
	VAR& operator[](uint index)
	{
		assert(index < num_elements);
		return data[index];
	}

	const VAR& operator[](uint index) const
	{
		assert(index < num_elements);
		return data[index];
	}

	//cogemos un elemento y lo sumamos e igualamos osea si tenemos hola y mundo, al final tendremos holamundo
	const p2DynArray<VAR>& operator+=(const p2DynArray<VAR>& array)
	{
		if (num_elements + array.num_elements > mem_capacoty)
		{
			Alloc(num_elements + array.num_elements);
		}
	    
		for (uint i = 0; i < array.num_elements; ++i)
		{
			data[num_elements++] = array.data[i];
		}
	
		return(*this);
	}
	 
	//data management-------------------------------------------------

	//añade uno al final
	void push_back(const VAR& element)
	{
		if (num_elements >= mem_capacoty)
		{
			Alloc(mem_capacoty + DYN_ARRAY_BLOCK_SIZE);
        }
		
		data[num_elements++] = element;
	}

	//elimina uno del final te retorna la data y un true si lo ha borrado
	bool pop_back(VAR& result)
	{
		if (num_elements == 0)
		{
			return false;
		}
		else
		
		return result = num_elements--;
		return true;

	}

	//elimina un elemento en la posicion que deseamos o una lista de elementos
	bool erase(uint index)
	{
		if (index < num_elements)
		{
			for (uint i = index; i < num_elements - 1; ++i)
			{
				data[i] = data[i + 1];
			}
			--num_elements;

			return true;
		}
		return false;
	}

	//añade un elemento en la posicion que le digas
	bool insert(uint position, const VAR& element)
	{
		if (position > num_elements)
			return false;

		if (position == num_elements)
		{
			push_back(element);
			return true;
		}

		if (num_elements+1 > mem_capacoty)
			Alloc(mem_capacoty + DYN_ARRAY_BLOCK_SIZE);

		for (int i = position; i < num_elements; i++)
		{
			data[i] = data[i - 1];

		}
			data[position] = element;
			++num_elements;
			return true;
		
		return false;
	}
   
	//añade otra matriz dentro de otra matriz
	bool insert(const p2DynArray<VAR>& array, uint position)
	{
		if (position > num_elements)
			return false;

		if (num_elements + array.num_elements > mem_capacoty)
			Alloc(num_elements + array.num_elements + DYN_ARRAY_BLOCK_SIZE);

		for (uint i = position; i < position + array.num_elements; ++i)
		{
			data[i + array.num_elements] = data[i];
			data[i] = array[i - position];
			++num_elements;
		}

	}

	//at devuelve la data del que le decimos que visite
	VAR* at(uint index)
	{
		if (index < num_elements)
		return &data[index];

		return nullptr;
	}
	
	//lo mismo que el anterior pero devuelve una referencia constante
	const VAR* at(uint index) const
	{
		if (index < num_elements)
			return &data[index];

		return nullptr;
	}

	//cambia dos sus posciones desde el principio hasta el final
	void flip()
	{
		VAR* start = &data[0];
		VAR* end = &data[num_elements - 1];

		while (start < end)
		{
			SWAP(*start++, end--);
		}
	}

	uint find(const VAR& value)
	{
		uint i = 0;
		while (i < num_elements)
		{
			if (data[i] == value)
				break;
			i++;
		}
		return i;
	}

	//devuelve una referencia de la primera posicion
	VAR* front()
	{ 
		if (num_elements > 0)
		return &(data[0]);

		return nullptr;
	}

	//devuelve una referencia constante al primer puntero
	const VAR* front() const
	{
		if (num_elements > 0)
			return &(data[0]);

		return nullptr;
	}

	//devuelve una referencia al ultimo puntero
	VAR* back()
	{
		if (num_elements > 0)
			return &data[num_elements - 1];
		return nullptr;
	}

	//devuelve una referencia constante al ultimo puntero
	const VAR* back()const
	{
		if (num_elements > 0)
			return &data[num_elements - 1];
		return nullptr;
	}
	
	//vacia el array dinamico
	void clear()
	{
		data[0] = '\0';
	}

	//ordenation metodes ---------------------------------------------------

	//sort -----------------------------------------------------------------
	
	//el bubblesort va mirando las datas de los elementos y cuando ve que uno es mas grande que el anterior los cambia
	int BubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			//iteramos por el array visitando todos los elementos
			for (unsigned int i = 0; i < num_elements - 2; ++i)
			{
				++ret;
				if (data[i] > data[i + 1])
				{
					SWAP(data[i], data[i + 1]);
					swapped = true;
				}
			}
		}

		return ret;
	}

	int BubbleSortOptimized()
	{
		int ret = 0;
		unsigned int count;
		unsigned int last = num_elements - 2;

		while (last > 0)
		{
			count = last;
			last = 0;
			for (unsigned int i = 0; i < count; ++i)
			{
				++ret;
				if (data[i] > data[i + 1])
				{
					SWAP(data[i], data[i + 1]);
					last = i;
				}
			}
		}
		return ret;
	}
	
	int CombSort()
	{
		int ret = 0;
		bool swapped = true;
		int gap = num_elements - 1;
		float shrink = 1.3f;

		while (swapped || gap > 1)
		{
			gap = MAX(1, gap / shrink);

			swapped = false;
			for (unsigned int i = 0; i + gap < num_elements - 1; ++i)
			{
				++ret;
				if (data[i] > data[i + gap])
				{
					SWAP(data[i], data[i + gap]);
					swapped = true;
				}
			}
		}

		return ret;
	}
	
	//utilities-------------------------------------------------------------
	
	//te devuelve la capacidad
	uint capacity()
	{
		return mem_capacoty;
	}

	//te devuelve el numero de elementos que hay
	uint size()
	{
		return num_elements;
	}

	//te dice si esta vacia o no
	bool empty()const
	{
		return (num_elements == 0);
	}
};






#endif