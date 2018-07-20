#include "impedance_control.h"

// other_parameter里，分别为force, M, K, B
vector<double> differential_equation_of_impedence_control(double t, vector<double>& y0,vector<double>& dy, const vector<double> &other_parameter)
{
	//vector<double> y(2);
	double force = other_parameter[0];
	double M = other_parameter[1];
	double K = other_parameter[2];
	double B = other_parameter[3];

	dy[0] = y0[1];
	dy[1] = (force - K * y0[0] - B * y0[1]) / M;
	return dy;
}
