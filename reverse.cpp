#include <iostream>

int reverse(int x)
{
	int result = 0;
	while(x != 0)
	{	
		if((result > INT32_MAX / 10) || ((result == INT32_MAX / 10) && (x > INT32_MAX % 10)))
			return 0;
		else if((result < INT32_MIN / 10) || ((result == INT32_MIN / 10) && (x < INT32_MIN % 10)))
			return 0;
		else
		{
			result = result * 10 + x % 10;
			x /= 10;
		}
	}
	return result;
}

int main()
{
	int x;
	std::cout << "input one number: ";
	std::cin >> x;

	std::cout << reverse(x) << std::endl;
}
