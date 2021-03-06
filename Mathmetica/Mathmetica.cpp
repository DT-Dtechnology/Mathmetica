// Mathmetica.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"

using std::cout;
using std::endl;

int main()
{
	Vector2 a, b;
	a.array[0] = 1;
	a.array[1] = 2;
	b = a;
	print_test(a);
	print_test(b);
	b = b + a;
	print_test(b);

	cout << "内积：" << endl;
	cout << a * b << endl;

	cout << "反转：" << endl;
	b = a.Opposite();
	print_test(b);

	cout << "中间值" << endl;
	cout << b[1] << endl;

	cout << "单位化：" << endl;
	print_test(a.Unitized());

	system("pause");
    return 0;
}

