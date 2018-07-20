#include "runge_kutta_methods.h"
using namespace std;

vector<double> RungeKutta::integrate(double t, vector<double>& y0, vector<double>& dy, const vector<double> &other_parameter)
{
	//TODO:funŒ¥∂®“Â±®¥Ì

	vector<double> k1 = fun_(t, y0, dy, other_parameter);

	t += h_ / 2;
	vector<double> y1 = y0 + h_ / 2 * k1;
	vector<double> k2 = fun_(t, y1, dy, other_parameter);

	vector<double> y2 = y0 + h_ / 2 * k2;
	vector<double> k3 = fun_(t, y2, dy, other_parameter);

	t += h_ / 2;
	vector<double> y3 = y0 + h_ * k3;
	vector<double> k4 = fun_(t, y3, dy, other_parameter);

	vector<double> y = y0 + h_ / 6.0 * (k1 + 2 * k2 + 2 * k3 + k4);

	return y;
}

vector<double> operator*(const double a, const vector<double> &M)
{
	vector<double> multiply;
	for (auto m : M)
	{
		multiply.push_back(m * a);
	}

	return multiply;
}

vector<double> operator/(const vector<double> &M, const double a)
{
	vector<double> divide;
	for (auto m : M)
	{
		divide.push_back(m / a);
	}

	return divide;
}

vector<double> operator+(const vector<double> &A, const vector<double> &B)
{
	vector<double> sum;
	if (A.size() != B.size())
	{
		return sum;
	}

	for (auto it1 = A.begin(), it2 = B.begin(); it1 != A.end(); ++it1, ++it2)
	{
		sum.push_back(*it1 + *it2);
	}
	return sum;
}