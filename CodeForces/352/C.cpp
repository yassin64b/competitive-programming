#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;

#define eps (1e-4)

typedef long long ll;

int tx, ty, n;
double naive = 0;

inline double dist(double x, double y)
{
	return sqrt(x*x + y*y);
}

double solve(vector<int>& x, vector<int>& y, int ax, int ay, int bx, int by)
{
	double minvalue = numeric_limits<double>::max();
	int ind;
	for(int i = 0; i < n; ++i)
	{
		double tmp = min(minvalue, naive + dist(x[i]-ax, y[i]-ay) - dist(x[i]-tx, y[i]-ty));
		if(minvalue - tmp > eps)
			ind = i;
		minvalue = tmp;		
	}
	//cout << ind << endl;

	double ret = minvalue;
	for(int i = 0; i < n; ++i)
	{
		if(i == ind) continue;
		ret = min(ret, minvalue + dist(x[i]-bx, y[i]-by) - dist(x[i]-tx, y[i]-ty));
	}
	return ret;
}



int main()
{
	int ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by >> tx >> ty >> n;

	vector<int> x(n), y(n);
	
	for(int i = 0; i < n; ++i)
	{
		cin >> x[i] >> y[i];
		naive += dist(x[i]-tx, y[i]-ty) * 2;
	}

	cout << setprecision(16);

	if(n == 1)
	{
		double ret = min(dist(x[0]-ax,y[0]-ay), dist(x[0]-bx,y[0]-by));
		ret += dist(x[0]-tx, y[0]-ty);
		cout << ret << endl;
		return 0;
	}

	double ret1 = solve(x, y, ax, ay, bx, by);
	double ret2 = solve(x, y, bx, by, ax, ay);
	//cout << ret1 << " " << ret2 << endl;
	cout << (ret1 < ret2 ? ret1 : ret2) << endl;

	return 0;
}