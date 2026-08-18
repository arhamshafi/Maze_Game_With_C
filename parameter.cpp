
#include <iostream>
using namespace std;

void addition();

int main() {

  int a = 34;
  int b = 20;

  cout << "\nvalue of a is:" << a << endl;
  cout << "value of a is:" << b;
  cout << "\n\n";

  addition(a, b);

  return 78;
}

void addition() {

  cout << "\n\nvalue of first parameter is: " << a;
  cout << "\n";
  cout << "value of second parameter is: " << b;
  cout << "\n\n";
}