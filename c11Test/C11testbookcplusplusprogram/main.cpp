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
struct Vector
{
	int sz;
	double* elem;
};
void vect_init(Vector& v, int s) {
	v.elem = new double[s];
	v.sz = s;
}
void vect_clear(Vector& v) {
	if (v.elem) {
		delete[] v.elem;
		v.elem = nullptr;
	}
}
double read_and_sum(int s) {
	Vector v;
	vect_init(v,s);
	for (int i = 0; i < s; ++i) {
		cin >> v.elem[i];
	}
	double sum = 0;
	for (int i = 0; i < s; ++i) {
		sum += v.elem[i];
	}
	vect_clear(v);
	return sum;
}
void runTestStruct(){
	const double dResult = read_and_sum(3);
	cout << dResult << endl;
}
class Vector_Class
{
public:
	Vector_Class(int s) : elem(new double[s]), sz(s) {

	}
	double& operator[](int i) {
		return elem[i];
	}
	int size() {
		return sz;
	}
	~Vector_Class() {
		if (elem) {
			delete[] elem;
			elem = nullptr;
 		}
	}
protected:
private:
	double* elem;
	int sz;
};
double read_and_sum_class() {
	Vector_Class v(3);
	// int v2[4] = {};
	for (int i = 0; i != v.size(); ++i)
	{
		cin >> v[i];
	}
	double sum = 0;
	for (int i = 0; i != v.size(); ++i) {
		sum += v[i];
	}
	return sum;
}
// enum class; in the scope of their enum class
enum class Traffic_light
{
	green,
	yellow,
	red
};
Traffic_light& operator++(Traffic_light&t) {
	switch (t)
	{
	case Traffic_light::green:
		return t = Traffic_light::yellow;
	case Traffic_light::yellow:
		return t = Traffic_light::red;
	case Traffic_light::red:
		return t = Traffic_light::green;
	}
}
void printTrafficColor(Traffic_light light) {
	switch (light)
	{
	case Traffic_light::green:
		cout << "green" << endl;
		break;
	case Traffic_light::yellow:
		cout << "yellow" << endl;
		break;
	case Traffic_light::red:
		cout << "red" << endl;
		break;
	default:
		break;
	}
}
void test_color(Traffic_light light) {
	printTrafficColor(light);
	Traffic_light next = ++light;
	printTrafficColor(light);
	printTrafficColor(next);
}
int main() {
	std::cout << "Hello World!" << std::endl;
	print_square(1.234);
	std::cout << max1 << endl;
	std::cout << max2 << endl;
	autoAndNewForTest();
	const auto nCount = count_charx("fsdafsdafxxxxxdfdsafxxxxxsdsxsfdd", 'f');
	cout << nCount << endl;
	runTestStruct();
	const double temp2 = read_and_sum_class();
	cout << temp2 << endl;
	test_color(Traffic_light::red);
	const bool temp = accept3();
	cout << temp << endl;

	getchar();

}