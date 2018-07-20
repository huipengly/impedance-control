#ifndef _RUNGE_KUTTA_METHODS_
#define _RUNGE_KUTTA_METHODS_

#include <vector>
using std::vector;

vector<double> operator*(const double a, const vector<double> &M);
vector<double> operator/(const vector<double> &M, const double a);
vector<double> operator+(const vector<double> &A, const vector<double> &B);

typedef vector<double>(*STATEMODEL)(double t, vector<double> &y0, vector<double> &dy, const vector<double> &other_parameter);

class RungeKutta
{
public:
	RungeKutta(STATEMODEL fun, double h) : fun_(fun), h_(h) {};

	vector<double> integrate(const double t, vector<double> &y0, vector<double> &dy, const vector<double> &other_parameter);

private:
	STATEMODEL fun_;
	double h_;
};


#endif // !_RUNGE_KUTTA_METHODS_
