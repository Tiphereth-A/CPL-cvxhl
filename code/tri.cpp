#include <iostream>
#include <math.h>
using namespace std;
const double Pi = 3.141592653589793;
int main() {
  cout.setf(ios::fixed);
  cout.precision(10);
  cout << sin(30.0 / 180.0 * Pi) << endl;
  cout << cos(60.0 / 180.0 * Pi) << endl;
  cout << tan(45.0 / 180.0 * Pi) << endl;
  cout << asin(1.0) << endl;
  cout << acos(0.0) << endl;
  cout << atan(1.0) << endl;
  return 0;
}