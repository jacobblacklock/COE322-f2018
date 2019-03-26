// disease propogation model
#include <iostream>
#include <fstream>
#include <cmath>
#include <vector>
using std::endl;
using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::ofstream;

//condition 1 is sick, 2 is susceptible, 3 is recovered, and 4 is inoculated

class person {
private:
	int condition,day,recoverydate,infected,name;
public:
	person()
	{
		condition = 2;
		day = 0;
		name = 1;
		infected = 0;
		recoverydate = -1;
	}
	
	void setdate(int Day, int Recoverydate)
	{
		day = Day;
		recoverydate = Recoverydate;
	}
	
	void setstate(int x)
	{
		condition = x;
		if (condition == 2)
                {
                        infected = 0;
                }
                else
                {
                        infected = 1;
                }
	}

	int reportday()
	{
		return day;
	}

	int reportstatus()
	{
		return condition;
	}
	
	void setname(int y)
	{
		name = y;
	}
	
	void update()
	{
		if (recoverydate==day)
		{
			condition = 3;
			day = day + 1;
		}
		else
		{	
			day = day + 1;
		}
	}	

	void infect(int n)
	{	
		if (infected == 0)
		{
		recoverydate = day + n;
		condition = 1;
		infected = 1;
		}
	}

	void status_string()
	{
		if (condition==1)
		{
		cout <<"On day "<<day<<", "<<name<<" is sick (" <<recoverydate-day <<" to go)" << endl;
		}
		else if (condition==2)
		{
		cout <<"On day "<<day<<", "<<name<<" is susceptible" << endl;
		}
		else if (condition==3)
		{
		cout <<"On day "<<day<<", "<<name<<" is recovered" << endl;
		}
		else if (condition==4)
		{
		cout <<"On day "<<day<<", "<<name<<" is inoculated" << endl;
		}
	}
	
	bool is_stable()
	{
		if (condition==2 || condition==3 || condition==4)
		{
			return true;
		}	
		else
		{
			return false;
		}
	}
};


int main()
{
	int numinoc;
	int size=100;
	int inocnum;
	int recoverarray[1000];
	int susceptiblearray[1000];
	int dayarray[1000];
	float dayaverage = 0;
	float recoveredaverage = 0;
	float susceptibleaverage = 0;
	int herdimmunity = 0;
	cout << "Size of Population?" << endl;
        cin >> size;
        cout << "Number of people inoculated?" << endl;
        cin >> numinoc;
	
	vector<person> population(size);
	
	srand(time(NULL));	
	//ofstream myfile;
	//myfile.open ("datac.txt");
	inocnum = numinoc;
for (int i=0;i<1000;i++)
{
	numinoc = inocnum;
	for (int z = 1;z<=size;z++)
	{
		population[z-1].setdate(0,-1);
		if (numinoc>0)
		{
			population[z-1].setstate(4);
			population[z-1].setname(z);
			numinoc = numinoc - 1;
		}
		else
		{
			population[z-1].setstate(2);
			population[z-1].setname(z);
		}
	}

	population[inocnum].infect(5);
	int numinfected = 1;
	float inocimpact = (float)inocnum/size;
	while (numinfected>0)
	{
		numinfected = 0;
		float contagious = 100;	
		for (int j=0;j<size;j++)
		{
			if (!population[j].is_stable())
			{
				contagious = contagious + 2;
				numinfected = numinfected + 1;
			}
		}
		for (int k=0;k<size;k++)
		{
			float bad_luck = (float)(contagious-inocimpact) *rand()/(float)RAND_MAX;
			if (bad_luck>=(100+inocimpact))
			{
				population[k].infect(5);
			}
			population[k].update();
		}
	}
	int susceptible = 0;
	int recovered = 0;
	for (int l=0;l<size;l++)
	{	
		if (population[l].reportstatus() == 2)
		{
			susceptible = susceptible + 1;
		}
		else if (population[l].reportstatus() == 3)
		{
			recovered = recovered + 1;
		}
		//population[l].status_string();
	}
	if (susceptible > 0)
	{
		herdimmunity = herdimmunity + 1;
	}
	dayarray[i] = population[0].reportday();
	recoverarray[i] = recovered;
	susceptiblearray[i] = susceptible;
}
for (int m=0;m<1000;m++)
{
	dayaverage = dayaverage + dayarray[m];
	recoveredaverage = recoveredaverage + recoverarray[m];
	susceptibleaverage = susceptibleaverage + susceptiblearray[m];
}
herdimmunity = (herdimmunity/10);
dayaverage = dayaverage/1000;
susceptibleaverage = susceptibleaverage/1000;
recoveredaverage = recoveredaverage/1000;
cout << "Population of " << size << " with " << inocnum << " inoculated" << endl;
cout << "contagiousness: " << 2 << endl;
cout << "Average time: " << dayaverage << " days" << endl;
cout << "Probability of herd immunity: " << herdimmunity << " percent" << endl;
cout << "Susceptible average: " << susceptibleaverage << endl;
cout << "Recovered average: " << recoveredaverage << endl;
/*
myfile << "Population of 100 with " << inocnum << " inoculated" << endl;
myfile << "Contagiousness: " << 5 << endl;
myfile << "Average time: " << dayaverage << " days" << endl;
myfile << "Probability of herd immunity: " << herdimmunity << " percent" << endl;
myfile << "Recovered average: " << recoveredaverage << endl;
myfile << "Susceptible average: " << susceptibleaverage << endl;
myfile << endl;
myfile.close();
*/
}






