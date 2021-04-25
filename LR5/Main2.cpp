#include <iostream>
using namespace std;

template<typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		struct Node * link;
	};
	struct Node *front, *rear;
	int mSize;
public:
	// �����������
	Queue()
	{
		front = NULL;
		rear = NULL;
		mSize = 0;
	}
	// ����������� �����������
	Queue(const Queue &other)
	{
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			enQueue(temp->data);
			temp = temp->link;
		}
		enQueue(temp->data);
	}
	// ����������� �����������
	Queue(Queue &&other)
	{
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			enQueue(other.deQueue());
			temp = temp->link;
		}
		enQueue(temp->data);

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
	void enQueue(const T &value)
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
	T deQueue()
	{
		if (this->front == NULL)
		{
			std::cout << "������� ������" << endl;
			return INT_MIN;
		}
		// ���� ����� ������� ��������� ����
		T value; // �������� ������� ���������
		if (this->front == this->rear)
		{
			value = this->front->data;
			delete this->front;
			this->front = NULL;
			this->rear = NULL;
		} // ���� � ������� ������ ��� 1 ����
		else{
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
		std::cout << "\n �������� � �������: ";
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
	T Peek() const
	{
		return this->front->data;
	}
	//operations
	friend std::ostream& operator<<(std::ostream &out, const Queue &q)
	{
		struct Node* temp = q.front;
		out << "\n �������� � ��������� �������: ";
		while (temp->link != q.front)
		{
			out << temp->data << " ";
			temp = temp->link;
		}
		out << temp->data << " ";
		return out;
	};
	// operator
	Queue &operator=(const Queue &other)
	{
		if (this == &other)
			return *this;
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			enQueue(temp->data);
			temp = temp->link;
		}
		enQueue(temp->data);
	}
	Queue &operator=(Queue &&other)
	{
		if (this == &other)
			return *this;
		front = NULL;
		rear = NULL;
		mSize = 0;
		struct Node* temp = new Node;
		while (temp->link != other.front)
		{
			enQueue(other.deQueue());
			temp = temp->link;
		}
		enQueue(temp->data);
	}
};

//std::ostream& operator<< (std::ostream &out, const Queue &q)

/* Driver of the program */
int main()
{
	setlocale(LC_ALL, "rus");
	// �������� ������� �������
	Queue<double> *q = new Queue<double>;

	// ������� ���������
	q->enQueue(1.1);
	q->enQueue(2.1);
	q->enQueue(3.1);
	q->enQueue(13.2);
	q->enQueue(23.2);
	q->enQueue(33.2);
	// �������� �������
	std::cout << "\n | ������ ������� = " << q->Peek();
	// �������� �������
	q->displayQueue();

	// �������� ��������� �� �������
	std::cout << "\n | ������� 3 �������� � ������: ";
	q->deQueue(); q->deQueue(); q->deQueue();
	// ��������� �������� �������
	std::cout << *q;

	q->enQueue(9);
	q->enQueue(20);
	q->displayQueue();
	std::cout << "\n | ������ ������� = " << q->GetSize();
	delete q;
	std::cout << std::endl;
	system("pause");
	return 0;
}
