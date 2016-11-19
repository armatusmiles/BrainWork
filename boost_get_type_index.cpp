#include <iostream>
#include <vector>
#include <boost/type_index.hpp>

template<typename T>
void f(const T& param)
{
	using std::cout;
	using std::endl;
	using boost::typeindex::type_id_with_cvr;

	cout << "T = " 
		<< type_id_with_cvr<T>().pretty_name()
		<< endl;

	cout << "param = "
		<< type_id_with_cvr<decltype(param)>().pretty_name()
		<< endl << endl;
}

int main()
{
	int x = 0;
	auto a = &x;
	char *ch = "text";
	f(a);
	f(ch);
	std::vector<int> s;
	f(s);
}
