#ifndef CAR_ADS_H_
#define CAR_ADS_H_

extern double g_taxrate;
extern double g_discount;

namespace sdds {
	extern void listArgs(int argc, char* argv[]);

	class Cars {
	private:
		char m_brand[11]{};
		char m_model[16]{};
		int m_year{};
		double m_price{};
		char m_wear{};
		bool m_discount{};

	public:
		Cars();

		std::istream& read(std::istream& is);

		void display(bool reset);

		char getStatus() const;
	};
}

#endif