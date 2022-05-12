// SecondChanceWithTheProject.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Dairy.h"
#include "MyString.h"

int main()
{
	const char* destinationInfoFileName = "destinationInformation.txt";
	const char* photoFileName = " ";
	const char* fileName = "CustomerData.txt";
	

	Person p("Siyana", "vasileva02", "ssiyanaa.vasilevaa@abv.bg");
	Data d("Sofia", "12/03/2020-14/04/2020", "Good");

	d.destinationInfo(destinationInfoFileName);
	
	
	


}