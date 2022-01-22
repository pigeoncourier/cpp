#include <vector>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[])
{
	int * arr = (int *)malloc(sizeof(int) * 5);

	for(int i = 0; i < 5; i++) {
		arr[i] = i;
	}

	for(int i = 0; i < 5; i++) {
		printf("%d\n", arr[i]);
	}


	return 0;
}