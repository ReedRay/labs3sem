#include <iostream>
#include <string>
#include <locale.h>

class Serial
{
public:
	friend class Viewer;
	
	Serial(int id=0, std::string name="", std::string review=""):  m_id(id),m_name(name),m_review(review){}
	~Serial(){}
	friend void print(Serial &serial);
	

private:
	int m_id;
	std::string m_name, m_review;
};
class Viewer
{
public:
	Viewer(){}
	~Viewer(){}
	void AddReview(Serial& serial)
	{
		std::cout << "Напишите отзыв:";
		std::cin >> serial.m_review;
	}

private:

};
void print(Serial &serial)
{
	std::cout << "Id:" << serial.m_id << std::endl;
	std::cout << "Name:" << serial.m_name << std::endl;
	std::cout << "Review:" << serial.m_review << std::endl;
}
int main()
{
	setlocale(LC_ALL, "Russian");
	Serial serial1(1, "boys");
	print(serial1);
	Viewer addSerial1;
	addSerial1.AddReview(serial1);
	print(serial1);
	Serial serial[3]; //массив
	std::string name;
	int id;
	
	for (size_t i = 0; i < 3; i++)
	{
		bool ISid = true;
		bool ISname = true;
		do
		{
			std::cout << "id: ";
			std::cin >> id;
			if (std::cin.fail())
				std::cout << "error" << std::endl;
			else
				ISid = false;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		} while (ISid);
		do
		{
			std::cout << "name: ";
			std::cin >> name;
			if (std::cin.fail())
				std::cout << "error" << std::endl;
			else
				ISname = false;
			std::cin.clear();
			std::cin.ignore(std::cin.rdbuf()->in_avail());
		} while (ISname);
		serial[i] = { id,name };
	}
	for (size_t i = 0; i < 3; i++)
	{
		print(serial[i]);
	}
	
	for (size_t i = 0; i < 3; i++)
	{
		addSerial1.AddReview(serial[i]);
	}
	for (size_t i = 0; i < 3; i++)
	{
		print(serial[i]);
	}

	
	
}






