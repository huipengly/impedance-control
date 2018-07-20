#ifndef _IMPEDENCE_CONTROL_
#define _IMPEDENCE_CONTROL_

#include <vector>
using std::vector;

vector<double> differential_equation_of_impedence_control(double t, vector<double>& y0, vector<double>& dy, const vector<double> &other_parameter);

#endif // !_IMPEDENCE_CONTROL_