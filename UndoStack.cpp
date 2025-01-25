#include<iostream>
using namespace std;

template<class T>
class undoStack {
private:
	class node
	{
	public:
		T data;
		node* next;
		node* prev;
	};
	
	node* top;
	node* bottom;
public:
	int count = 100;
	int size = 0;
	//constructor
	undoStack()
	{
		top = NULL;
		bottom = NULL;
	}


	bool isEmpty()
	{
		if (top == NULL)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool isFull()
	{
		if (size == count)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Push(const T& val)
	{
		if (top == NULL)
		{
			node* insert = new node();
			insert->data = val;
			top = insert;
			bottom = insert;
			top->prev = NULL;
			size++;
			return true;
		}
		else if (!isFull())
		{
			node* insert = new node();
			insert->data = val;
			top->next = insert;
			insert->prev = top;
			top = insert;
			size++;
			return true;
		}
		else
		{
			cout << "WAIT\n";     //just to check everything works fine
			bottom = bottom->next;
			delete bottom->prev;
			bottom->prev = NULL;
			node* insert = new node();
			insert->data = val;
			top->next = insert;
			insert->prev = top;
			top = insert;
			size++;
			return true;
		}
	}


	bool Pop()
	{
		if (!isEmpty())
		{
			node* del = top;
			top = top->prev;
			delete del;
			del = NULL;
			return true;
		}
		else
		{
			cout << "Dear user there is nothing to undo\n";
			return false;
		}
	}



	bool Top(T& val)      //pass by reference so that data can be accessed outsisde the function
	{
		if (!isEmpty())
		{
			val = top->data;
			return true;
		}

		else
		{
			return false;  // case when stack is empty; there would be nothing on top
		}
	}


	// below function is just to verify the code
	void print()
	{
		node* temp = top;
		while (temp != NULL)
		{
			cout << "|"<< temp->data << "|"<< endl;
			cout << "---" << endl;
			temp = temp->prev;
		}
		cout << endl;
	}

	~undoStack()
	{
		if (bottom != NULL)
		{
			node* temp1 = top;
			node* temp2 = top;
			while (temp1 != NULL)
			{
				temp2 = temp1->prev;
				delete temp1;
				temp1 = temp2;
			}
		}
		
	}

};


int main()
{
	int n;
	undoStack<int> s1;
	s1.Push(1);
	s1.Push(2);
	s1.Push(3);
	s1.Push(4);
	s1.Push(5);

	s1.print();

	s1.Push(6);
	s1.print();

	s1.Pop();
	s1.Pop();
	s1.print();

	s1.Push(8);
	s1.Push(9);
	s1.print();
	return 0;

}