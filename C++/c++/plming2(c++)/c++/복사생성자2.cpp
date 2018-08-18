#include<iostream>
using namespace std;
class ball{
public:
	ball (int x , int y);
	ball (const ball& b);
	void Print();
	void Setx(int value) { _x = value;}
    void Sety(int value) { _y = value;}   
    int  Getx()          { return _x;}
    int  Gety()          { return _y;}
public:
	static int _radius;
private:
	int _x, _y;
};

int ball::_radius=5;
void ball::Print(){
	cout << "( " << _x << ", " << _y << ")\n";}// 뭐가 다른건지 모르겠다.
ball::ball(int x , int y){	
	_x=x;
	_y=y;
	_radius = 5;
}
ball::ball(const ball & b){
	_x = b._x+2*_radius;
	_y = b._y;
	_radius = b._radius;}

int main(){
	ball ball1(3,4);
	ball ball2(ball1);
	ball1.Print();
	ball2.Print();

	return 0; } 
