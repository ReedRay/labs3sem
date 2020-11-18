#include <iostream>
#include <string>
#include <locale.h>
#include <algorithm> 

class ExceptionStack
{
public:
	ExceptionStack(std::string error)
	{
		m_exception = error;
	}
	const char* getError()
	{

		return m_exception.c_str();
	}

private:
	std::string m_exception;
};



class Serial
{
	
public:
	Serial(int id, std::string name) : m_id(id), m_name(name) {}
	Serial()
	{
		m_id = 0;
		m_name = "";

	}
	void print()
	{
		using namespace std;
		cout << m_id << " " << m_name;
	}

	friend std::ostream& operator<< (std::ostream& out, const Serial& point);
public:
	Serial* m_next;
	int m_id;
	std::string m_name;

};
std::ostream& operator<< (std::ostream& out, const Serial& point)
{

	out << point.m_id << ' ' << point.m_name << std::endl;


	return out;
}



template<typename T>
class  Stack
{
public:


	class Iterator
	{

	public:
		Iterator()
		{
			current = NULL;
			size_it = 0;
		}
		
		void operator=(T* pointer)
		{
			this->current = pointer;
		}
		bool operator !=(T* pointer)
		{
			return current != pointer;
		}
		T operator *()
		{
			return *current;
		}
		T* operator--()
		{
			return current = current->m_next;

		}
		
		bool operator>(Stack::Iterator it1)
		{
			return this->current->m_id > it1.current->m_id;
		}
		
		
	public:
		T* current;
		int size_it;
	};
	Stack()
	{
		head = NULL;

		size = 0;

	}
	Stack(T* head)
	{
		this->head = head;
	}
	Stack(T data)
	{
		this->data = data;
	}
	void push(T* head)
	{
		if (this->head == NULL)
		{
			this->head = head;
			this->head->m_next = NULL;
		}
		else
		{
			head->m_next = this->head;
			this->head = head;
		}
		size++;
	}
	Iterator pop(Stack::Iterator it)
	{
	
		if (size==0)
		{
			throw ExceptionStack("Theree is no stack");

		}
		else
		{
			T* temp = this->head;
			this->head = this->head->m_next;
			delete temp;
			size--;
			it = this->head;
			return it;

		}
			
		
	
		
	}
	void print(Stack::Iterator it)
	{

		using namespace std;
		while (it != NULL)
		{
			if (size==0)
			{
				throw ExceptionStack("Theree is no stack");
			}
			else
			{
				cout << *it;
				--it;
			}
			

		}

	}
	

	T* top()
	{
		return this->head;
	}

		void sort(Stack::Iterator it)
		{
			Stack::Iterator it1 = it;
			int* ms = new int[size];
			for (int i = 0; i < size; i++)
			{
				ms[i] = it1.current->m_id;
				--it1;
			}
			
			for (int i = 0; i < size; i++)
			{
				for (int j = i; j < size; j++)
				{
					if (ms[i] > ms[j])
					{
						int temp = ms[i];
						ms[i] = ms[j];
						ms[j] = temp;
					}
				}
			}
			
			for (int i = 0; i < size; i++)
			{
				it.current->m_id = ms[i];
				--it;
			}
		}
private:
	T* head;
	int size;
	
};


void menu()
{
	using namespace std;
	cout << " что желаете: 1-push 2-pop 3-sort 4-print 0-выход";
	
}




int main()
{
	using namespace std;
	setlocale(LC_ALL, "Russian");
	int x;
	Stack<Serial>stack;
	Stack<Serial>::Iterator it;

	while (1)
	{
		menu();
		try
		{
			cin >> x;
			if (x < 0 || x>4)
				throw ExceptionStack("Invalid x,input correct x\n");
		}
		catch (ExceptionStack exception)
		{
			cerr << exception.getError();
		}

		if (x == 1)
		{
			cout << "Введите id и name:";
			int id;
			string name;
			try
			{
				cin >> id >> name;
				if (id < 0)
				{
					throw ExceptionStack("Invalid id,input correct id\n");
				}
			}
			catch (ExceptionStack exception)
			{
				cerr << exception.getError();
			}
			Serial* ser = new Serial(id, name);
			stack.push(ser);
			it = stack.top();

		}
		if (x == 2)
		{
			try
			{
				stack.pop(it);
				it = stack.top();
			}
			catch (ExceptionStack exception)
			{
				cerr<<exception.getError();
			}
			
		}

		if (x == 3)
		{
			stack.sort(it);
		}

		if (x == 4)
		{
			
			try
			{
				stack.print(it);

			}
			catch (ExceptionStack exception)
			{
				cerr << exception.getError();
			}
		}
		if (x == 0)
		{
			break;
		}

	}
}
	
