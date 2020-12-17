#include"Header.h"


ostream& operator<<(ostream& out, const ATS& temp)
{
	out << "Code: " << temp.code << endl;
	out << "Duration: " << temp.time_in_sec << endl;
	out << "tarif: " << temp.tarif << endl;
	out << "Number: " << temp.number << endl;
	
	return out;
}

void InsertSort(int n, int* ms)
{
	int j;
	int m;
	for (int i = 1; i < n; ++i)
	{
		j = i - 1;
		m = ms[i];
		while (j >= 0 && m < ms[j])
		{
			ms[j-- + 1] = ms[j];
		}
		ms[j + 1] = m;
	}
	return;
}

int File::Del(int index, int n)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return 0;
	}
	ATS* ms;
	ms = new ATS[n];
	for (int i = 0; i < n; i++)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
	}
	fs.close();
	fstream fs1;
	fs1.open(path, fstream::binary | fstream::out | fstream::trunc);
	fs1.close();
	fstream fs2;
	fs2.open(path, fstream::binary | fstream::out);
	for (int i = 0; i < index; i++)
	{
		this->WriteBin(ms[i]);
	}
	for (int i = index + 1; i < n; i++)
	{
		this->WriteBin(ms[i]);
	}
	n = n - 1;
	cout << "After deletion: " << endl;
	this->ReadBin(n);
	fs2.close();
	return n;
}

void File::ReadTextBin()
{
	char* msg;
	msg = new char[10];
	fstream fs;
	fs.open(path, fstream::in | fstream::binary);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	fs.read(msg, 10);
	int count = 0;
	for (int i = 0; i < 10; i++)
	{
		if (msg[i] >= 97 && msg[i] <= 122 || msg[i] >= 65 && msg[i] <= 90)
		{
			count++;
		}
	}
	for (int i = 0; i < count; i++)
	{
		cout << msg[i];
	}
	cout << endl;
	fs.close();
}

void File::Sort(int n)
{
	if (n == 1)
	{
		this->ReadBin(n);
		return;
	}
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	int* m;
	m = new int[n];
	ATS* ms;
	ms = new ATS[n];
	int i = 0;
	for (int k = 0; k < n; k++)
	{
		fs.read((char*)&ms[i], sizeof(ms[i]));
		m[i] = ms[i].code;
		i++;
	}
	InsertSort(n, m);
	fs.close();
	fstream fs1;
	fs1.open(path, fstream::binary | fstream::out | fstream::trunc);
	try
	{
		if (!fs1.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	fs1.close();
	fstream fs2;
	fs2.open(path, fstream::binary | fstream::out);
	try
	{
		if (!fs2.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "Sort by code of products:  " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (ms[j].code == m[i])
			{
				this->WriteBin(ms[j]);
			}
		}
	}
	this->ReadBin(n);
	fs2.close();
	delete[] ms;
	delete[] m;
}

//void File::Search()
//{
//	fstream fs;
//	fs.open(path, fstream::in | fstream::binary | fstream::out);
//	try
//	{
//		if (!fs.is_open())
//		{
//			throw 1;
//		}
//	}
//	catch (int i)
//	{
//		Exception ex(i);
//		ex.Print();
//		return;
//	}
//	ATS ms[10];
//	int i = 0;
//	char c;
//	while (!fs.eof())
//	{
//		fs.read(reinterpret_cast<char*>(&ms[i]), sizeof(ms[i]));
//		/*fs.read((char*)&ms[i], sizeof(ms[i]));*/
//		i++;
//	}
//	cout << "Enter workshop (A, B, C): ";
//	cin >> c;
//	cout << "Searching results: " << endl;
//	int count = 0;
//	for (int i = 0; i < 10; i++)
//	{
//		if (ms[i].category == c)
//		{
//			cout << "____________________________________" << endl;
//			cout << ms[i] << endl;
//			count = count + ms[i].amount;
//		}
//	}
//	cout << "Total number of products in this category: " << count << endl;
//	fs.close();
//}

void File::WriteBin(ATS pr)
{
	fstream fs;
	fs.open(path, fstream::out | fstream::binary | fstream::app);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	fs.write((char*)&pr, sizeof(pr));
	/*fs.write(reinterpret_cast<char*>(&pr), sizeof(pr));*/
	fs.close();
}

void File::WriteText()
{
	string msg;
	fstream fs;
	fs.open(path, fstream::out | fstream::app);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "Enter message: ";
	cin >> msg;
	fs << msg << "\n";
	fs.close();
}

void File::ReadBin(int n)
{
	fstream fs;
	fs.open(path, fstream::in | fstream::binary | fstream::out);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "____________________________________" << endl;
	ATS pr;
	for (int i = 0; i <n; i++)
	{
		fs.read((char*)&pr, sizeof(ATS));
			cout << pr;
		cout << "____________________________________" << endl;
	} 
	
	fs.close();
}

void File::ReadText()
{
	string msg;
	fstream fs;
	fs.open(path, fstream::in);
	try
	{
		if (!fs.is_open())
		{
			throw 1;
		}
	}
	catch (int i)
	{
		Exception ex(i);
		ex.Print();
		return;
	}
	cout << "File " << path << ":" << endl;
	while (!fs.eof())
	{
		while (getline(fs, msg))
		{
			cout << msg << endl;
		}
	}
	fs.close();
}

int main()
{

	File file2("2.bin");
	int* code;
	int* secs;
	char* tarif;
	char* number;
	int n, index, choice, ch;
	cout << "Work with text or binary file? Choose 1 or 2  ";


	cin >> choice;
	if (choice == 1)
	{
		system("CLS");
		cout << "Text file mode:" << endl;
		File file1("1.txt");
		file1.WriteText();
		file1.ReadText();
		cout << "Read as a binary file: " << endl;
		file1.ReadTextBin();
	}
	if (choice == 2)
	{
		system("CLS");
		cout << "Writing the file: " << endl;
		cout << "Enter the number of products: ";
		try
		{
			cin >> n;
			if (cin.fail())
			{
				throw 0;
			}
		}
		catch (int i)
		{
			Exception ex(i);
			ex.Print();
			return 0;
		}
		code = new int[n];
		secs = new int[n];
		tarif = new char[n];
		number = new char[n];
		for (int i = 0; i < n; i++)
		{
			cout << "Code: ";
			cin >> code[i];
			cout << "Duration: ";
			cin >> secs[i];
			cout << "tarif: ";
			cin >> tarif;
			cout << "number: ";
			cin >> number;

			ATS pr(code[i], secs[i], tarif, number);
			file2.WriteBin(pr);
		}
		while (1)
		{
			cout << "\nRead the file - 1" << endl;
		
			cout << "Sort - 2" << endl;
			cout << "Deletion - 3" << endl;
			cout << "EXIT-4" << endl;
			cin >> ch;
			if (ch == 1)
			{
				cout << "File: " << endl;
				file2.ReadBin(n);
			}
		
			if (ch == 2)
			{
				file2.Sort(n);
			}
			if (ch == 3)
			{
				cout << "Index na ydalenie: ";
				try
				{
					cin >> index;
					if (cin.fail())
					{
						throw 0;
					}
				}
				catch (int i)
				{
					Exception ex(i);
					ex.Print();
					return 0;
				}
				int k;
				k = file2.Del(index, n);
				n = k;
			}
			
			if (ch == 4)
				return 0;
		}
		delete[] code;
		delete[] secs;
		delete[] tarif;
		delete[] number;
	}
}

				