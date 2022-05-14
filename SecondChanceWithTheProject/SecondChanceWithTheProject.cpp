// SecondChanceWithTheProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dairy.h"
#include "MyString.h"

int main()
{
	/*const char* destinationInfoFileName = "destinationInformation.txt";
	const char* photoFileName = " ";
	const char* fileName = "CustomerData.txt";
	*/

	/*Person p("Siyana", "vasileva02", "ssiyanaa.vasilevaa@abv.bg");
	Data d("Sofia", "12/03/2020-14/04/2020", "Good");*/

	/*d.destinationInfo(destinationInfoFileName);*/
	Person p;
	Person p1 = p.createCustomer("Siyana", "123456", "siyana@abv.bg");

	ofstream f1("CustomerData.txt", ios::binary);
	if (!f1.is_open())
	{
		cout << "File Error!" << endl;
	}

	p.saveInfoToFile(f1, p1);


	ifstream f2("CustomerData.txt", ios::binary);

	if (!f2.is_open())
	{
		cout << "File Error";
	}

	Person p2 = p.readInfoFromFile(f2);

	p.print(p2);




}