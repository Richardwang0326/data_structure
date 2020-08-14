#include <iostream>
#include <math.h>

int countPrimes(int n) {
    int num = 0;
    if(n < 0)
        return 0;
    for(int i = 2; i < n; i++)
    {
        for(int j = sqrt(i); j > 0; j--)
        {
            if((i % j) == 0)
            {
                if(j == 1)
                    num += 1;
                else
                    break;
            }
        }
    }
    return num;
}

int main()
{
    std::cout << countPrimes(INT32_MAX) << std::endl;
    return 0;
}