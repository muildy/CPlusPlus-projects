#include <iostream>

using namespace std;

void Increment()
{
	static int i = 0;
	++i;
	cout << "The value of i is : " << i << endl;
}
int main()
{
	for (int j = 0; j < 5; j++)
		Increment();
	return 0;
}