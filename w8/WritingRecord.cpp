#include <algorithm>
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

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

							// continue excecution by passing exception once more
							throw;
						}
						
						activeEmp += ptr;
						delete ptr;
						ptr = nullptr;
					}
				}
			}
		}
		return activeEmp;
	}
}