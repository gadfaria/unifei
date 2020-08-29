#include <iostream>
#include "CPilha.h"

using namespace std;

int main()
{
	CPilha<int> p{50};
	CPilha<float> p1{50};
	CPilha<char> p2{50};
	CPilha<CPilha<int>> p3{50};
}
