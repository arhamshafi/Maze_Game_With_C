
#include <iostream>
using namespace std;

// line by line

void Addition(), Subtraction(), Multiplication(), Division();

int main() {

  int a, b;
  char opt;

  cout << "\nEnter first Num: ";
  cin >> a;
  cout << "\nEnter Second Num: ";
  cin >> b;

  cout << "\n1: Addition\n"
       << "2: Subtraction\n"
       << "3: Multiplication\n"
       << "4: Division\n\n";
  cout << "Choose Any Operation (1-4): ";
  cin >> opt;

  switch (opt) {

  case '1':
    Addition(a, b); // argument send kr rhy hain jae ga
    break;

  case '2':
    Subtraction();
    break;

  case '3':
    Multiplication();
    break;

  case '4':
    Division();
    break;

  default:
    cout << "Invalid Error ";
  }

  return 0;
}

void Addition(int a, int b) { // parameter recive krta ha

  int sum = a + b;
  cout << "You Choose Addition Function , The Answer is:" << sum;
}

void Subtraction() {
  cout << "You Choose Subtraction Function , The Answer is:";
}

void Multiplication() {
  cout << "You Choose Multiplication Function , The Answer is:";
}

void Division() { cout << "You Choose Division Function , The Answer is:"; }
