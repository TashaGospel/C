#include <iostream>
#include <math.h>
using namespace std;

class point
{
	int x,y;
public:
	void input() {cin >> x >> y;}
	float length(point);
	float circum(point,point);
};

float point::length(point d)
{
	return sqrt(pow(x-d.x,2)+(pow(y-d.y,2)));
}

float point::circum(point d1,point d2)
{
	return length(d1)+d1.length(d2)+d2.length(*this);
}
	
int main()
{
	point *p = new point[3];
	for (int i=0; i<=2; i++) {p[i].input();}
	cout << p[0].circum(p[1],p[2]);		
} 
