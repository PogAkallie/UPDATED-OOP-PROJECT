#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class Person
{
private:

	char* name;
	char* password;
	char* email;
	size_t size;

	
	void free();
	void copyFrom(const Person& other);

	bool validatingName(char ch);

	/*void saveNamesToFile(const Person* customers, size_t count, ofstream& file);*/


public:

	Person createCustomer(const char* name, const char* password, const char* email);
	void saveInfoToFile(ofstream& file, const Person& p);
	Person readInfoFromFile(ifstream& file);

	Person() : name(nullptr), password(nullptr), email(nullptr), size(1024) {}
	Person(const char* name, const char* password, const char* email);
	Person(const Person& other);
	Person& operator=(const Person& other);
	~Person();

	const char* getName() const;
	char* getPassword() const;
	char* getEmail() const;

	void setName(const char* newName);
	void setPassword(const char* newPassword);
	void setEmail(const char* newEmail);

	//void getInfo(const char* fileName);

	void collectNamesInArray();

	bool linearSearch(const int* arr, int element);

	void print(const Person& p);
	
	
};

class Data
{

private:

	char* destination;
	char* period;
	int rating;
	char* comment;
	char* photo;

	void free();
	void copyFrom(const Data& other);

	bool checkIsPeriodValid(int month, int day, int year);//unvalid period of the ending date to be greater than starting
	bool checkifTheSecondPeriodIsGreater(char* startDate, char* endDate);
	/*void checkIfPhotoFileIsValid();*/
	bool checkIsRatingValid(const int rating);

	/*void destinationInfo(const char* destinationInfoFileName);*/

	

public:

	void saveDataToFile(ofstream&  file, const Data& p);
	Data readInfoFromFile(ifstream& file);

	Data() : destination(nullptr), period(nullptr), comment(nullptr), rating(0), photo(nullptr) {}
	Data(const char* destination, const char* period, const char* comment);
	Data(const Data& other);
	Data& operator=(const Data& other);
	~Data();

	void destinationInfo(const char* destinationInfoFileName);
	void showDetails(const char* destinationInfoFileName);

	void setDestinastion(const char* NewDestination);
	void setPeriod(const char* NewPeriod);
	void setComment(const char* NewComment);

	void savePhotos(const char* photoFileName);
	void showPhotos(const char* photoFileName);

	void print() const;
};