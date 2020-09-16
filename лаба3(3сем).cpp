#include <iostream>
#include <string>
#include <locale.h>
#include <cassert>
#include "Array.h"





Array operator&(Array array1, Array array2)
{
	int maxElements = 0;
	int z = 0;
	Array array3(array1.m_length+array2.m_length);
	for (size_t i = 0; i < array1.m_length; i++)
	{
		bool check = 0;
		for (size_t j = 0; j < array2.m_length; j++)
		{
			for (size_t k = 0; k < maxElements; k++)     
			{
				if (array3.m_array[k] == array1.m_array[i])
				{ 
					bool check = 1;
					break;
				}
			}       

			if (array1.m_array[i]== array2.m_array[j])
			{
				if (check==1)
				{
					break;
				}
				maxElements++;
				array3.m_array[z] = array1.m_array[i];
				z++;
				break;
			}
		}
	}
	return array3;
}
std::ostream& operator<< (std::ostream& out, const Array& array)
{
	for (size_t i = 0; i < array.m_length; i++)
	{
		out << array.m_array[i];
	}


	return out;
}


int main()
{
	Array array(10);
	
	for (int i = 0; i < 10 ; i++)
	{
		array.SetArray(i,i);            //присвоение элементам массива
	}
	Array array1(array);                //вызов конструктора копирования
	array.print();                      //метод принт
	std::cout << '\n';
	array1.SetArray(0, 100);            //метод сеттер
	array1.SetArray(1, 200);
	std::cout << '\n';
	array1.print();

	std::cout <<'\n';
	std::cout << array1[0];                //перегрузка оператора []
	std::cout << '\n';
	std::cout << "My array is " << array;  //перегрузка оператора вывода
	std::cout << '\n';

	Array array2 = array & array1;         // перегрузка оператора & для пересечения массивов(выводится общая часать)
	
	array2.print();
	std::cout << '\n';

	array.ShellSort();                     //метод сортировки по убыванию
	array.print();
	
	
	
	
	

}
