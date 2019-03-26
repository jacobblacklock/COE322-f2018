#include <iostream>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;

class point {
private:
	double px,py;

public: 
	point()
	{
		px = 1; py = 1;
	}
	point(double x, double y)
	{
		px = x; py = y;
	};
	
	double getx() { return px; };
	double gety() { return py; };
	
	void setx(double x) { px = x; };
	void sety(double y) { py = y; };
	
	void printpoint()
	{
		cout << "(" << px << "," << py << ")" <<endl;
	} 

	double distance(point p2)
	{
		return sqrt(pow(p2.getx()-px,2) + pow(p2.gety()-py,2));
	}	

	double distance_to_origin()
	{
		return sqrt(pow(0-px,2) + pow(0-py,2));
	}	

};

class line
{
private:
	point p1,p2;
	double px,py;
public:
	line()
	{
		p1.setx(1);
		p1.sety(1);
		p2.setx(2);
		p2.sety(2);
	}
	
	line(point p3, point p4)
	{
		p1.setx(p3.getx());
		p1.sety(p3.gety());
		p2.setx(p4.getx());
		p2.sety(p4.gety());
	}
	
	void printline()
	{
		p1.printpoint();
		p2.printpoint();
	}

	point midpoint()
	{	
		point p3;
		double x = (p1.getx() + p2.getx())/2;
		p3.setx(x);
		double y = (p1.gety() + p2.gety())/2;
		p3.sety(y);
		return p3; 
	}

};
	



double distanceBetweenPoints(point p1, point p2)
{
	return sqrt(pow(p2.getx()-p1.getx(),2) + pow(p2.gety()-p1.gety(),2));
}




int main () 
{
	point p1(2,2),p2(3.5,7.8);
	//p1.printpoint();
	//p2.printpoint();

	//old way, calling a function
	//double distance = distanceBetweenPoints(p1,p2);
	//cout << "Distance between the points: " << distance << endl;

	//new way, calling a method in class
	//cout << p1.distance(p2) << endl;		
	//cout << p1.distance_to_origin() << endl;
	
	//line normal;
	//normal.printline();
	//point p3 = normal.midpoint();
	//p3.printpoint();
	
}



