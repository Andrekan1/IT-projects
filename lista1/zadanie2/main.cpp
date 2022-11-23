#include <iostream>
#include <cmath>

using namespace std;

struct Vector {
	public:

		static auto Length(double tab[2][2]) {
			double temptab[2];
			for(short i = 0; i <= 1; i++)
				temptab[i] = pow(tab[1][i]-tab[0][i],2);

			return sqrt(temptab[0]+temptab[1]);
		}

		static auto Dot(double tab[2][2]) {
			double temptab[2];
			for(short i = 0; i <= 1; i++)
				temptab[i] = tab[0][i]*tab[1][i];

			return temptab[0]+temptab[1];
		}

		static auto Equal(const double tab[2]) {
			if(tab[0] == tab[1])
				return true;

			return false;
		}

		static auto AAvg(double tab[2][2]) {
			double temptab[2] = {0,0};
			for(short i = 0; i <= 1; i++)
				temptab[i] = (tab[0][i] + tab[1][i]) / 2;

			return pair(temptab[0],temptab[1]);
		}

		static auto GAvg(double tab[2][2]) {
			double temptab[2] = {1,1};
			for(short i = 0; i <= 1; i++)
				temptab[i] = sqrt(tab[0][i] * tab[1][i]);

			return pair(temptab[0],temptab[1]);
		}

		static auto Median(double tab[2][2]) {
			double tab1d[4];
			for(short i = 0; i <= 1; i++)
				for(short j = 0; j <= 1; j++)
					tab1d[i==0 ? j : i+j+1] = tab[i][j];

			for(short i = 0; i < 4; i++) {
				for(short j = 0; j < 3; j++) {
					if(tab1d[j] > tab1d[j+1]) {
						double temp = tab1d[j + 1];
						tab1d[j + 1] = tab1d[j];
						tab1d[j] = temp;
					}
				}
			}

			return (tab1d[1]+tab1d[2])/2;
		}
};

double tableMaxElement(double tab[2][2]) {
    double max = 0;
	for(short i = 0; i < 2; i++)
		for(short j = 0; j < 2; j++)
			if(tab[i][j] > max)
				max = tab[i][j];
	return max;
}

int main() {
    double tab[2][2];
    cout << "Podaj wspolrzedne wektorow" << endl;
    for(auto &i : tab)
		for(double &j : i)
            cin >> j;

	double len = Vector::Length(tab);
	cout << "\nDlugosc wektora wynosi: " << len << endl;

	tab[2][2] = {};
	double vectors[2];
	for (short k = 0; k < 2; k++) {
		/*cout << "Podaj wspolrzedne dla " << (k == 0 ? "pierwszego" : "drugiego") << " wektrora" << endl;
		for(auto &i: tab) {
			for(double &j: i) {
				cin >> j;
			}
		}*/
		vectors[k] = Vector::Length(tab);
	}

	pair<double,double> aavg = Vector::AAvg(tab);
	cout << "Srednia arytmetyczna wektoru to: [" << aavg.first << ", " << aavg.second << "]" << endl;

	pair<double,double> gavg = Vector::GAvg(tab);
	cout << "Srednia geometryczna wektoru to: [" << gavg.first << ", " << gavg.second << "]" << endl;

	double median = Vector::Median(tab);
	cout << "Mediana wektoru to: " << median << endl;

	if(Vector::Equal(vectors)) {
		double dot = Vector::Dot(tab);
		cout << "Iloczyn skalarny dwoch podanych wektorow wynosi: " << dot << endl;
	}

	double max = tableMaxElement(tab);
	cout << "Maksymalny element tablicy: " << max << endl;


    return 0;
}
