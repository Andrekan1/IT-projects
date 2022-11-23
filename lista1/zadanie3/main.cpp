#include <iostream>
#include <cmath>

using namespace std;

struct PhysObj {
	float pi = M_PI;
	float g = 9.8066f;

	static auto GetHorizontalPos(float h, float t, float v, float tmax) {
		PhysObj phys;
		float y = h - (phys.g/2)*t;
		float x = v * t;

		return t <= tmax ? pair<float,float>(x,y) : pair<float,float>(v*sqrt(2*h/phys.g),0);
	}

	static auto GetDiagonalPos(float v0x, float v0y, float t, float tmax) {
		PhysObj phys;
		float y = v0y*t - (phys.g/2)*t;
		float x = v0x*t;
		return t <= tmax ? pair<float,float>(x,y) : pair<float,float>(v0x*tmax,0);
	}

	static auto GetVelocity(float vx, float vy) {
		auto x = pow(vx,2);
		auto y = pow(vy,2);
		return sqrt(x+y);
	}

	static auto DegToRad(float a) {
		PhysObj phys;
		a = a * phys.pi / 180;
		return a;
	}
};

int main() {
	PhysObj phys;
	float h0,v0,t;

	cout << "Podaj wysokosc poczatkowa, predkosc poczatkowa, czas dla wyznaczenia polozenia (rzut poziomy): " << endl;
	cin >> h0 >> v0 >> t;
	if(h0 < 0 or t < 0 or v0 < 0) { cout << "Wprowadzone bledne dane: " << (h0 < 0 ? "h0" : t < 0 ? "t" : "v0") << endl; return EXIT_FAILURE;}

	float tmax = sqrt(2*h0/phys.g);
	cout << "Rzut poziomy:" << endl;
	double v = phys.GetVelocity(v0,t <= tmax ? phys.g*t : phys.g*tmax);
	cout << "\tPredkosc objektu w chwili t(" << t << "s): " << v << " m/s" << endl;

	auto pos = phys.GetHorizontalPos(h0,t,v0,tmax);
	cout << "\tPozycja objektu w chwili t(" << t << "s): " << "(" << pos.first << "m, " << pos.second << "m)" << endl;

	////////////////////////

	cout << "\nPodaj kat poczatkowy, predkosc poczatkowa, czas dla wyznaczenia polozenia (rzut ukosny): " << endl;
	float a; cin >> a >> v0 >> t;
	if(a >= 90 or a <= 0) { cout << "Wprowadzone bledne dane, kat ma byc od 0 do 90 stopni" << endl; return EXIT_FAILURE;}

	cout << "\nRzut ukosny: " << endl;

	a = phys.DegToRad(a);
	float v0x = v0 * cos(a), v0y = v0 * sin(a);
	tmax = (2*v0y)/phys.g;
	cout << tmax << endl;
	v = phys.GetVelocity(v0x,t <= tmax ? v0y - (phys.g*t) : v0y - (phys.g*tmax));
	cout << "\tPredkosc objektu w chwili t(" << t << "s): " << v << " m/s" << endl;

	pos = phys.GetDiagonalPos(v0x,v0y,t,tmax);
	cout << "\tPozycja objektu w chwili t(" << t << "s): " << "(" << pos.first << "m, " << pos.second << "m)" << endl;

	return 0;
}
