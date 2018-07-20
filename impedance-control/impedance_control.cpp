//#include "TcPch.h"
//#pragma hdrstop
#include "impedance_control.h"

// other_parameter里，分别为force, M, K, B
vector<double> differential_equation_of_impedence_control(double t, vector<double>& y0,vector<double>& dy, const double force)
{
	double M = 0.005;
	double K = 1;
	double B = 0.12;
	double fforce = 0;
	const double min_force = 10, max_force = 50;
	if (force > min_force && force < max_force)
	{
		fforce = force - min_force;
	}
	else if (force > max_force)
	{
		fforce = 0;
	}

	dy[0] = y0[1];
	dy[1] = (fforce - K * y0[0] - B * y0[1]) / M;
	return dy;
}
