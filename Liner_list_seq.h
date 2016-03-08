#ifndef LINERLISTSEQ_H
#define LINERLISTSEQ_H
#include <memory>
#include <functional>
typedef std::size_t size;

template<typename Node> struct LinerList_seq{
public:
	//一般构造函数，链表长度为0，步长为10
	LinerList_seq(size n = 10):length(0),step(n){
		std::allocator<Node> p;
		head = p.allocate(step);
		size_ = step;
	}
	//传递两个迭代器的构造函数版本，步长必须大于传递的迭代器长度
	template<typename It> explicit LinerList_seq(It beg,It end,size n = 10):step(n){
		std::allocator<Node> p;
		head = p.allocate(step);
		size_ = step;
		std::uninitialized_copy(beg,end,head);
		step = n;
		length = 0;
		for (;beg!=end;beg++)
		{
			length++;
		}
	}

	//往链表里添加一个节点，当分配空间不足时，需重新分配空间，分配步长为step，此时链表空间大小size_为size_+step，将原空间数据赋值过空间，并将新元素插入到链表最后
	void add_Node(Node node);

	//删除链表第n个元素，返回该元素值
	Node delete_n(size n);

	//查找元素，找到则返回符合要求的第一个元素的指针，否则返回NULL
	Node *find_(Node no1,std::function<bool(Node n1,Node n2)> compare_);

	//查找元素，找到所有符合要求的元素的，返回指向第一个元素的迭代器
	//virtual Node &find(Node no1,std::function<bool(Node n1,Node n2)> compare_);

	//常看链表的第n个元素的值
	Node check(size n){
		return *(head+n-1);
	}

	//返回表头
	const Node *get_head(void ){
			return head;
		}

	//设置步长
	void set_step(size n){
		step = n;
	}

	//返回步长
	size get_step(void){
		return step;
	}

	//返回链表长度
	size get_length(void){
		return length;
	}

	//查看链表是否为空
	bool isempty(void){
		return (length ==0)
	}

	//返回链表大小
	size get_size(void){
		return size_;
	}

	//add_element(T t)
private:
	Node* head;
	size length;
	size size_; 
	size step;
};
//template<typename Node>	virtual Node &LinerList_seq<Node>::find(Node no1,std::function<bool(Node n1,Node n2)> compare_){
//
//	return NULL;
//}
template<typename Node> Node *LinerList_seq<Node>::find_(Node no1,std::function<bool(Node n1,Node n2)> compare_){
	Node *temp = head;
	while(temp != head+length)
		if (compare_(*(temp++) ,no1) )
		{
			return --temp;
		}
		return NULL;
}

template<typename Node> Node LinerList_seq<Node>::delete_n(size n){
	if (n > length)
	{
		std::cerr << "out of range";
		return NULL;
	}
	std::allocator<Node> p;
	Node temp = check(n);
	Node *de = head+n-1;
	p.destroy(de);
	for (;n<length;n++)
	{
		*de = *(de+1);
		de++;
	}
	p.destroy(de);
	length--;
	return temp;
}

template<typename Node> void LinerList_seq<Node>::add_Node(Node node){
	std::allocator<Node> p;
	if (length == size_){			
		Node* head_temp = p.allocate(size_+step);
		std::uninitialized_copy(head, head+length, head_temp);

		for (Node* t = head; t <= head+length;t++)
		{
			p.destroy(head);
		}
		head = head_temp;
		size_ = size_ + step;
	}
	p.construct(head+length, node);
	length++;
}

#endif