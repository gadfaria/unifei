#include <iostream>
#include "date.h" // Date class definition
using namespace std;

int main()
{
   Date d1;
   Date d2;
   Date d3;
   cout << "Format :: MONTH / DAY / YEAR\n"
        << endl;

   cout << "Enter the date 1: " << endl;
   cin >> d1;
   cout << "Enter the date 2: " << endl;
   cin >> d2;
   cout << "Enter the date 3: " << endl;
   cin >> d3;

   cout << "\n\nd1 += 7 is " << (d1 += 7);

   cout << "\n\n  d2 is " << d2;
   cout << "\n++d2 is " << ++d2 << " (leap year allows 29th)";

   cout << "\n\nTesting the prefix increment operator:\n"
        << "  d3 is " << d3 << endl;
   cout << "++d3 is " << ++d3 << endl;
   cout << "  d3 is " << d3;

   cout << "\n\nTesting the postfix increment operator:\n"
        << "  d3 is " << d3 << endl;
   cout << "d3++ is " << d3++ << endl;
   cout << "  d3 is " << d3 << endl;
}
