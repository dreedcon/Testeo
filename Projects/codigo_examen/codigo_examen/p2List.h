#ifndef __p2List_H__
#define __p2List_H__

#include "Utilities.h"

/**
* Manages a double linked list
*/
template<class TYPE>
class p2List
{
public:

	/**
	* Node implementation
	*/
	struct node
	{
		friend class p2List<TYPE>;
	public:
		mutable TYPE	data;

		inline node* next() const // hauria de ser const ho se
		{
			return nxt;
		}
		inline const node* prev() const
		{
			return prv;
		}

	private:
		node*   nxt = nullptr;
		node*   prv = nullptr;

		node(const TYPE& data) : data(data)
		{}

		/* mmm .... something to think about :)
		~node()
		{
		if(prv)
		prv->nxt = nullptr;
		if(nxt)
		nxt->prv = nullptr;
		}
		*/
	};

private:

	node*   start = nullptr;

public:

	// Constructors ------------------------------------------------------
	p2List(){}
	p2List(const p2List<TYPE>& new_list){

		node* new_node = new_list.start;
		while (new_node != NULL){
			this->push_back(new_node->data);
			new_node = new_node->next;
		}
	}
	// Destructor ---------------------------------------------------------
	~p2List()
	{
		clear();
	}

	// Operators ----------------------------------------------------------
	const p2List<TYPE>& operator +=(const p2List<TYPE>& list)
	{
		node* item = list.start;
		node* last = back_node();

		while (item != nullptr)
		{
			node* new_item = new node(item->data);

			if (last != nullptr)
			{
				new_item->prv = last;
				last->nxt = new_item;
			}
			else
				start = new_item;

			item = item->nxt;
			last = new_item;
		}

		return(*this);
	}

	// Data Management -----------------------------------------------------
	//Remove duplicate values
	void Unique(){
		p2List<TYPE>* new_list(this);
		node* tmp1 = new_list->start;
		node* tmp = start;
		TYPE data;
		while (tmp1 != NULL){
			data = tmp1->data;
			tmp = start;
			int position = 1;
			int i = 0;
			while (tmp != NULL){
				int j = 0;
				if (data == tmp->data && i <= 0){
					i++;
				}
				else if (data == tmp->data && i >= 0){
					tmp = tmp->nxt;
					j++;
					this->Remove(position);
				}
				if (j <= 0){
					tmp = tmp->nxt;
					position++;
				}
			}
			tmp1 = tmp1->nxt;
		}

	}

	//Change node from a list to another list
	void Splice(int position_to_insert, int position_to_remove, p2List<TYPE>& list){
		const node* tmp = NULL;
		tmp = list.Remove(position_to_remove);
		this->Insert(position_to_insert, tmp->data);

	}

	const p2List& Swap(){
		node* tmp = start;
		node* tmp1 = start;
		while (tmp1->nxt){
			tmp1 = tmp1->nxt;
		}
		TYPE save_data;
		int i = 0;
		while (i < this->size() / 2){
			save_data = tmp1->data;
			tmp1->data = tmp->data;
			tmp->data = save_data;
			tmp = tmp->nxt;
			tmp1 = tmp1->prv;
			i++;
		}

		return (*this);
	}

	node* push_back(const TYPE& data)
	{
		node* item = new node(data);
		node* last = back_node();

		if (last != nullptr)
		{
			item->prv = last;
			last->nxt = item;
		}
		else
			start = item;

		return item;
	}

	node* push_front(const TYPE& item)
	{
		node* item = new node(item);

		if (start != nullptr)
		{
			item->nxt = start;
			start->prv = item;
		}

		start = item;

		return item;
	}

	bool pop_back(TYPE& data)
	{
		node* last = back_node();

		if (last != nullptr)
		{
			data = last->data;
			if (last->prv != nullptr)
				last->prv->nxt = nullptr;
			else
				start = nullptr;

			RELEASE(last);
			return true;
		}

		return false;
	}

	bool pop_front(TYPE& data)
	{
		if (start != nullptr)
		{
			data = start->data;
			node* second_node = start->nxt;
			RELEASE(start); // start is reset to nullptr inside RELEASE

			if (second_node != nullptr)
			{
				start = second_node;
				start->prv = nullptr;
			}
			return true;
		}
		return false;
	}

	void clear()
	{
		node*   item;
		node*   item_next;
		item = start;

		while (item != nullptr)
		{
			item_next = item->nxt;
			RELEASE(item);
			item = item_next;
		}

		start = nullptr;
	}

	node* Remove(uint position){
		node* new_node = new node(NULL);
		if (position > size()){
			printf("T'has passat\n");
		}
		else{
			node* tmp = start;
			if (tmp == NULL){
				printf("No hi ha llista\n");
			}
			else{

				for (uint i = 1; i < position; i++){
					tmp = tmp->nxt;
				}
				if (position == 1){
					if (tmp->nxt == NULL){
						start = NULL;
					}
					else{
						start = tmp->nxt;
						tmp->nxt->prv = NULL;
					}
					//node = tmp;
					new_node->data = tmp->data;
					delete tmp;
				}
				else if (position == size()){
					tmp->prv->nxt = NULL;
					//	node = tmp;
					new_node->data = tmp->data;
					delete tmp;
				}
				else{
					tmp->prv->nxt = tmp->nxt;
					tmp->nxt->prv = tmp->prv;
					//node = tmp;
					new_node->data = tmp->data;
					delete tmp;
				}
			}
		}
		return new_node;
	}

