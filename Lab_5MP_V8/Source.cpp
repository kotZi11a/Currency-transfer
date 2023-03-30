#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <stdio.h>
#include <conio.h>

using namespace std;

class money
{
private:
	string data, val;
	double course;
public:
	money() 
	{
	}
	money(string a, string b, double c)
	{
		data = a;
		val = b;
		course = c;
	}
	double to_rub(double b)
	{
		return b * course;
	}

	friend ostream& operator<< (ostream&, const money&);
	friend istream& operator>> (istream&, money&);
	friend fstream& operator<< (fstream&, const money&);
	friend fstream& operator>> (fstream&, money&);
};

	ostream& operator<< (ostream& out, const money& b)
	{
		out << b.data << ' ' << b.val << ' ' << b.course;
		return out;
	}
	istream& operator>> (istream& inp, money& b)
	{
		inp >> b.data >> b.val >> b.course;
		return inp;
	}
	fstream& operator<< (fstream& out, const money& b)
	{
		out << b.data << b.val << b.course;
		return out;
	}
	fstream& operator>> (fstream& inp, money& b)
	{
		inp >> b.data >> b.val >> b.course;
		return inp;
	}

int main()
{
	bool inp = 1;
	char c;
	vector<money> wz;
	int size;
	cout << "Choose input: (1)file, (2)console" << endl;
	while (inp == 1)
	{
		c = _getch();
		if (c == '1' || c == '2')
		{
			cout << c << endl;
			inp = 0;
		}
		else
		{
			cout << c << endl << "Please enter 1 or 2. (1)file, (2)console" << endl;
			inp = 1;
		}
	}
	if (c == '1')
	{
		ifstream input("data.txt");
		input >> size;
		for (int i = 0; i < size; i++)
		{
			money a;
			input >> a;
			wz.push_back(a);
		}
		input.close();
	}
	else 
	{
		cout << "Enter size of vector" << endl;
		cin >> size;
		for (int i = 0; i < size; i++)
		{
			money a;
			cout << "Write class kind of: (data:day.month) (valute) (course)" << endl;
			cin >> a;
			wz.push_back(a);
		}
	}
	double sum;
	vector<double> rub(size);
	cout << "Write sum money: ";
	cin >> sum;
	for (int i = 0; i < size; i++)
	{
		rub[i] = wz[i].to_rub(sum);
	}
	inp = 1;
	cout << "Chouse output: (1)file, (2)console ";
	while (inp == 1)
	{
		c = _getch();
		if (c == '1' || c == '2')
		{
			cout << c << endl;
			inp = 0;
		}
		else
		{
			"Please enter 1 or 2. (1)file, (2)console ";
		}
	}
	if (c == '1')
	{
		ofstream out("result.txt");
		for (int i = 0; i < size; i++)
		{
			out << i << ") " << wz[i] << " in rubles: " << rub[i] << endl;
		}
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			cout << i << ") " << wz[i] << " in rubles: " << rub[i] << endl;
		}
	}
}