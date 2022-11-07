/*
==============
= WORKSHOP 6 =
==============

Name----Kristjan Punno
Email-- - kpunno@myseneca.ca
ID------ 150695211
Section - NCC
Date---- 2022 - 11 - 06
+ ---------------------------------------------------------------------- +
| I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments. |
+---------------------------------------------------------------------- +
*/

// Workshop 6 - STL Containers
// 2020/02/26 - Cornel

#ifndef SDDS_VEHICLE_H
#define SDDS_VEHICLE_H

#include <iostream>
#include <string>

namespace sdds
{
	class Vehicle
	{
	public:

		// interface for ... 

		// returning a vehicle's top speed
		virtual double topSpeed() const = 0;

		// displaying a vehicle
		virtual void display(std::ostream&) const = 0;

		// returning a vehicle's condition
		virtual std::string condition() const = 0;
		
		// destruction of a vehicle
		virtual ~Vehicle() {};
	};
}

#endif
