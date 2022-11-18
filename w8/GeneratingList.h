#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool luhnAlgo(const std::string str) {
			int result{ 0 }, count{ 0 };
			int i = static_cast<int>(str.length() - 1);

			for (i; i >= 0; i--) {
				++count;
				int val = str[i] - '0';
				if (count % 2 == 0) {
					val *= 2;
					if (val > 9) {
						val -= 9;
					}
				}
				result += val;
			}
			return result % 10 == 0;
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(T* ptr) {
			list.push_back(*ptr);
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(std::unique_ptr<T>&& ptr) {
			list.push_back(*ptr);
		}

		
		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
