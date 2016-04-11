#include "Linked_List.h"

#ifndef Branch
#define Branch



template<class data>
class NodeTree
{

public:

	//atributes
    data value;
	NodeTree* father;
	List<NodeTree*> sons;

	//Constructors
	NodeTree(data _value, NodeTree<data>* _father){ value = _value; father = _father; }
	NodeTree(data _value){ value = _value; father = NULL; }
	

	//methods
	void PreorderRecursive(List<data>* list)
	{
		list->Add(value);
		node<NodeTree*>* tmp = sons.getfirst();

		while (tmp != NULL) 
		{
			tmp->value->PreorderRecursive(list);
			tmp = tmp->next;
		}
	}

	void InorderRecursive(List<data>* list)
	{
		Node<NodeTree*>* tmp = sons.start;
		unsigned int Count = sons.Count() / 2;

		for (int i = 0; i < Count; i++)
		{
			tmp = tmp->next;
			tmp->next->InorderRecursive(list);
		}

		list->Add(value);
		for (tmp != NULL; tmp = tmp->next)
		{
			tmp->next->InorderRecursive(list);
		}


	}

	void PostorderRecursive(List<data>* list)
	{
		Node<NodeTree*>* tmp = sons.start;
		while (tmp != NULL)
		{
			tmp->next->PostorderRecursive(list);
			tmp = tmp->next;
		}

		list->Add(this);
	}


};



template<class data>
class Tree
{
public:
	//Atributes
	NodeTree<data>* first;

	//constructor
	Tree(data value){ firts = new NodeTree < data >; first->data = data; }
	Tree(){ first = NULL; }

	//Destructor
	~Tree(){ delete first; }

	//Methods
	NodeTree<data>* Add(const data& value)
	{
		NodeTree<data>* nodeAdd = new NodeTree<data>(value, first);
		nodeAdd->value = value;
		first->sons.Add(nodeAdd);
		return nodeAdd;
	}

	NodeTree<data>*Add(const data newvalue, NodeTree<data>* newNode)
	{
		NodeTree<data>* nt = new NodeTree<data>(newvalue, newNode);
		newNode->sons.Add(nt);
		return nt;
	}

	//recursives
	void TreePreorderRecursive(List<data>* list)
	{

		first->PreorderRecursive(list);
	}

	void TreeInorderRecursive(List<data>* list)
	{

		first->InorderRecursive(list);
	}

	void TreePostorderRecursive(List<data>* list)
	{
		first->PostorderRecursive(list);

	}
	
	void Show(List<data>* list)
	{
		node<NodeTree<data>*>*node1 = list->getstart();
		while (node1 = NULL)
		{
			printf("%s", node1->data);
			node1 = node1->next;
         }

	}
};

#endif

