#include "Class_linked_list.h"

#ifndef Branch
#define Branch

template<class Thing>

class NodeTree
{

public:
	
	//atributes
	Thing another;
	NodeTree* father;
	Class_linked_list < NodeTree* > sons;

	//Constructors
	NodeTree(Thing _another, NodeTree<Thing>* _father){ data = data; father = _father; }
	NodeTree(Thing _another){ another = _another; father = NULL; }

	//methods
	void PreorderRecursive( Class_linked_list<thing*>* list )
	{
		list->Add(this);
		Node<NodeTree*>* tmp = sons.getstart;

		while (tmp != NULL)
		{
			tmp->thing->PreorderRecursive(List);
			tmp = tmp->next;
		}
	}

	void InorderRecursive( Class_linked_list<thing*>* list )
	{
		Node<NodeTree*>* tmp = sons.getstart();
		unsigned int Count = sons.Count() / 2;

		for (int i = 0; i < Count; i++)
		{
			tmp = tmp->next;
			tmp->thing->InorderRecursive(list);
		}
        
		list->Add(this);
		for (tmp != NULL; tmp = tmp->next)
		{
			tmp->thing->InorderRecursive(list);
		}
	    
	
	}
    
	void PostorderRecursive(Class_linked_list<thing*>* list)
	{
		Node<NodeTree*>* tmp = sons.getstart();
		while (tmp != NULL)
		{
			tmp->thing->PostorderRecursive(list);
			tmp = tmp->next;
		}
		
		list->Add(this);
	}


};


template<class Thing>
class Tree
{
	//Atributes
	NodeTree<thing>* first;
	
	//constructor
	Tree(Thing another){ firts = new NodeTree < Thing > ; first->thing = thing; }

	//Destructor
	~Tree(){ delete first; }

	//Methods
	NodeTree<Thing>* Add(const Thing& another)
	{
        NodeTree<Thing>* nodeAdd = new NodeTree<Thing>(another, first);
		first->sons.Add(nodeAdd);
		return nodeAdd;
     }

	NodeTree<Thing>*Add(const Thing newanother, NodeTree<Thing>* newNode)
	{
		NodeTree<Thing>* nt = new NodeTree<Thing>(newData, newNode);
		newNode->sons.Add(nt);
		return nt;
     }

	//recursives
	void TreePreorderRecursive
	{
	
		first->PreorderRecursive(List);
	}

	void TreeInorderRecursive(List);
	{

		first->InorderRecursive(List);
	}

	void TreePostorderRecursive
	{
		first->PostorderRecursive(List);

	}
	void show
	{
		node<NodeTree<Thing>*>* node1 = list->getstart();
		while (node1 = NULL)
		{
			printf("%s", node1->thing);
			node1 = node1->next;

		}

	}
};

#endif



