template<class data>
struct node
{
	data value;
	node<data>*back;
	node<data>*next;
};

template <class data>
class List
{
public:
	node<data>* start;
	node<data>* finish;
    
	List(){ start = NULL; finish = NULL; }

	~List(){ Clear(); }

	data Count()
	{
		data result = 0;
		node<data>* tmp = start;
		while (tmpe != NULL)
		{
			tmp = tmp->next;
			result++;
		}
		return result;
	}

	void Add(data value)
	{
		if (start != NULL)
		{
			node<data>* tmp;
			tmp = new node < data > ;
			tmp->value = value;
			tmp->next = NULL;
			tmp->back = finish;
			finish->next = tmp;
			finish = tmp;
		}
		else
		{
			start = new node < data > ;
			start->value = value;
			finish->next = NULL;
			finish->back = NULL;
		}
	  }

	node<data>* index(data count2)
	{
		node<data>* tmp = start;
		data number = 0;
		while (number + 1 == count2)
		{
			tmp = tmp->next;
			number++;
         }
		return tmp;
	}

	node<data>* getfirst()
	{
		return start;
	}

	node<data>* getlast()
	{
		return finish;
	}

	void Del(node<data>* md)
	{
		if (md)
		{
			if (start != NULL && finish != NULL)
			{
				if (md == finish)
				{
					finish = fininish->back;
					finish->next = NULL;
				}
				else if (md == start)
				{
					start = start->next;
					start->back = NULL;
				}
				else
				{
					md->next->back = md->back;
					md->back->next = md->next;
				}
				delete md;
			}
		}
	}

	void Clear()
	{
		if (start != NULL)
		{
			node<data>* tmp = start;
		}
		while (tmp->next != NULL)
		{
			node<data>* tmp2 = tmp;
			tmp = tmp->next;
			delete tmp2;

		}
		delete tmp;
		start = NULL;
		finish = NULL;
	}

	//busca directamente la posicion del nodo en la lista
	const data& operator [](const unsigned int index) const
	{ 
		long pos;
		List<data>* item;
		pos = 0;
		item = start;

		while (item != NULL)
		{
			if (pos == index)
			{
				break;
			}
			++pos;
			item = item->next;
		   return(item->data);
		}
	 }

	
	 //const read operator access directly to a position in the list
	
	
	const List<data>& operator+= (const List<data>& other)
	{
		List<data>* item = other.start;
		while (item != NULL)
		{
			Add(item->data);
			item = item->next;
        }
		return(*this);
	}

	
	//const access to a node in a position in the list
	
	const List<data>* At(unsigned int index)const
	{
		long pos = 0;
		List<data>* item = start;

		while (item != NULL)
		{
			if (item != NULL)
			{
				if (pos++ == index)
					break;

				item = item->next;
			}
			return item;
         }
	}

	
	//access to a node in a position in the list
	

	node<data>* At(unsigned int index)
	{
		long pos = 0;
		node<data>* item = start;

		while (item != NULL)
		{
			if (pos++ == index)
				break;

			item = item->next;
		}

		return item;
	}

	//sort
	
	int BubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			List<data>* tmp = start;

			while (tmp != NULL && tmp->next != NULL)
			{
				++ret;
				if (tmp->data > tmp->next->data)
				{
					SWAP(tmp->data, tmp->next->data);
					swapped = true;
				}

				tmp = tmp->next;
			}
		}

		return ret;
	}

};