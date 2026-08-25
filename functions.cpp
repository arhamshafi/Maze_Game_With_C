#include <iostream>

using namespace std;

main() {
  int obj[] = {98, 78, 54, 15, 12, 34};

  for (int i = 0; i <= 5; i++) {

    if (i == 3 || i == 4) {
      continue;
    }

    cout << obj[i] << endl;
  }
}
