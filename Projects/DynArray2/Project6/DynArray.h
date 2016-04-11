#define MIN(a,b) (a<b ? a:b)
#define MAX(a,b) (a>b? a:b)

template<class num>
class DynArray
{

private:

	num* data;
	unsigned int allocated_memory;
	unsigned int num_elements;

public:

	DynArray(num mem_size){ Reallocate(mem_size); num_elements = 0; }
	DynArray(){ data = NULL; allocated_memory = 0; num_elements = 0; }
	void reallocated(num new_memory_size){}
	~DynArray(){ delete[] data; }
	unsigned int getallocated_memory()const{ return allocated_memory; }
	unsigned int getnum_elements()const{ return num_elements; }

	void Reallocate(unsigned int mem)
	{
		num* tmp = data;

		allocated_memory = mem;
		data = new num[allocated_memory];

		if (num_elements > allocated_memory)
		{
			num_elements = allocated_memory;
		}

		if (tmp != NULL)
		{
			for (unsigned int i = 0; i < num_elements; ++i)
			{
				data[i] = tmp[i];
			}

			delete[] tmp;
		}
	}

	void push_back(num value)
	{
		if (num_elements < allocated_memory)
		{

			num_elements++;
		}
		else
		{
			Reallocate(allocated_memory + 1);
		}
		data[num_elements - 1] = value;
	}
	void Pop()
	{
		if (num_elements >= 1)
			num_elements = 1;
	}

	bool insert(num value, num position)
	{
		if (position > num_elements)
		{
			return  false;
		}

		if (position == num_elements)
		{
			push_back(num_elements);
			return true;
		}
		for (num i = num_elements; i > position; i--)
		{
			data[1] = data[i - 1];
		}
		data[position] = num_elements;
		++num_elements;
		return true;
	}

	num& operator[](num index)
	{
		assert(index < num_elements);
		return data[index];
	}

	num& operator[](int index)const
	{
		assert(index < num_elements);
		return data[index];
	}
};
