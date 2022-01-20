#include <iostream>
#include <vector>
#include <string>

using namespace std;

void func(int n){
    int i, count = 0;
    for(i=1; i*i<=n; i++){
        count++;
    }
    std::cout << count << std::endl;
}

int main()
{
    func(19);
}
