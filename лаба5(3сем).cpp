#include <stdio.h>
#include <iostream>
#include <locale.h>
#include <string>
class  House
{
public:
	virtual void showInfo() = 0;
	virtual void  something() = 0;

	virtual ~ House()
	{
		std::cout << "destructor House";
	}
	House()
	{
		m_floors = 10;
		m_type = "Block of flats";
	}
	House(int floors, std::string type) :m_type(type), m_floors(floors)
	{

	}
	void setType(std::string type)
	{
		m_type = type;
	}
	void setFloors(int x)
	{
		m_floors = x;
	}

protected:
	int m_floors;
	std::string m_type;
};

class Deteched :  public House
{
public:
	Deteched() :House()
	{
		m_id = 0;
		m_address_line = 00;
		
	}
	Deteched(int id,int address,std::string type,int floors):House(floors,type),m_id(id),m_address_line(address)
	{

	}
	~Deteched()
	{
		std::cout << "destructor deteched";
	}
	void showInfo()
	{
		using namespace std;
		cout << "Id " << m_id << " Address " << m_address_line << " Type " << m_type << " Floors " << m_floors << endl;

	}
	void something()
	{
		std::cout << "Post index=Addres*id " << m_address_line * m_id << std::endl;
	}
	void setId(int x)
	{
		m_id = x;
	}
	void setAddress(int x)
	{
		m_address_line = x;
	}


	
protected:

	int m_id;
	int m_address_line;

};

class Flat :  public House
{
public:
	
	Flat():House()
	{
		m_id = 0;
		m_post_index = 0;
	}
	Flat(int id, int post, int floors, std::string type) :House(floors, type), m_id(id), m_post_index(post)
	{

	}
	~Flat()
	{
		std::cout << "destructor flat";
	}
	void showInfo()
	{
		using namespace std;
		cout << "Id " << m_id << " Post " << m_post_index << " Type " << m_type << " Floors " << m_floors << endl;
		
	}
	void something()
	{
		std::cout << "Address=Post/id " << m_post_index / m_id << std::endl;
	}
	void setId(int x)
	{
		m_id = x;
	}
	void setPost(int x)
	{
		m_post_index = x;
	}
	

protected:
	int m_id;
	int m_post_index;
};

class SemiDeteched : public Deteched
{
public:
	SemiDeteched():Deteched()
	{
		m_living_area = 0;
		m_number_of_neighbours = 0;
	}
	SemiDeteched(int living,int neighbours, int id, int address, std::string type, int floors):Deteched(id,address,type,floors),m_living_area(living),m_number_of_neighbours(neighbours)
	{

	}
	~SemiDeteched()
	{
		std::cout << "destructor SemiDeteched";
	}
	void showInfo()
	{
		using namespace std;
		cout << "Id " << m_id << " Address " << m_address_line << " Type " << m_type << " Floors " << m_floors << endl;
		cout << "Living area " << m_living_area << " Amount of neigbours " << m_number_of_neighbours << endl;

	}
	void something()
	{
		std::cout << "Price=Living area*Floors*100 " << m_living_area * m_floors * 100 << std::endl;
	}
	void setLiving(int x)
	{
		m_living_area = x;
	}
	void setNeighbours(int x)
	{
		m_number_of_neighbours = x;
	}
	

protected:
	double m_living_area;
	int m_number_of_neighbours;
};
void SetHouse(House& house)
{
	using namespace std;
	int floors;
	string type;
	cout << "Введите кол-во этажей и тип ";
	cin >> floors >> type;
	house.setFloors(floors);
	house.setType(type);
}
void SetFlat(Flat &flat)
{
	SetHouse(flat);
	using namespace std;
	int id, post;
	cout << "Введите ид и пост-индекс ";
	cin >> id >> post;
	flat.setId(id);
	flat.setPost(post);

}
void SetDeteched(Deteched& deteched)
{
	SetHouse(deteched);
	using namespace std;
	int id, address;
	cout << "Введите ид и адрес ";
	cin >> id >> address;
	deteched.setAddress(address);
	deteched.setId(id);

}
void setSemi(SemiDeteched& semi)
{
	SetDeteched(semi);
	using namespace std;
	int living;
	int neigh;
	cout << "Введите кол-во соседей и жилую площадь";
	cin >> neigh >> living;
	semi.setLiving(living);
	semi.setNeighbours(neigh);

}
int main()
{
	setlocale(LC_ALL, "Russian");
	Flat *ptrFlat = new Flat[2];
	Deteched* ptrDet = new Deteched[2];
	SemiDeteched* ptrSemi = new SemiDeteched[2];
	House* house;
	for (int i = 0; i < 2; i++)
	{
		SetFlat(ptrFlat[i]);
		house = &ptrFlat[i];
		house->showInfo();
		house->something();
		

	}
	for (int i = 0; i < 2; i++)
	{
		SetDeteched(ptrDet[i]);
		house = &ptrDet[i];
		house->showInfo();
		house->something();


	}
	for (int i = 0; i < 2; i++)
	{
		setSemi(ptrSemi[i]);
		house = &ptrSemi[i];
		house->showInfo();
		house->something();


	}
	
	
}