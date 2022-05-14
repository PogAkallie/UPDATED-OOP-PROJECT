#include <iostream>
#include "Dairy.h"
#include "MyString.h"
#include <fstream>
//#include <istream>
#include <cstring>
#include <exception>
#pragma warning (disable:4996)
using namespace std;

//PERSON

void Person::free()
{
	delete[] name;
	delete[] password;
	delete[] email;
}

void Person::copyFrom(const Person& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	password = new char[strlen(other.password) + 1];
	strcpy(password, other.password);

	email = new char[strlen(other.email) + 1];
	strcpy(email, other.email);
}

bool Person::validatingName(char ch)
{
	return (name[ch] <= 'a' && name[ch] >= 'z') || (!ch <= 'A' && name[ch] >= 'Z') || (name[ch] == ' ' || name[ch] == '\n') || (name[ch] >= '0' && name[ch] <= '9');
}

Person Person::createCustomer(const char* name, const char* password, const char* email)
{
	Person p;

	size_t nameLength = strlen(name);
	p.name = new char[nameLength + 1];
	strcpy(p.name, name);
	
	size_t passwordLength = strlen(password);
	p.password = new char[passwordLength + 1];
	strcpy(p.password, password);

	size_t emailLength = strlen(email);
	p.email = new char[emailLength + 1];
	strcpy(p.email, email);

	return p;
}

//public

void Person::saveInfoToFile(ofstream& file, const Person& p)
{
	size_t nameLength = strlen(p.name);
	size_t passwordLength = strlen(p.password);
	size_t emailLength = strlen(p.email);

	file.write((const char*)&nameLength, sizeof(nameLength));
	file.write(p.name, nameLength);

	file.write((const char*)&passwordLength, sizeof(passwordLength));
	file.write(p.password, passwordLength);

	file.write((const char*)&emailLength, sizeof(emailLength));
	file.write(p.email, emailLength);

	cout << "Custormer personal data is saved!\n" << endl;
}

Person Person::readInfoFromFile(ifstream& file)
{
	Person p;

	size_t nameLength;
	size_t passwordLength;
	size_t emailLength;

	file.read((char*)&nameLength, sizeof(nameLength)); //we read the size of the name
	p.name = new char[nameLength + 1];
	file.read(p.name, nameLength);
	p.name[nameLength] = '\0';

	file.read((char*)&passwordLength, sizeof(passwordLength)); //we read the size of the password
	p.password = new char[passwordLength + 1];
	file.read(p.password, passwordLength);
	p.password[passwordLength] = '\0';

	file.read((char*)&emailLength, sizeof(emailLength)); //we read the size of the email
	p.email = new char[emailLength + 1];
	file.read(p.email, emailLength);
	p.email[emailLength] = '\0';

	return p;

}


Person::Person(const char* name, const char* password, const char* email)
{
	setName(name);
	setPassword(password);
	setEmail(email);
}

Person::Person(const Person& other)
{
	copyFrom(other);
}

