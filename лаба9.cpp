#include "Header.h"

using namespace std;
using namespace myClass;

std::ostream& operator<< (std::ostream& out, const Serial& point)
{

	out << point.m_id << ' ' << point.m_name << std::endl;


	return out;
}

void menu()
{
	using namespace std;
	cout << " что желаете: 1-push 2-Search 3-popValue 4-print 5-file 6-linked list 0-выход";

}

string func2(std::vector<Serial>::const_iterator begin, std::vector<Serial>::const_iterator end, int vvod)
{
	do
	{
		if (begin == end&&begin->m_id!=vvod)
		{
			throw ExceptionStack("Id doesn`t exist\n");
		}
		if (begin->m_id == vvod)
		{
			return begin->m_name;
		}
		else
		{
			begin++;
		}

	} while (begin != end+1);
	
}
void func3(std::vector<Serial>::reverse_iterator begin, int vvod, vector<Serial>& stack)
{
	int x1 = vvod;
	auto result = remove_if(stack.begin(), stack.end(), [&](const Serial p)
		{
			return p.m_id == vvod;
		});
	stack.erase(result, stack.end());
}
void func1(list<string> &L)
{
	
	ifstream fin;
	ofstream fout;
	fin.open("filein.txt");
	fout.open("fileout.txt");
	try
	{
	
		if (!fin.is_open())
		{
			throw ExceptionStack("Can`t open file\n");
		}
	}
	catch (ExceptionStack exception)
	{
		cerr << exception.getError();
	}
	string buf;
	
	while (getline(fin,buf))
	{
		buf += "1";
		L.push_back(buf);
		fout << buf<<'\n';
	}
	

}
int main()
{
	setlocale(LC_ALL, "Russian");
	vector<Serial> myStack;
	int x;
	while (1)
	{
		menu();
		try
		{
			cin >> x;
			if (x < 0 || x>6)
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
			Serial ser = { id, name };
			myStack.push_back(ser);

			

		}
		if (x == 2)
		{
			cout << "Введите ид для поиска";
			int vvod;
			string stroka;
			try
			{
				cin>>vvod;
				auto it1 = myStack.begin();
				auto it2 = myStack.end();
				--it2;
				stroka=func2(it1, it2, vvod);
				cout << "Название сериала:" << stroka<<endl;
			}
			catch (ExceptionStack exception)
			{
				cerr << exception.getError();
			}

		}

		if (x == 3)
		{
			int vvod;
			cout << "Введите ид для удаления:";
			cin >> vvod;
			auto it1 = myStack.rbegin();
			
			try
			{
				func3(it1,vvod, myStack);
				
			}
			catch (ExceptionStack exception)
			{
				cerr << exception.getError();
			}

		}

		if (x == 4)
		{

			try
			{
				vector<Serial>::const_iterator it = myStack.begin();
				
				while (it!=myStack.end())
				{
					cout <<it->m_id<<" "<<it->m_name ;
					++it;
				}

			}
			catch (ExceptionStack exception)
			{
				cerr << exception.getError();
			}
		}
		
		if (x == 6)
		{
			list<string> L;
			func1(L);
			auto it = L.begin();
			while (it!=L.end())
			{
				cout << *it << endl;
				it++;
			}
		}
		if (x == 0)
		{
			break;
		}

	}
	
	
}
