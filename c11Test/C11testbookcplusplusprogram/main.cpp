#include <iostream>
using namespace std;
// meaning roughly "I promise not change this value"
const int dmv = 17;// you can't change the dmv variable to other value;

double square( double x){
	return x * x;
}
const double max2 = 1.4 * square(dmv);
// meaning roughly "to be evaluated at compile time"
constexpr double max1 = 1.4 * dmv;
// There is a error in the book c++ programing language
// the demo expresstion constexpr double max1 = 1.4 * square(dmv) will be
// complited with a error in vs2015;
void print_square(double x) {
	cout << "the square of" << x << " is " << square(x) << endl;
}
bool accept3() {
	int tries = 1;
	while (tries < 4)
	{
		cout << "Do you want to process(y or n)?\n";
		char answer = 0;
		cin >> answer;

		switch (answer)
		{
		case 'y':
			cout << "you input y" << endl ;
			return true;
		case 'n':
			cout << "you input n" << endl;
			return false;
		default:
			cout << "Sorry, I don't understand that.\n";
			++tries;
		}
	}
	cout << "I'll take that for a no.\n";
	return false;
}
void autoAndNewForTest() {
	int v[] = { 1,2,3,4,5,6,7,8,9 };
	for (auto x:v) 
	{
		cout << x << ' ';
	}
	cout << endl;
	for (auto &x : v) {
		++x;
	}
	for (auto x : v) 
	{
		cout << x << ' ';
	}
	cout << endl;
	for (auto x : { 10,12,32,45,67 }) {
		cout << x << " ";
	}
	cout << endl;
}
// test nullptr
int count_charx(char*p, char x) {
	if (p == nullptr) {
		return 0;
	}
	int nCount = 0;
	while (*p != 0) {
		if (*p == x) {
			++nCount;
		}
		++p;
	}
	return nCount;
}
int main() {
	std::cout << "Hello World!" << std::endl;
	print_square(1.234);
	std::cout << max1 << endl;
	std::cout << max2 << endl;
	autoAndNewForTest();
	const auto nCount = count_charx("fsdafsdafxxxxxdfdsafxxxxxsdsxsfdd", 'f');
	cout << nCount << endl;
	const bool temp = accept3();
	cout << temp << endl;
	getchar();

}