Person& Person::operator=(const Person& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Person::~Person()
{
	free();
}

const char* Person::getName() const
{
	return name;
}

char* Person::getPassword() const
{
	return password;
}

char* Person::getEmail() const
{
	return email;
}

void Person::setName(const char* newName)
{
	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Person::setPassword(const char* newPassword)
{
	delete[] password;
	password = new char[strlen(newPassword) + 1];
	strcpy(password, newPassword);
}

void Person::setEmail(const char* newEmail)
{
	delete[] email;
	email = new char[strlen(newEmail) + 1];
	strcpy(email, newEmail);

}

//void Person::getInfo(const char* fileName)
//{
//	ofstream file(fileName, ios::app);
//	{
//		cout << "Enter your name:" << endl;
//		cin >> name;
//		cout << "Enter your password:" << endl;
//		cin >> password;
//		cout << "Enter your email:" << endl;
//		cin >> email;
//	}
//
//	file << "\nName:" << name << "\nPassword:" << password << "\nEmail:" << email << endl;
//	file.close();
//	cout << "Custormer personal data is saved!\n" << endl;
//}

void Person::collectNamesInArray()
{
	//size of the names we want to store
	string* name = new string[size];
	for (size_t i = 0; i < size; i++)
	{
		cin >> name[i];
	}
}

bool Person::linearSearch(const int* arr, int element)
{
	for (unsigned i = 0; i < size; i++)
	{
		if (arr[i] == element)
			return true;
	}
	return false;
}

void Person::print(const Person& p)
{
	cout << p.name << " " << p.password << " " << p.email << endl;
}

//DATA

void Data::destinationInfo(const char* destinationInfoFileName)
{
	ofstream file(destinationInfoFileName, ios::app);
	{
		cout << "Enter your destination:" << endl;
		cin >> destination;
		cout << "Enter your period(example-> date/month/year - date/month/year) :" << endl;
		cin >> period;
		cout << "Enter your comment:" << endl;
		cin >> comment;
		cout << "Your rating from 1 to 10 is:" << endl;
		cin >> rating;
	}

	file << "\nDestination:" << destination << "\nPeriod:" << period << "\nComment:" << comment << "\nRating:" << rating << endl;
	file.close();
	cout << "Customer travels are saved!" << endl;
}

void Data::showDetails(const char* destinationInfoFileName)
{
	ifstream file(destinationInfoFileName);
	{
		if (!file.is_open())
		{
			cout << "File Error!" << endl;
		}
		while (!file.eof())
		{
			file >> destination >> period >> comment >> rating;
		}
		file.close();
	}

	
}

void Data::saveDataToFile(ofstream& file, const Data& p)
{
	size_t destinationLength = strlen(p.destination);
	size_t periodLength = strlen(p.period);
	size_t commentLength = strlen(p.comment);

	file.write((const char*)&destinationLength, sizeof(destinationLength));
	file.write(p.destination, destinationLength);

	file.write((const char*)&periodLength, sizeof(periodLength));
	file.write(p.period, periodLength);

	file.write((const char*)&commentLength, sizeof(commentLength));
	file.write(p.comment, commentLength);

	file.write((char*)&p.rating, sizeof(p.rating));
}

Data Data:: readInfoFromFile(ifstream& file)
{
	Data p;

	size_t destinationLength;
	size_t pariodLength;
	size_t commentLength;

	file.read((char*)&destinationLength, sizeof(destinationLength)); //we read the size of the name
	p.destination = new char[destinationLength + 1];
	file.read(p.destination, destinationLength);
	p.destination[destinationLength] = '\0';

	file.read((char*)&pariodLength, sizeof(pariodLength)); //we read the size of the password
	p.period = new char[pariodLength + 1];
	file.read(p.period, pariodLength);
	p.period[pariodLength] = '\0';

	file.read((char*)&commentLength, sizeof(commentLength)); //we read the size of the email
	p.comment = new char[commentLength + 1];
	file.read(p.comment, commentLength);
	p.comment[commentLength] = '\0';

	file.read((char*)&p.rating, sizeof(p.rating));

	return p;

}

void Data::savePhotos(const char* photoFileName)
{
	ofstream file(photoFileName);
	{
		cout << "Enter the file name of the photo:" << endl;
		cin >> photo;
	}
	file << "\nPhto" << photo;
	file.close();
	cout << "Your phtot has been saved!" << endl;
}

void Data::showPhotos(const char* photoFileName)
{
	ifstream file(photoFileName);
	{
		if (!file)
		{
			cout << "File Error!" << endl;
		}
		while (!file.eof())
		{
			file >> photo;
		}
		file.close();
	}
}

void Data::free()
{
	delete[] destination;
	delete[] period;
	delete[] comment;
	delete[] photo;
}

void Data::copyFrom(const Data& other)
{
	destination = new char[strlen(other.destination) + 1];
	strcpy(destination, other.destination);

	period = new char[strlen(other.period) + 1];
	strcpy(period, other.period);

	comment = new char[strlen(other.comment) + 1];
	strcpy(comment, other.comment);

	photo = new char[strlen(other.photo) + 1];
	strcpy(photo, other.photo);
}

bool Data::checkIsPeriodValid(int month, int day, int year)
{
	bool validation = true;
	if (!(year >= 1950 && year <= 2100))
	{
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12) && day > 0 && day <= 31)
			validation = true;
		else
			if ((month == 4) || (month == 6) || (month == 9) || (month == 11) && day > 0 && day <= 30)
				validation = true;
			else
				if (month == 2)
				{
					if (((year % 400 == 0) || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29)
						validation = true;
					else if (day > 0 && day <= 28)
						validation = true;
					else
						validation = false;
				}
		validation = true;
	}
	return true;
}

bool Data::checkIsRatingValid(const int rating)
{
	if (!(rating >= 1 && rating <= 5))
	{
		return "You have entered incorrect number! Please try againg!";
	}
	return true;
}

Data::Data(const char* destination, const char* period, const char* comment)
{
	setDestinastion(destination);
	setPeriod(period);
	setComment(comment);
}

Data::Data(const Data& other)
{
	copyFrom(other);
}

Data& Data::operator=(const Data& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

Data::~Data()
{
	free();
}

void Data::setDestinastion(const char* NewDestination)
{
	delete[] destination;
	destination = new char[strlen(NewDestination) + 1];
	strcpy(destination, NewDestination);
}

void Data::setPeriod(const char* NewPeriod)
{
	delete[] period;
	period = new char[strlen(NewPeriod) + 1];
	strcpy(period, NewPeriod);
}

void Data::setComment(const char* NewComment)
{
	delete[] comment;
	comment = new char[strlen(NewComment) + 1];
	strcpy(comment, NewComment);
}

bool Data::checkifTheSecondPeriodIsGreater(char* startDate, char* endDate)
{
	cout << "Enter starting date:" << endl;
	cin >> startDate;
	cout << "Enter ending date:" << endl;
	cin >> endDate;

	if (endDate < startDate)
		throw "Invalid period";
	else
		return true;

}

void Data::print() const
{
	cout << destination << " " << period << " " << comment << " " << rating << " " << endl;
}