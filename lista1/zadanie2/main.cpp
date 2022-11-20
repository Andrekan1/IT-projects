#include <iostream>
#include <cmath>

using namespace std;

struct Vector {
	static double Length(double tab[2][2]) {
		double temptab[2];
		for(short i = 0; i <= 1; i++)
			temptab[i] = pow(tab[1][i]-tab[0][i],2);
		return sqrt(temptab[0]+temptab[1]);
	}

	static double Dot(double tab[2][2]) {
		double temptab[2];
		for(short i = 0; i <= 1; i++)
			temptab[i] = tab[i][0]*tab[i][1];
		return temptab[0]+temptab[1];
	}

	static bool Equal(double tab[2]) {
		if(tab[0] == tab[1])
			return true;
		return false;
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
	cout << "Dlugosc wektora wynosi: " << len << endl << endl;


	tab[2][2] = {};
	double vectors[2];
	for (short k = 0; k < 2; k++) {
		cout << "Podaj wspolrzedne dla " << (k == 0 ? "pierwszego" : "drugiego") << " wektrora" << endl;
		for(auto &i: tab) {
			for(double &j: i) {
				cin >> j;
			}
		}
		vectors[k] = Vector::Length(tab);
	}

	if(Vector::Equal(vectors)) {
		double dot = Vector::Dot(tab);
		cout << "Iloczyn skalarny dwoch podanych wektorow wynosi: " << dot << endl;
	}

	double max = tableMaxElement(tab);
	cout << "Maksymalny element tablicy: " << max << endl;


    return 0;
}
