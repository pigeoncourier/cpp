#include <vector>
#include <iostream>

using namespace std;

int main()
{
	printf("Hello!\n");
	std::vector<int> myints;
	myints.push_back(1);
	printf("%ld",myints.size());
	return 0;
}