	bool erase(uint index)
	{
		node* item = at(index);


		if (item != nullptr)
		{
			if (item->nxt != nullptr)
				item->nxt->prv = item->prv;

			if (item->prv != nullptr)
				item->prv->nxt = item->nxt;
			new_node->data = item->data;
			RELEASE(item);
			return true;
		}
		return false;
	}

	bool erase(node* item)
	{
		if (item != nullptr)
		{
			if (item->nxt != nullptr)
				item->nxt->prv = item->prv;

			if (item->prv != nullptr)
				item->prv->nxt = item->nxt;

			RELEASE(item);
			return true;
		}
		return false;
	}

	bool Insert(uint position, const TYPE& new_data){

		if (position > size() + 1)
		{
			return false;
		}
		else
		{
			node* new_node = new node(new_data);
			node* tmp = start;

			if (position = size() + 1){
				position = size();
			}

			for (uint i = 1; i < position; i++){
				tmp = tmp->nxt;
			}
			if (start == NULL)
			{
				start = new_node;
				new_node->prv = NULL;
				new_node->nxt = NULL;
			}
			else if (tmp->nxt == NULL)
			{
				tmp->nxt = new_node;
				new_node->prv = tmp;
				new_node->nxt = NULL;
			}
			else{
				new_node->nxt = tmp;
				new_node->prv = tmp->prv;
				tmp->prv->nxt = new_node;
				tmp->prv = new_node;
			}
			return true;
		}
	}

	bool insert(const TYPE& data, uint position)
	{
		node* item = at_node(position);

		if (item != nullptr)
		{
			node* new_item = new node(data);
			new_item->nxt = item;
			new_item->prv = item->prv;

			if (new_item->prv != nullptr)
				new_item->prv->nxt = new_item;

			item->prv = new_item;
			return true;
		}

		return false;
	}

	bool insert(const p2List<TYPE>& list, uint position)
	{
		node* item = at_node(position);
		node* other_list = list.start;

		if (item != nullptr && other_list != nullptr)
		{
			// copy the whole list
			node* start_new_list = nullptr;
			node* end_new_list = nullptr;

			while (other_list != nullptr)
			{
				node* new_item = new node(other_list->data);

				if (start_new_list != nullptr)
				{
					new_item->prv = end_new_list;
					end_new_list->nxt = new_item;
				}
				else
					start_new_list = new_item;

				end_new_list = new_item;
				other_list = other_list->nxt;
			}

			// now exchange pointers
			end_new_list->nxt = item;
			start_new_list->prv = item->prv;

			if (start_new_list->prv != nullptr)
				start_new_list->prv->nxt = start_new_list;

			item->prv = end_new_list;

			return true;
		}
		return false;
	}

	TYPE* at(uint index)
	{
		uint counter = 0;
		node* item = start;

		while (item != nullptr)
		{
			if (counter++ == index)
				return &(item->data);
			item = item->nxt;
		}

		return nullptr;
	}

	const TYPE* at(uint index) const
	{
		uint counter = 0;
		node* item = start;

		while (item != nullptr)
		{
			if (counter++ == index)
				return &(item->data);
			item = item->nxt;
		}

		return nullptr;
	}

	node* at_node(uint index)
	{
		uint counter = 0;
		node* item = start;

		while (item != nullptr)
		{
			if (counter++ == index)
				return item;
			item = item->nxt;
		}

		return nullptr;
	}

	const node* at_node(uint index) const
	{
		uint counter = 0;
		node* item = start;

		while (item != nullptr)
		{
			if (counter++ == index)
				return item;
			item = item->nxt;
		}

		return nullptr;
	}

	// Utils ------------------------------------------------------------
	uint size() const
	{
		uint ret = 0;

		for (node* item = start; item != nullptr; item = item->nxt)
			++ret;

		return ret;
	}

	bool empty() const
	{
		return start == nullptr;
	}

	node* front_node()
	{
		return start;
	}

	const node* front_node() const
	{
		return start;
	}

	node* back_node()
	{
		node* item = start;
		node* last_item = nullptr;
		while (item != nullptr)
		{
			last_item = item;
			item = item->nxt;
		}

		return last_item;
	}

	const node* back_node() const
	{
		node* item = start;
		node* last_item = nullptr;
		while (item != nullptr)
		{
			last_item = item;
			item = item->nxt;
		}

		return last_item;
	}

	TYPE* front()
	{
		if (start != nullptr)
			return &(start->data);
		return nullptr;
	}

	const node* front() const
	{
		if (start != nullptr)
			return &(start->data);
		return nullptr;
	}

	TYPE* back()
	{
		node* item = start;
		node* last_item = nullptr;
		while (item != nullptr)
		{
			last_item = item;
			item = item->nxt;
		}

		return (last_item != nullptr) ? &(last_item->data) : nullptr;
	}

	const TYPE* back() const
	{
		node* item = start;
		node* last_item = nullptr;
		while (item != nullptr)
		{
			last_item = item;
			item = item->nxt;
		}

		return (last_item != nullptr) ? &(last_item->data) : nullptr;
	}

	// Sort -------------------------------------------------------------
	int BubbleSort()
	{
		int ret = 0;
		bool swapped = true;

		while (swapped)
		{
			swapped = false;
			node* tmp = start;

			while (tmp != nullptr && tmp->nxt != nullptr)
			{
				++ret;
				if (tmp->data > tmp->nxt->data)
				{
					SWAP(tmp->data, tmp->nxt->data);
					swapped = true;
				}

				tmp = tmp->nxt;
			}
		}

		return ret;
	}

};

#endif