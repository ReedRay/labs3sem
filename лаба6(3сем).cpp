#include<iostream>
#include<cstdlib>
#include <string>
#include<math.h>
#include <ctype.h>

using namespace std;
template <typename T>
class Equation
{
public:
	Equation()
	{
		cout << "Уравнения не существует";
	}
	Equation(T a,T b,T c)
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	

	T Roots(int a)
	{
		int a1, b1, c1;
		a1 = atoi(this->a);
		b1 = atoi(this->b);
		c1 = atoi(this->c);
		double D1 = (b1*b1) - (4 * a1*c1);
		if (D1 < 0)
		{
			cout << "D <0";
			return 0;
		}

		double x11 = (((-1 * b1) + sqrt(D1)) / (2 * a1));
		double x22 = (((-1 *b1) - sqrt(D1)) / (2 *a1));
		/*	x1 = this->a * this->b * this->c;*/
			 /*cout << D;*/

		cout << x11 << endl;
		cout << x22;

	}
	T Roots()
	{
		T D = (this->b * this->b) - (4 * this->a * this->c);
		if (D < 0)
		{
			cout << "D <0";
			return 0;
		}

		x1 = (((-1 * this->b) + sqrt(D)) / (2 * this->a));
		x2 = (((-1 * this->b) - sqrt(D)) / (2 * this->a));
		/*	x1 = this->a * this->b * this->c;*/
			 /*cout << D;*/

		cout << x1 << endl;
		cout << x2;

	}

	
	
private:
	T a, b, c;
	T x1, x2;


};

int main()
{

	cout << "vvedite tip 1-int,2-double,3-char";
	int proverka;
	do
	{
		cin >> proverka;
		if (proverka == 1)
		{
			int a, b, c;
			cout << "vvedite indexi a b c";
			cin >> a >> b >> c;
			Equation<int> EQ1(a, b, c);
			EQ1.Roots();
			break;

		}
		if (proverka == 2)
		{
			double a, b, c;
			cout << "vvedite indexi a b c";
			cin >> a >> b >> c;
			Equation<double> EQ2(a, b, c);
			EQ2.Roots();
			break;

		}
		if (proverka == 3)
		{
			cout << "vvedite indexi a b c";

			char* ms=new char[3];
			char* ms1 = new char[3];
			char* ms2 = new char[3];
			cin >> ms;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			cin >> ms1;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			cin >> ms2;
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			Equation<char*> obj1(ms, ms1, ms2);
			obj1.Roots(1);
			
		
			break;

		}
	} while (1);
	
	

}

