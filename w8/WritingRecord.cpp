/*
Name ---- Kristjan Punno
Email --- kpunno@myseneca.ca
ID ------ 150695211
Section - NCC
Date ---- 2022-11-20
+ ---------------------------------------------------------------------- +
| I have done all the coding by myself and only copied the code that  |
|  my professor provided to complete my workshops and assignments. |
+---------------------------------------------------------------------- +
*/

#include <memory>
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"



namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;

		// iterate through emp (containing names)
		for (size_t i{ 0 }; i < emp.size(); i++) {

			// for each employee iterate through sal ...
			for (size_t j{ 0 }; j < sal.size(); j++) {

				// if a match is found between a 'name' and a 'salary'
				if (emp[i].id == sal[j].id) {

					// if the SIN is valid
					if (activeEmp.luhnAlgo(emp[i].id)) {

						// ptr points to dynamically allocated EmployeeWage
						EmployeeWage* ptr = new EmployeeWage{ emp[i].name, sal[j].salary };

						// try validation
						try {
							ptr->rangeValidator();
						}
						// ensure deletion if exception occurs
						catch (...) {
							delete ptr;

							// continue to throw
							throw;
						}

						activeEmp += std::move(ptr);
						delete ptr;
						ptr = nullptr;
					}
				}
			}
		}
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		// TODO: Add your code here to build a list of employees
		//         using smart pointers

		// iterate through emp (containing names)
		for (size_t i{ 0 }; i < emp.size(); i++) {

			// for each employee iterate through sal ...
			for (size_t j{ 0 }; j < sal.size(); j++) {

				// if a match is found between a 'name' and a 'salary'
				if (emp[i].id == sal[j].id) {

					// if the SIN is valid
					if (activeEmp.luhnAlgo(emp[i].id)) {

						// ptr points to dynamically allocated EmployeeWage
						std::unique_ptr<EmployeeWage> ptr(new EmployeeWage{ emp[i].name, sal[j].salary });

						ptr->rangeValidator();
						activeEmp += std::move(ptr);
					}
				}
			}
		}
		
		return activeEmp;
	}
}