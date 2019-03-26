//find stuff for a triangle
#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

/*struct triangle
{
	float side1;
	float side2;
	float angle1;
	float angle2;
	float angle3;
	float hypotenuse;
};

void calculator(triangle* tri)	
{
	tri->hypotenuse = sqrt(pow(tri->side1,2) + pow(tri->side2,2));
	tri->angle1 = (atan(tri->side2/tri->side1))*(180/M_PI);
	tri->angle2 = 90 - tri->angle1;
	tri->angle3 = 90;
}
*/
class triangle
{
private:
	float side1,side2,hypotenuse,angle1,angle2,angle3;
public:
	triangle()
	{
	side1 = 1; side2 = 1; angle3 = 90;
	}
	triangle(float side3, float side4)
	{
	side1 = side3;	
	side2 = side4;
	angle3 = 90;
	}
	
	void calculator()
	{
	hypotenuse = sqrt(pow(side1,2) + pow(side2,2));
	angle1 = (atan(side2/side1))*(180/M_PI);
	angle2 = 90 - angle1;
	}
	
	void printvalues()
	{
        cout << "The hypotenuse is = "<<hypotenuse<<endl;
        cout << "Angle 1 is = " <<angle1<<endl;
        cout << "Angle 2 is = " <<angle2<<endl;
        cout << "Angle 3 is = " <<angle3<<endl;
	}
};


int main ()
{	
	float side1,side2,side3,side4;
	cout << "Input side 1 for triangle 1: " <<endl;
	cin >> side1;
	cout << "Input side 2 for triangle 1: " <<endl;
	cin >> side2;
	cout << "Input side 1 for triangle 2: " <<endl;
	cin >> side3;
	cout << "Input side 2 for triangle 2: " <<endl;
	cin >> side4;
	
	triangle triangle1(side1,side2),triangle2(side3,side4);
	triangle1.calculator();
	triangle2.calculator();

	cout << "Triangle 1: " << endl;
	triangle1.printvalues();

	cout << "Triangle 2: " << endl;
	triangle2.printvalues();
}	
	
