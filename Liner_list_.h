#ifndef LINERLIST__H
#define LINERLIST__H

typedef std::size_t size_;

template<typename Node> class liner_list_;
template<typename Node> struct  Node_struct
{
	friend liner_list_<Node>;
	Node node;
	Node* forward_;
	Node* next;
};

template<typename Node> class liner_list_{
public:
	liner_list_():length=0,head(NULL),tail(head){}//默认构造函数

	Node_struct* add(Node node){
		//Node_struct temp_node;
		//temp_node.node = node;
		if (head == NULL)
		{
			head->node = node;
			head->forward_ = NULL;
			
			tail->node = head->node;
			head->next = tail->node;
			tail->forward_ = head->node;
			tail->next = NULL;
		}
		*(tail->next) = node;
		*(tail->forward)_ = tail->node;
		tail->node = node

	}


private:
	Node_struct* head;
	Node_struct* tail;
	size_ length;
};

#endif