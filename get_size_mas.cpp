#include <iostream>
#include <array>

template<typename T, std::size_t N>
constexpr std::size_t arraySize(T (&)[N]) noexcept
{
	return N;
}

// constexpr - Makes result available during compilation

int main()
{
	int ar[] = { 3,5,10,40,50 };
	int new_mas[arraySize(ar)];
	std::array<int, arraySize(new_mas)> maqws;

	std::cout << "size mas = " << arraySize(ar)
		<< std::endl;
}