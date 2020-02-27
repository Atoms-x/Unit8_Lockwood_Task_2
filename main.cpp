/* Dr. Tyson McMillan
   Chet Lockwood
   26 Feb 2020
   IDE: Repl.it
   Program to practice passing a struct by point (*)
*/

#include <iostream>
#include <string>
using namespace std;

//Structures *****************************************************************
struct car
{
  string Make;
  string Model;
  int Year;
  string Color;
};

//Function Definitions ********************************************************
void printCar(car *c)
{
  cout << "\nCar details: " << endl;
  cout << "Make - " << c->Make << endl;
  cout << "Model - " << c->Model << endl;
  cout << "Year - " << c->Year << endl;
  //set the color variable based upon the year, and print it
  (c->Year > 2010) ? cout << "Color - Green\n" : cout << "Color - Red\n";
}

void preserveData(car &c)
{
  cout << "\nORIGINGAL DATA " << endl;
  printCar(&c);

  car *p_car = &c;
  cout << "\nData copied into new struct\n";
  printCar(p_car);

  new(p_car) car;
  cout << "\n" << p_car->Year << endl; //print current Year

  new(p_car) car(); //default constructor
  cout << p_car->Year << endl; //0

  cout << "\nData after default constructor reset: \n";
  printCar(p_car);

  cout << "\nCheck of Original Data\n";
  printCar(&c);
}

//Main Function ***************************************************************
int main() 
{
  //Declare an array of the struct
  car carInfo1;
  
  carInfo1.Make = "Hyundai";
  carInfo1.Model = "Genesis";
  carInfo1.Year = 2016;
  carInfo1.Color = "";

  car carInfo2 = {"GMC", "Yukon", 1975, ""};
  
  car carInfo3 = {"Toyota", "MR2", 1997, ""};
  
  //print each car
  printCar(&carInfo1);
  printCar(&carInfo2);
  printCar(&carInfo2);

  preserveData(carInfo1);

  return 0;
}