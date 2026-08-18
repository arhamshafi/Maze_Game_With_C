#include <iostream>
using namespace std;

float usdToPkr(float usd);
float pkrToUsd(float pkr);
float usdToEuro(float usd);
float euroToUsd(float euro);

int main() {
  float amount;
  int choice;

  cout << "1. USD to PKR" << endl;
  cout << "2. PKR to USD" << endl;
  cout << "3. USD to Euro" << endl;
  cout << "4. Euro to USD" << endl;
  cout << "Choose option: ";
  cin >> choice;

  cout << "Enter amount: ";
  cin >> amount;

  switch (choice) {
  case 1:
    cout << amount << " USD = " << usdToPkr(amount) << " PKR" << endl;
    break;
  case 2:
    cout << amount << " PKR = " << pkrToUsd(amount) << " USD" << endl;
    break;
  case 3:
    cout << amount << " USD = " << usdToEuro(amount) << " Euro" << endl;
    break;
  case 4:
    cout << amount << " Euro = " << euroToUsd(amount) << " USD" << endl;
    break;
  default:
    cout << "Invalid choice!" << endl;
  }

  return 0;
}

float usdToPkr(float usd) {
  return usd * 280; // Example rate
}

float pkrToUsd(float pkr) { return pkr / 280; }

float usdToEuro(float usd) {
  return usd * 0.92; // Example rate
}

float euroToUsd(float euro) { return euro / 0.92; }