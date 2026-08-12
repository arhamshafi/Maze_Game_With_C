
#include <cmath>
#include <iostream>

using namespace std;

const double PI = 3.14159;

// Function prototypes
double expression(string s, int &p);
double term(string s, int &p);
double power(string s, int &p);
double number(string s, int &p);
double primary(string s, int &p);
void skipSpaces(string s, int &p);

// Remove spaces
void skipSpaces(string s, int &p) {
  while (p < s.length() && s[p] == ' ') {
    p++;
  }
}

// Read a number
double number(string s, int &p) {
  double num = 0;
  double decimal = 0.1;
  bool point = false;

  while (p < s.length()) {
    if (s[p] >= '0' && s[p] <= '9') {
      if (point == false) {
        num = num * 10 + (s[p] - '0');
      } else {
        num = num + (s[p] - '0') * decimal;
        decimal = decimal / 10;
      }

      p++;
    } else if (s[p] == '.') {
      point = true;
      p++;
    } else {
      break;
    }
  }

  return num;
}

// Read sin, cos, tan, sqrt and log
double primary(string s, int &p) {
  skipSpaces(s, p);

  // Negative number
  if (s[p] == '-') {
    p++;
    return -primary(s, p);
  }

  // Brackets
  if (s[p] == '(') {
    p++;

    double answer = expression(s, p);

    if (s[p] == ')') {
      p++;
    }

    return answer;
  }

  // sin
  if (s.substr(p, 3) == "sin") {
    p = p + 3;

    if (s[p] == '(')
      p++;

    double x = expression(s, p);

    if (s[p] == ')')
      p++;

    return sin(x * PI / 180);
  }

  // cos
  if (s.substr(p, 3) == "cos") {
    p = p + 3;

    if (s[p] == '(')
      p++;

    double x = expression(s, p);

    if (s[p] == ')')
      p++;

    return cos(x * PI / 180);
  }

  // tan
  if (s.substr(p, 3) == "tan") {
    p = p + 3;

    if (s[p] == '(')
      p++;

    double x = expression(s, p);

    if (s[p] == ')')
      p++;

    return tan(x * PI / 180);
  }

  // sqrt
  if (s.substr(p, 4) == "sqrt") {
    p = p + 4;

    if (s[p] == '(')
      p++;

    double x = expression(s, p);

    if (s[p] == ')')
      p++;

    return sqrt(x);
  }

  // log
  if (s.substr(p, 3) == "log") {
    p = p + 3;

    if (s[p] == '(')
      p++;

    double x = expression(s, p);

    if (s[p] == ')')
      p++;

    return log10(x);
  }

  // Normal number
  return number(s, p);
}

// Power
double power(string s, int &p) {
  double answer = primary(s, p);

  skipSpaces(s, p);

  if (p < s.length() && s[p] == '^') {
    p++;

    double second = power(s, p);

    answer = pow(answer, second);
  }

  return answer;
}

// Multiplication, division and modulus
double term(string s, int &p) {
  double answer = power(s, p);

  while (p < s.length()) {
    skipSpaces(s, p);

    if (s[p] == '*') {
      p++;

      answer = answer * power(s, p);
    }

    else if (s[p] == '/') {
      p++;

      double second = power(s, p);

      answer = answer / second;
    }

    else if (s[p] == '%') {
      p++;

      double second = power(s, p);

      answer = fmod(answer, second);
    }

    else {
      break;
    }
  }

  return answer;
}

// Addition and subtraction
double expression(string s, int &p) {
  double answer = term(s, p);

  while (p < s.length()) {
    skipSpaces(s, p);

    if (s[p] == '+') {
      p++;

      answer = answer + term(s, p);
    }

    else if (s[p] == '-') {
      p++;

      answer = answer - term(s, p);
    }

    else {
      break;
    }
  }

  return answer;
}

// Main
int main() {
  string input;

  cout << "====================================" << endl;
  cout << "       SCIENTIFIC CALCULATOR" << endl;
  cout << "====================================" << endl;

  cout << "Examples:" << endl;
  cout << "2+3*4" << endl;
  cout << "(2+3)^2" << endl;
  cout << "sin(30)+5" << endl;
  cout << "sqrt(25)+10" << endl;

  while (true) {
    cout << "\nEnter expression: ";

    getline(cin, input);

    if (input == "exit") {
      cout << "Calculator closed." << endl;
      break;
    }

    if (input == "") {
      continue;
    }

    int position = 0;

    double answer = expression(input, position);

    cout << "Answer = " << answer << endl;
  }

  return 0;
}
