#include <cassert>
#include <iostream>
#include <vector>

/* Задача на программирование повышенной сложности: огромное число Фибоначчи по 
	Даны целые числа 1≤n≤10181≤n≤1018 и 2≤m≤1052≤m≤105, необходимо найти остаток от деления n-го числа Фибоначчи на m */

class Fibonacci final {
	using ull = unsigned long long;
public:
	static std::vector<ull> get_period(ull m)
	{
		std::vector<ull> period{ 0, 1 };
		for (int i = 1; i < 6 * m; i++)
		{
			period.push_back((period[i - 1] + period[i]) % m);
			if (period[i - 1] % m == 1 && period[i] % m == 1 && i > 3)
			{
				period.erase(period.end() - 4, period.end());
				break;
			}
		}
		return period;
	}

	static int get_remainder(int64_t n, int m) 
	{
		assert(n >= 1);
		assert(m >= 2);
		std::vector<ull> v = Fibonacci::get_period(m);
		return v[n % v.size()];
	}

};

int main(void) 
{
	int64_t n;
	int m;
	std::cin >> n >> m;
	std::cout << Fibonacci::get_remainder(n, m) << std::endl;
	return 0;
}