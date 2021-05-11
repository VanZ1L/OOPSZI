#include <iostream>
using namespace std;


class Queue
{
private:
	struct Node
	{
		int data;
		struct Node* link;
	};
	struct Node* front, * rear;
	int mSize;
public:
	// Конструктор
	Queue()
	{
		front = NULL;
		rear = NULL;
		mSize = 0;
	}
	// конструктор копирования
	Queue(const Queue& other)
	{
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			Push(temp->data);
			temp = temp->link;
		}
		Push(temp->data);
	}
	// конструктор перемещения
	Queue(Queue&& other)
	{
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			Push(other.Pop());
			temp = temp->link;
		}
		Push(temp->data);

		other.front = nullptr;
		other.rear = nullptr;
		other.mSize = 0;
	}
	~Queue()
	{
		delete this->front;
		this->front = NULL;
		this->rear = NULL;
		/* delete this->rear; */

	}
	// Push
	void Push(const int& value)
	{
		struct Node* temp = new Node;
		temp->data = value;
		if (this->front == NULL)
			this->front = temp;
		else
			this->rear->link = temp;
		/*-----------------------------*/
		this->rear = temp;
		this->rear->link = this->front;
		mSize++;
	}
	// Pop
	int Pop()
	{
		if (this->front == NULL)
		{
			std::cout << "Очередь пустая" << endl;
			return INT_MIN;
		}
		// если нужно удалить последний узел
		int value; // значение которое удаляется
		if (this->front == this->rear)
		{
			value = this->front->data;
			delete this->front;
			this->front = NULL;
			this->rear = NULL;
		} // если в очереди больше чем 1 узел
		else {
			struct Node* temp = this->front;
			value = temp->data;
			this->front = this->front->link;
			this->rear->link = this->front;
			delete temp;
		}
		mSize--;
		return value;
	}
	void displayQueue()
	{
		struct Node* temp = this->front;
		std::cout << "\n Элементы в очереди: ";
		while (temp->link != this->front)
		{
			std::cout << temp->data << " ";
			temp = temp->link;
		}
		std::cout << temp->data << " ";
	}
	int GetSize() const
	{
		return mSize;
	}
	int Peek() const
	{
		return this->front->data;
	}
	//operations
	friend std::ostream& operator<<(std::ostream& out, const Queue& q)
	{
		struct Node* temp = q.front;
		out << "\n Элементы в кольцевой очереди: ";
		while (temp->link != q.front)
		{
			out << temp->data << " ";
			temp = temp->link;
		}
		out << temp->data << " ";
		return out;
	};
	// operator
	Queue& operator=(const Queue& other)
	{
		if (this == &other)
			return *this;
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			Push(temp->data);
			temp = temp->link;
		}
		Push(temp->data);
	}
	Queue& operator=(Queue&& other)
	{
		if (this == &other)
			return *this;
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			Push(other.Pop());
			temp = temp->link;
		}
		Push(temp->data);
	}
};


int main()
{
	setlocale(LC_ALL, "rus");
	// Создание объекта очереди
	Queue* q = new Queue;

	// Вставка элементов
	q->Push(1);
	q->Push(2);
	q->Push(3);
	q->Push(13);
	q->Push(23);
	q->Push(33);
	// Просмотр вершины
	std::cout << "\n | Первый элемент = " << q->Peek();
	// Просмотр очереди
	q->displayQueue();

	// Удаление элементов из очереди
	std::cout << "\n | Удаляем 3 элемента с начала: ";
	q->Pop(); q->Pop(); q->Pop();
	// Повторный просмотр очереди
	std::cout << *q;

	q->Push(9);
	q->Push(20);
	q->displayQueue();
	std::cout << "\n | Размер очереди = " << q->GetSize();
	delete q;
	std::cout << std::endl;
	system("pause");
	return 0;
}
