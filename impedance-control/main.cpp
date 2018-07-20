#include "impedance_control.h"
#include "runge_kutta_methods.h"
#include <iostream>
using std::cout; using std::endl;

int main()
{
	RungeKutta rk4(differential_equation_of_impedence_control, 0.02);
	vector<double> y0{ 0, 0 }, dy(2);
	double force, fforce;
	double M{ 0.005 }, K{ 1 }, B{ 0.12 };

	force = 20;//单位N
	if (force>100)
		force = 0;
	if (force <= 10)
		fforce = 0;
	if (force>10)
		fforce = force - 10;
	for (double ix = 0; ix <= 4; ix += 0.01)
	{
		if (fabs(ix - 2) < 1e-5)
		{
			force = 30;
			if (force>100)
				force = 0;
			if (force <= 10)
				fforce = 0;
			if (force>10)
				fforce = force - 10;
			cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
		}
		y0 = rk4.integrate(ix, y0, dy, force);
		cout << y0[0] << endl;
	}

	cout << "press any key to continue..." << endl;
	getchar();
	return 0;
}