#include<iostream>
#include<cmath>
using namespace std;


class Point
{
public:
	// ¸â¹ö º¯¼ö
	int x, y;

	// ¸â¹ö ÇÔ¼ö
	void Print();
	float DFO();
};

void Point::Print()
{
	cout << "( " << x << ", " << y << ")\n";

}
float Point ::DFO(){
	float a = sqrt(pow((double)x,2)+pow((double)y,2));
	return a;
 }
int main(){
	Point pt1;
	pt1.x = 100;
	pt1.y = 100;
	float a=pt1.DFO();
	cout <<"DFO:"<<a<<"\n";
	return 0;}
