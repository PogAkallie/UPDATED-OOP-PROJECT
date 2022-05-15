// SecondChanceWithTheProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dairy.h"
#include "MyString.h"

int main()
{
	//const char* destinationInfoFileName = "destinationInformation.txt";
	//const char* photoFileName = " ";
	//const char* fileName = "CustomerData.txt";
	//

	//Person p("Siyana", "vasileva02", "ssiyanaa.vasilevaa@abv.bg");
	//Data d("Sofia", "12/03/2020-14/04/2020", "Good");

	////d.destinationInfo(destinationInfoFileName);
	//d.showDetails(destinationInfoFileName);

	/*Person p;
	Person p1 = p.createCustomer("Siyana", "123456", "siyana@abv.bg");

	ofstream f1("CustomerData.txt", ios::binary);
	if (!f1.is_open())
	{
		cout << "File Error!" << endl;
	}

	p.saveInfoToFile(f1, p1);
	f1.close();

	ifstream f2("CustomerData.txt", ios::binary);

	if (!f2.is_open())
	{
		cout << "File Error";
	}

	Person p2 = p.readInfoFromFile(f2);

	p.print(p2);
	f2.close();*/

	//DATA

	Data d;
	Data d1 = d.createDestinationInfo("Sofia", "15/02/2020-16/02/2020", "Very good", 8);

	ofstream f1("destinationInformation.txt", ios::binary);

	if (!f1.is_open())
	{
		cout << "File Error!" << endl;
	}
	d.saveDataToFile(f1, d1);
	f1.close();

	ifstream f2("destinationInformation.txt", ios::binary);
	if (!f2.is_open())
	{
		cout << "File Error!" << endl;
	}
	Data d2 = d.readInfoFromFile(f2);
	d.print(d2);
	f2.close();

}