#include <cmath>
#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// ============================================================
// CONSTANTS
// ============================================================
const double PI = 3.14159265358979323846;
const double E = 2.71828182845904523536;

// ============================================================
// FUNCTION PROTOTYPES
// ============================================================
double expression(string s, int &p);
double term(string s, int &p);
double power(string s, int &p);
double number(string s, int &p);
double primary(string s, int &p);
void skipSpaces(string s, int &p);

// ============================================================
// FUNCTION 1: skipSpaces - Spaces hataana
// ============================================================
void skipSpaces(string s, int &p) {
  while (p < s.length() && s[p] == ' ') {
    p++;
  }
}

// ============================================================
// FUNCTION 2: number - String se number banana
// ============================================================
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

// ============================================================
// FUNCTION 3: primary - Basic elements handle karna
// ============================================================
double primary(string s, int &p) {
  skipSpaces(s, p);

  // 1. NEGATIVE NUMBER
  if (s[p] == '-') {
    p++;
    return -primary(s, p);
  }

  // 2. BRACKETS
  if (s[p] == '(') {
    p++;
    double answer = expression(s, p);
    if (s[p] == ')') {
      p++;
    }
    return answer;
  }

  // 3. SIN - Sine function (degree mein)
  if (s.substr(p, 3) == "sin") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return sin(x * PI / 180);
  }

  // 4. COS - Cosine function (degree mein)
  if (s.substr(p, 3) == "cos") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return cos(x * PI / 180);
  }

  // 5. TAN - Tangent function (degree mein)
  if (s.substr(p, 3) == "tan") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return tan(x * PI / 180);
  }

  // 6. SQRT - Square root
  if (s.substr(p, 4) == "sqrt") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return sqrt(x);
  }

  // 7. LOG - Log base 10
  if (s.substr(p, 3) == "log") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return log10(x);
  }

  // 8. LN - Natural log (base e)
  if (s.substr(p, 2) == "ln") {
    p = p + 2;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return log(x);
  }

  // 9. EXP - Exponential (e^x)
  if (s.substr(p, 3) == "exp") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return exp(x);
  }

  // 10. ABS - Absolute value
  if (s.substr(p, 3) == "abs") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return fabs(x);
  }

  // 11. FACT - Factorial
  if (s.substr(p, 4) == "fact") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    double result = 1;
    for (int i = 1; i <= x; i++) {
      result = result * i;
    }
    return result;
  }

  // 12. CBRT - Cube root
  if (s.substr(p, 4) == "cbrt") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return cbrt(x);
  }

  // 13. ASIN - Arc sine
  if (s.substr(p, 4) == "asin") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return asin(x) * 180 / PI;
  }

  // 14. ACOS - Arc cosine
  if (s.substr(p, 4) == "acos") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return acos(x) * 180 / PI;
  }

  // 15. ATAN - Arc tangent
  if (s.substr(p, 4) == "atan") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return atan(x) * 180 / PI;
  }

  // 16. SINH - Hyperbolic sine
  if (s.substr(p, 4) == "sinh") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return sinh(x);
  }

  // 17. COSH - Hyperbolic cosine
  if (s.substr(p, 4) == "cosh") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return cosh(x);
  }

  // 18. TANH - Hyperbolic tangent
  if (s.substr(p, 4) == "tanh") {
    p = p + 4;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return tanh(x);
  }

  // 19. PI constant
  if (s.substr(p, 2) == "pi") {
    p = p + 2;
    return PI;
  }

  // 20. E constant
  if (s.substr(p, 1) == "e") {
    if (s.substr(p, 3) != "exp") {
      p = p + 1;
      return E;
    }
  }

  // 21. DEG - Degree to radian
  if (s.substr(p, 3) == "deg") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return x * PI / 180;
  }

  // 22. RAD - Radian to degree
  if (s.substr(p, 3) == "rad") {
    p = p + 3;
    if (s[p] == '(')
      p++;
    double x = expression(s, p);
    if (s[p] == ')')
      p++;
    return x * 180 / PI;
  }

  // Normal number
  return number(s, p);
}

// ============================================================
// FUNCTION 4: power - Power operator (^)
// ============================================================
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

// ============================================================
// FUNCTION 5: term - *, /, %
// ============================================================
double term(string s, int &p) {
  double answer = power(s, p);

  while (p < s.length()) {
    skipSpaces(s, p);

    if (s[p] == '*') {
      p++;
      answer = answer * power(s, p);
    } else if (s[p] == '/') {
      p++;
      double second = power(s, p);
      if (second != 0) {
        answer = answer / second;
      } else {
        cout << "Error: Division by zero!" << endl;
        return 0;
      }
    } else if (s[p] == '%') {
      p++;
      double second = power(s, p);
      answer = fmod(answer, second);
    } else {
      break;
    }
  }

  return answer;
}

// ============================================================
// FUNCTION 6: expression - +, -
// ============================================================
double expression(string s, int &p) {
  double answer = term(s, p);

  while (p < s.length()) {
    skipSpaces(s, p);

    if (s[p] == '+') {
      p++;
      answer = answer + term(s, p);
    } else if (s[p] == '-') {
      p++;
      answer = answer - term(s, p);
    } else {
      break;
    }
  }

  return answer;
}

// ============================================================
// MAIN FUNCTION
// ============================================================
int main() {
  string input;

  cout << "============================================================"
       << endl;
  cout << "              SCIENTIFIC CALCULATOR" << endl;
  cout << "============================================================"
       << endl;
  cout << endl;

  cout << "SUPPORTED FUNCTIONS:" << endl;
  cout << "------------------------------------------------------------"
       << endl;
  cout << "  sin(x)  cos(x)  tan(x)  sqrt(x)  cbrt(x)" << endl;
  cout << "  log(x)  ln(x)   exp(x)  abs(x)   fact(x)" << endl;
  cout << "  asin(x) acos(x) atan(x) sinh(x)  cosh(x)" << endl;
  cout << "  tanh(x) deg(x)  rad(x)  pi       e" << endl;
  cout << "------------------------------------------------------------"
       << endl;
  cout << "OPERATORS:  +  -  *  /  %  ^  (  )" << endl;
  cout << "------------------------------------------------------------"
       << endl;
  cout << "EXAMPLES:" << endl;
  cout << "  2 + 3 * 4" << endl;
  cout << "  (2 + 3) ^ 2" << endl;
  cout << "  sin(30) + cos(60)" << endl;
  cout << "  sqrt(25) + log(100)" << endl;
  cout << "  fact(5) + exp(2)" << endl;
  cout << "  pi * 2" << endl;
  cout << "============================================================"
       << endl;
  cout << endl;

  cout << "Type 'exit' to close the calculator" << endl;
  cout << "============================================================"
       << endl;
  cout << endl;

  while (true) {
    cout << "Enter expression: ";
    getline(cin, input);

    if (input == "exit" || input == "EXIT") {
      cout << "============================================================"
           << endl;
      cout << "              CALCULATOR CLOSED" << endl;
      cout << "============================================================"
           << endl;
      break;
    }

    if (input == "") {
      continue;
    }

    int position = 0;
    double answer = expression(input, position);

    cout << "------------------------------------------------------------"
         << endl;
    cout << "  " << input << " = ";

    if (answer == (int)answer) {
      cout << (int)answer << endl;
    } else {
      cout << fixed << setprecision(6) << answer << endl;
    }
    cout << "------------------------------------------------------------"
         << endl;
    cout << endl;
  }

  return 0;
}