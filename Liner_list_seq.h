#ifndef LINERLISTSEQ_H
#define LINERLISTSEQ_H
#include <memory>
#include <functional>
typedef std::size_t size;

template<typename Node> struct LinerList_seq{
public:
	//һ�㹹�캯����������Ϊ0������Ϊ10
	LinerList_seq(size n = 10):length(0),step(n){
		std::allocator<Node> p;
		head = p.allocate(step);
		size_ = step;
	}
	//���������������Ĺ��캯���汾������������ڴ��ݵĵ���������
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

	//�����������һ���ڵ㣬������ռ䲻��ʱ�������·���ռ䣬���䲽��Ϊstep����ʱ����ռ��Сsize_Ϊsize_+step����ԭ�ռ����ݸ�ֵ���ռ䣬������Ԫ�ز��뵽�������
	void add_Node(Node node);

	//ɾ�������n��Ԫ�أ����ظ�Ԫ��ֵ
	Node delete_n(size n);

	//����Ԫ�أ��ҵ��򷵻ط���Ҫ��ĵ�һ��Ԫ�ص�ָ�룬���򷵻�NULL
	Node *find_(Node no1,std::function<bool(Node n1,Node n2)> compare_);

	//����Ԫ�أ��ҵ����з���Ҫ���Ԫ�صģ�����ָ���һ��Ԫ�صĵ�����
	//virtual Node &find(Node no1,std::function<bool(Node n1,Node n2)> compare_);

	//��������ĵ�n��Ԫ�ص�ֵ
	Node check(size n){
		return *(head+n-1);
	}

	//���ر�ͷ
	const Node *get_head(void ){
			return head;
		}

	//���ò���
	void set_step(size n){
		step = n;
	}

	//���ز���
	size get_step(void){
		return step;
	}

	//����������
	size get_length(void){
		return length;
	}

	//�鿴�����Ƿ�Ϊ��
	bool isempty(void){
		return (length ==0)
	}

	//���������С
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