#include <iostream>
using namespace std;

class Time
{
private:
	int hours;
	int minutes;
	int seconds;

public:
	int gethours() { return hours; }
	int getminutes() { return minutes; }
	int getseconds() { return seconds; }

	void sethours(int valuehours) { hours = valuehours; }
	void setminutes(int valueminutes) { minutes = valueminutes; }
	void setseconds(int valueseconds) { seconds = valueseconds; }
 
	Time(int valuehours, int valueminutes, int valueseconds)
	{
		hours = valuehours;
		minutes = valueminutes;
		seconds = valueseconds;
	}

	~Time() {}

	void gettime(int valuehours, int valueminutes, int valueseconds)
	{
		if (valuehours < 10) { cout << "0" << valuehours << ":"; }
		else { cout << valuehours << ":"; }
		if (valueminutes < 10) { cout << "0" << valueminutes << ":"; }
		else { cout << valueminutes << ":"; }
		if (valueseconds < 10) { cout << "0" << valueseconds << "|"; }
		else { cout << valueseconds << "|"; }

		if (valuehours <= 12) 
		{
			if (valuehours < 10) { cout << "0" << valuehours << ":"; }
			else { cout << valuehours << ":"; }
			if (valueminutes < 10) { cout << "0" << valueminutes << ":"; }
			else { cout << valueminutes << ":"; }
			if (valueseconds < 10) { cout << "0" << valueseconds << "AM"; }
			else { cout << valueseconds << "AM"; }
		}
		else 
		{
			if (valuehours < 10) { cout << "0" << valuehours << ":"; }
			else { cout << valuehours << ":"; }
			if (valueminutes < 10) { cout << "0" << valueminutes << ":"; }
			else { cout << valueminutes << ":"; }
			if (valueseconds < 10) { cout << "0" << valueseconds << "PM"; }
			else { cout << valueseconds << "PM"; }
		}
	}

	void increasedtime(int valuehours, int valueminutes, int valueseconds)
	{
		if (valueseconds == 59) 
		{
			valueseconds = 00;
			valueminutes++;
		}
		else { valueseconds++; }

		if (valueminutes == 59)
		{
			valueminutes = 00;
			valuehours++;
		}
		else if  (valueminutes == 60)
		{ 
			valueminutes = 01; 
			valuehours++;
		}
		else { valueminutes++; }

		if (valuehours == 23) 
		{
			valuehours = 00;
		}
		else if (valuehours == 60)
		{
			valuehours = 01;
		}
		else { valuehours++; }
		if (valuehours == 25)
		{
			valuehours = 01;
		}

		gettime(valuehours, valueminutes, valueseconds);
	}
};

int main()
{
	system("chcp 1251");
	int valuehours, valueminutes, valueseconds;
	cout << "Введіть годину -> ";
	cin >> valuehours;
	if (valuehours > 23) 
	{
		cout << "Не вірні дані";
		return 0;
	}
	cout << "Введіть хвилину -> ";
	cin >> valueminutes;
	if (valueminutes > 59)
	{
		cout << "Не вірні дані";
		return 0;
	}
	cout << "Введіть секунду -> ";
	cin >> valueseconds;
	if (valueseconds > 59)
	{
		cout << "Не вірні дані";
		return 0;
	}

	Time time1(valuehours, valueminutes, valueseconds);

	cout << "Введений час : ";
	time1.gettime(valuehours, valueminutes, valueseconds);
	cout << "\nЗбільшений на одну годину, хвилину та секунду введений час : ";
	time1.increasedtime(valuehours, valueminutes, valueseconds);


	return 0;
}

