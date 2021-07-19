#include <cassert>
#include <iostream>
#include <string>
#include <vector>


class Human
{
private:
	std::string m_firstname{};
	std::string m_lastname{};
	int m_age{};
	
	int m_kidsAmount{};
	Human* m_kids{ nullptr };

	bool m_isMarried{ false };
	std::string m_partnersName{};
	Human* m_partner{ nullptr };

public:
	// Constructor
	Human();
	Human(std::string firstname, std::string lastname, int age);
	Human(const Human& toCopy);

	// Destructor
	~Human();

	// Operator overloads
	Human& operator=(const Human& obj);
	Human& operator()(Human& obj);
	Human& operator++();
	Human& operator++(int);
	void operator+(Human& obj);
	void operator-(Human& obj);
	
	operator std::string();

	friend std::ostream& operator<<(std::ostream& out, const Human& obj);
};



Human::Human() 
{
};


Human::Human(std::string firstname, std::string lastname, int age)
	: m_firstname{firstname}, m_lastname{lastname}, m_age{age}, m_kidsAmount{0}
{
	assert(age >= 0 && "Age needs to be positive");
}


Human::Human(const Human& toCopy)
	: m_firstname{ toCopy.m_firstname }, m_lastname{ toCopy.m_lastname }, m_age{ toCopy.m_age },
	m_kidsAmount{ toCopy.m_kidsAmount }, m_isMarried{ toCopy.m_isMarried }
{
	if (toCopy.m_kids == nullptr)
	{
		return;
	}

	if (toCopy.m_kidsAmount > 0)
	{
		delete[] m_kids;
		m_kids = new Human[m_kidsAmount];


		for (int i = 0; i < m_kidsAmount; ++i)
		{
			m_kids[i] = toCopy.m_kids[i];
		}
	}
}


Human::~Human()
{
	delete[] m_kids;
}



Human& Human::operator=(const Human& obj)
{
	// Self copy guard
	if (this == &obj)
	{
		return *this;
	}

	m_firstname = obj.m_firstname;
	m_lastname = obj.m_lastname;
	m_age = obj.m_age;
	m_kidsAmount = obj.m_kidsAmount;
	m_isMarried = obj.m_isMarried;


	delete[] m_kids;
	m_kids = new Human[m_kidsAmount];


	for (int i = 0; i < m_kidsAmount; ++i)
	{
		m_kids[i] = obj.m_kids[i];
	}

	return *this;
}

Human& Human::operator()(Human& obj)
{
	++m_kidsAmount;

	delete[] m_kids;
	m_kids = new Human[m_kidsAmount];

	*(m_kids + m_kidsAmount - 1) = obj;


	if (m_isMarried)
	{
		++m_partner->m_kidsAmount;
		delete[] m_partner->m_kids;
		m_partner->m_kids = new Human[m_partner->m_kidsAmount];
		*(m_partner->m_kids + m_partner->m_kidsAmount - 1) = obj;
	}

	return *this;
}

Human& Human::operator++()
{
	m_age += 1;

	return *this;
}

Human& Human::operator++(int)
{
	m_age += 1;

	return *this;
}


void Human::operator+(Human& obj)
{
	m_isMarried = true;
	obj.m_isMarried = true;

	m_partnersName = obj.m_firstname + " " + obj.m_lastname;
	obj.m_partnersName = m_firstname + " " + m_lastname;

	obj.m_partner = this;
	m_partner = &obj;
}

void Human::operator-(Human& obj)
{
	m_isMarried = false;
	obj.m_isMarried = false;

	m_partnersName = "";
	obj.m_partnersName = "";

	obj.m_partner = nullptr;
	m_partner = nullptr;
}



Human::operator std::string()
{
	return m_firstname + " " + m_lastname;
}


std::ostream& operator<<(std::ostream& out, const Human& obj)
{
	out << "The human " << obj.m_firstname << " " << obj.m_lastname << " is " << obj.m_age <<
		" years old " << (obj.m_isMarried ? "and is married with " + obj.m_partnersName : "and is not married")
		<< ". It has " << obj.m_kidsAmount << " kid(s).";

	return out;
}


int main()
{
	// Instantiate humans
	Human first("Human1", "Johnson", 16);
	Human second("Human2", "Ramsy", 19);

	// Create a kid
	Human kid2("Kid1", "Johnson", 4);
	// Add tge kid to human 2
	second(kid2);

	// marray human1 and human2
	first + second;

	// Create a kid
	Human kid1("Kid2", "Jhonsy", 1);
	// Add tge kid to human 1
	first(kid1);

	// divorce human1 and human2
	first - second;

	// Create a kid
	Human kid3("Kid2", "Jhonsy", 1);
	// Add tge kid to human 1
	first(kid3);

	// Increasing human1's age
	++first;

	// Printing
	std::cout << first << "\n";
	std::cout << "\n";
	std::cout << second << "\n";

	std::cout << "\n";
	// Type conversion
	std::cout << static_cast<std::string>(first);
}