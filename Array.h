#pragma once
class Array
{
public:

	Array(int length = 0)
	{
		assert(length > 0);
		m_array = new int[length];
		m_length = length;

	}
	Array(const Array& arraycopy)  //копи
	{
		this->m_length = arraycopy.m_length;
		this->m_array = new int[arraycopy.m_length];
		for (int i = 0; i < m_length; i++)
		{
			this->m_array[i] = arraycopy.m_array[i];
		}

	}
	~Array()
	{
		delete[] m_array;
	}
	void SetArray(int index, int number)
	{
		m_array[index] = number;
	}
	void ShellSort()
	{
		int step, i, j, tmp;
		for (step = m_length / 2; step > 0; step /= 2)
			for (i = step; i < m_length; i++)
				for (j = i - step; j >= 0 && m_array[j] < m_array[j + step]; j -= step)
				{
					tmp = m_array[j];
					m_array[j] = m_array[j + step];
					m_array[j + step] = tmp;
				}
	}
	int GetArrayLength(const Array& array)
	{
		return array.m_length;
	}

	int& operator[] (const int index)
	{
		return m_array[index];
	}
	friend Array operator &(Array array1, Array array2);

	friend std::ostream& operator<< (std::ostream& out, const Array& x);
	void print()
	{
		for (int i = 0; i < m_length; i++)
		{
			if (m_array[i] == -842150451)
			{
				break;
			}
			std::cout << m_array[i] << ' ';
		}
	}
private:

	int* m_array;
	int m_length;

};