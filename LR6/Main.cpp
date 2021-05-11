#include <iostream>
using namespace std;

template<typename T>
class Base
{
public:
	virtual void Push(const T& value) {}
	virtual T Pop() { return 0; }
	virtual T Peek() { return 0; }
	virtual int GetSize() { return 0; }
	virtual void displayQueue() {}
};

template<typename T>
class Queue : Base<T>
{
public:
	Queue();
	Queue(const Queue& other);
	Queue(Queue&& other);
	~Queue();

	int GetSize();
	void Push(T data); // push_back
	T Pop(); // pop_front
	T Peek();
	bool empty();
	void displayQueue();
	friend std::ostream& operator<<(std::ostream& out, const Queue& q)
	{
		Node<T>* temp = q.head_;
		out << "\n Элементы в очереди: ";
		while (temp->pNext_ != NULL)
		{
			out << temp->data_ << " ";
			temp = temp->pNext_;
		}
		out << temp->data_ << " ";
		return out;
	};
	Queue<T>& operator=(const Queue<T>& other);
	Queue<T>& operator=(Queue<T>&& other);

private:
	template<typename T>
	class Node
	{
	public:
		Node(T data, Node* pNext = NULL, Node* pPrev = NULL)
		{
			data_ = data;
			pNext_ = pNext;
			pPrev_ = pPrev;
		}

		Node* pNext_;
		Node* pPrev_;
		T data_;
	};

	void pop_front();
	void push_front(T data);
	Node<T>* head_;
	Node<T>* tail_;
	int size_;
};

template<typename T>
Queue<T>::Queue()
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
}

template<typename T>
Queue<T>::Queue(const Queue& other)
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
	Node<T>* temp = new Node<T>();
	while (temp->pNext_ != other.tail_)
	{
		Push(temp->data_);
		temp = temp->pNext_;
	}
	Push(temp->data_);
}

template<typename T>
Queue<T>::Queue(Queue&& other)
{
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
	Node<T>* temp = new Node<T>();
	while (temp->pNext_ != other.tail_)
	{
		Push(other.Pop());
		temp = temp->pNext_;
	}
	Push(temp->data_);
}

template<typename T>
Queue<T>::~Queue()
{
	while (size_)
		pop_front();
}
template<typename T>
void Queue<T>::push_front(T data)
{
	head_ = new Node<T>(data, head_, NULL);
	size_++;
}
template <typename T>
void Queue<T>::Push(T data)
{
	if (head_ == NULL)
	{
		head_ = new Node<T>(data);
		tail_ = head_;
	}

	else
	{
		tail_->pNext_ = new Node<T>(data, NULL, tail_);
		tail_ = tail_->pNext_;
	}

	size_++;
}
template <typename T>
void Queue<T>::pop_front()
{
	Node<T>* temp = head_; // Запоминаем адрес головного элемента
	head_ = head_->pNext_; // Смещаем голову списка на следующий узел
	delete temp; // Удаляем предыдущий за головой узел
	size_--;
}

template <typename T>
T Queue<T>::Pop()
{
	Node<T>* temp = head_;
	T value = temp->data_;
	head_ = head_->pNext_;
	delete temp;
	size_--;
	return value;
}

template <typename T>
T Queue<T>::Peek()
{
	return head_->data_;
}

template <typename T>
int Queue<T>::GetSize()
{
	return size_;
}

template <typename T>
bool Queue<T>::empty()
{
	if (size_)
		return false;
	else
		return true;
}
template <typename T>
void Queue<T>::displayQueue()
{
	Node<T>* temp = head_;
	std::cout << "\n Элементы в очереди: ";
	while (temp->pNext_ != NULL)
	{
		std::cout << temp->data_ << " ";
		temp = temp->pNext_;
	}
	std::cout << temp->data_ << " " << std::endl;
}
template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T>& other)
{
	if (this == &other)
		return *this;
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
	Node<T>* temp = new Node<T>();
	while (temp->pNext_ != other.tail_)
	{
		Push(temp->data_);
		temp = temp->pNext_;
	}
	Push(temp->data_);
}
template <typename T>
Queue<T>& Queue<T>::operator=(Queue<T>&& other)
{
	if (this == &other)
		return *this;
	head_ = NULL;
	tail_ = NULL;
	size_ = 0;
	Node<T>* temp = new Node<T>();
	while (temp->pNext_ != other.tail_)
	{
		Push(other.Pop());
		temp = temp->pNext_;
	}
	Push(temp->data);
}


// Тестовый пример
int main()
{
	setlocale(LC_ALL, "rus");

	Queue<int>* q = new Queue<int>;
	Queue<int>* qc;

	// Вставка элементов
	q->Push(1);
	q->Push(2);
	q->Push(3);
	q->Push(13);
	q->Push(23);
	q->Push(33);

	std::cout << "\n | Первый элемент = " << q->Peek() << std::endl;

	q->displayQueue();

	std::cout << "\n | Удаляем 3 элемента с начала: ";
	q->Pop();
	q->Pop();
	q->Pop();

	std::cout << *q << std::endl;

	q->Push(9);
	q->Push(20);

	q->displayQueue();
	std::cout << "\n | Размер очереди = " << q->GetSize();

	std::cout << std::endl;

	qc = q;

	qc->displayQueue();

	system("pause");

	return 0;
}

