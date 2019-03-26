//find stuff for a triangle
#include <iostream>
#include <string>
#include <cmath>
using std::cin;
using std::cout;
using std::endl;
using std::string;

struct triangle
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

int main ()
{	
	triangle triangle1,triangle2;
	cout << "Input side 1 for triangle 1: " <<endl;
	cin >> triangle1.side1;
	cout << "Input side 2 for triangle 1: " <<endl;
	cin >> triangle1.side2;
	cout << "Input side 1 for triangle 2: " <<endl;
	cin >> triangle2.side1;
	cout << "Input side 2 for triangle 2: " <<endl;
	cin >> triangle2.side2;
	calculator(&triangle1);
	calculator(&triangle2);
	
	cout << "Triangle 1: " << endl;
	cout << "The hypotenuse is = "<<triangle1.hypotenuse<<endl;
	cout << "Angle 1 is = " <<triangle1.angle1<<endl;
	cout << "Angle 2 is = " <<triangle1.angle2<<endl;
	cout << "Angle 3 is = " <<triangle1.angle3<<endl;	
	
	cout << "Triangle 2: " << endl;
	cout << "The hypotenuse is = "<<triangle2.hypotenuse<<endl;
	cout << "Angle 1 is = " <<triangle2.angle1<<endl;
	cout << "Angle 2 is = " <<triangle2.angle2<<endl;
	cout << "Angle 3 is = " <<triangle2.angle3<<endl;
}	
	
