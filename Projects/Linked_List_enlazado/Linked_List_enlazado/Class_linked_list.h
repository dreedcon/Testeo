template<class data>
struct node
{
	data value;
    node<data>* back;
	node<data>* next;
};

template<class data>
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
		while (tmp != NULL)
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
			tmp = new node<data>;
			tmp->value = value;
		    tmp->next = NULL;
			tmp->back = finish;
			finish->next = tmp;
			finish = tmp;
		}
		else
		{
			start = new node<data>;
			start->value = value;
			finish = start;
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
					finish = finish->back;
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
	};

	void Clear()
	{
		if (start != NULL)
		{
			node<data>* tmp = start;

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
	}

};