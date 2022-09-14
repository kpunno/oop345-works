#ifndef CAR_ADS_H_
#define CAR_ADS_H_

#include <istream>

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	extern void listArgs(int argc, char* argv[]);

	class Cars {
	private:
		char* m_brand{};
		char m_model[16]{};
		int m_year{};
		double m_price{};
		char m_wear{};
		bool m_discount{};

	public:
		Cars();

		Cars& operator=(const Cars& car);

		Cars(const Cars& car);

		~Cars();

		std::istream& read(std::istream& is);

		void display(bool reset);

		char getStatus() const;

		operator bool() const;
	};

	std::istream& operator>>(std::istream& is, Cars& car);

	void operator>>(const Cars& car1, Cars& car2);
}

#endif