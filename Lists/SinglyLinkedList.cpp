#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next = nullptr;
};
class List {
private:
	Node* head;
	Node* tail;
public:
	List()
	{
		this->head = this->tail = NULL;
	}
	void free()
	{
		Node* i = head;
		while (i != nullptr)
		{
			Node* next = i->next;
			delete i;
			i = next;
		}
		head = tail = NULL;
	}
	~List()
	{
		free();
	}
	void insertAtEnd(int value)
	{
		if (head == NULL)
		{
			head = new Node({ value });
			tail = head;
		}
		else
		{
			this->tail->next = new Node({ value, NULL });
			this->tail = this->tail->next;
		}
	}
	void insertAtStart(int value)
	{
		Node* newHead = new Node({ value, NULL });
		newHead->next = head;
		head = newHead;
		if (tail == NULL)
			tail = head;
	}
	void insertAt(int index, int value)
	{
		Node* newEl = new Node({ value, NULL });
		if (index == 0)
		{
			insertAtStart(value);
			return;
		}
		auto curr = this->head;
		int i = 0;
		while (i < index - 1 && curr != NULL)
		{
			curr = curr->next;
			i++;
		}
		newEl->next = curr->next;
		curr->next = newEl;
	}
	void deleteAtStart()
	{
		if (head != NULL)
		{
			Node* temp = this->head;
			this->head = this->head->next;
			delete temp;
		}

	}
	void deleteAtEnd()
	{
		if (this->head != NULL)
		{
			if (this->head == this->tail)
			{
				delete this->head;
				head = tail = NULL;
			}
			auto curr = this->head;
			while (curr->next != NULL)
			{
				curr = curr->next;
			}
			delete curr->next;
			curr->next = NULL;
			this->tail = curr;
		}
	}
	void deleteAt(int index)
	{
		if (index == 0)
		{
			deleteAtStart();
			return;
		}
		int i = 0;
		if (head != NULL)
		{
			auto curr = this->head;
			while (i < index - 1 && curr->next != NULL)
			{
				i++;
				curr = curr->next;
			}
			Node* temp = curr->next;
			if (curr->next == tail)
			{
				deleteAtEnd();
			}
			else
			{
				curr->next = curr->next->next;
				delete temp;
			}
		}
	}
	int getAtIndex(int index)
	{
		if (head == NULL)
		{
			return NULL;
		}
		else
		{
			int i = 0;
			auto curr = head;
			while (i < index && curr->next != NULL)
			{
				curr = curr->next;
				i++;
			}
			return curr->data;
		}
	}
	bool search(int num)
	{
		if (head == NULL)
			return false;
		auto curr = this->head;
		while (curr != NULL)
		{
			if (curr->data == num)
			{
				return true;
			}
			else
			{
				curr = curr->next;
			}
		}
		return false;
	}
	void print()
	{
		auto curr = this->head;
		while (curr != nullptr)
		{
			cout << curr->data << " ";
			curr = curr->next;
		}
	}
	void unite(const List& list)
	{
		if (this->head == NULL)
		{
			this->head = list.head;
			this->tail = this->head;
		}
		else
		{
			this->tail->next = list.head;
		}
	}
	void reverseList()
	{
		Node* prev = NULL;
		Node* curr = head;
		Node* nexted = NULL;
		while (curr != NULL)
		{
			nexted = curr->next;
			curr->next = prev;
			prev = curr;
			curr = nexted;
		}
		this->head = prev;
	}
	//Merging 2 ordered lists into one
	void merge(const List& list)
	{
		auto currFirst = this->head;
		auto currSecond = list.head;
		Node* start = NULL;
		if (currFirst->data < currSecond->data)
		{
			start = currFirst;
			currFirst = currFirst->next;
		}
		else
		{
			start = currSecond;
			currSecond = currSecond->next;
		}
		Node* curr = start;
		while (currFirst != NULL && currSecond != NULL)
		{
			if (currFirst->data < currSecond->data)
			{
				curr->next = currFirst;
				currFirst = currFirst->next;
				curr = curr->next;
			}
			else
			{
				curr->next = currSecond;
				currSecond = currSecond->next;
				curr = curr->next;
			}
		}
		while (currFirst != NULL)
		{
			curr->next = currFirst;
			currFirst = currFirst->next;
			curr = curr->next;
		}
		while (currSecond != NULL)
		{
			curr->next = currSecond;
			currSecond = currSecond->next;
			curr = curr->next;
		}
		head = start;
	}

};

int main()
{
	//TESTS
	List l;
	List p;
	l.insertAtStart(2);
	l.insertAtStart(7);
	l.insertAtStart(9);
	l.insertAtStart(10);
	l.insertAtEnd(3);
	l.insertAt(1, 44);
	l.deleteAt(1);
	l.insertAtEnd(456);
	l.deleteAtStart();
	l.deleteAtEnd();
	l.print();
	cout << endl;
	cout << l.getAtIndex(3);
	p.insertAtStart(12);
	p.insertAtStart(12);
	p.insertAtStart(12);
	p.insertAtStart(12);
	p.insertAtStart(12);
	l.unite(p);
	l.print();
	l.reverseList();
	l.print();
	cout << endl;
	List listA;
	listA.insertAtEnd(2);
	listA.insertAtEnd(4);
	listA.insertAtEnd(7);
	listA.insertAtEnd(9);
	listA.insertAtEnd(12);

	List listB;
	listB.insertAtEnd(1);
	listB.insertAtEnd(3);
	listB.insertAtEnd(6);
	listB.insertAtEnd(13);

	listA.merge(listB);
	cout << endl;
	listA.print();

	cin.get();
	return 0;
}
