#include <iostream>
#include <math.h>

using namespace std;

//BCS370 Thomas Barrella Homework Assignment 2 
//create the template
template<class C>
//create the class
class Circle {
  private:
  //create the private data member radius
  C radius;

  public:
    Circle(C r=0):radius(r) {}
      //sets radius equal to r and initializes all circles at 0
     

    //creates the friend function and overrides operator>>, returns input
    friend istream &operator>>(istream &inp, Circle &circle1) {
      inp >> circle1.radius;
      return inp;
    }

    //creates the friend function and overrides operator<<
    friend ostream &operator<<(ostream &out, Circle circle1) {
      out << "\nRadius: " << circle1.radius << endl;
      //uses the math.h pow
      out << "\nArea: " << 3.1415 * (pow(circle1.radius,2)) << endl;
      //pow calculation without using pow
      //out << "\nArea: " << (circle1.radius * circle1.radius) * 3.1415 << endl;
      return out;
    }

    //takes the num value and adds it to radius, double so it can be a non-whole number
    void operator+(double num) {
      this->radius = this->radius + num;
    }

};



int main() {
  //run a few test circles of various sizes
  Circle test1(2);
  cout << test1;

  Circle test2(65);
  cout << test2;

  //test that a non-whole number radius works
  Circle test3(4.5);
  cout << test3;

  //testing the operator+ by adding 2 to test1 
  test1 + 2;
  cout << test1;
}