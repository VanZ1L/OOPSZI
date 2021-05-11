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
	// �����������
	Queue()
	{
		front = NULL;
		rear = NULL;
		mSize = 0;
	}
	// ����������� �����������
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
	// ����������� �����������
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
			std::cout << "������� ������" << endl;
			return INT_MIN;
		}
		// ���� ����� ������� ��������� ����
		int value; // �������� ������� ���������
		if (this->front == this->rear)
		{
			value = this->front->data;
			delete this->front;
			this->front = NULL;
			this->rear = NULL;
		} // ���� � ������� ������ ��� 1 ����
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
	int Peek() const
	{
		return this->front->data;
	}
	//operations
	friend std::ostream& operator<<(std::ostream& out, const Queue& q)
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
	// �������� ������� �������
	Queue* q = new Queue;

	// ������� ���������
	q->Push(1);
	q->Push(2);
	q->Push(3);
	q->Push(13);
	q->Push(23);
	q->Push(33);
	// �������� �������
	std::cout << "\n | ������ ������� = " << q->Peek();
	// �������� �������
	q->displayQueue();

	// �������� ��������� �� �������
	std::cout << "\n | ������� 3 �������� � ������: ";
	q->Pop(); q->Pop(); q->Pop();
	// ��������� �������� �������
	std::cout << *q;

	q->Push(9);
	q->Push(20);
	q->displayQueue();
	std::cout << "\n | ������ ������� = " << q->GetSize();
	delete q;
	std::cout << std::endl;
	system("pause");
	return 0;
}
