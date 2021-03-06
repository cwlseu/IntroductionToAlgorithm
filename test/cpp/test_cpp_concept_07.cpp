﻿#include <iostream>
#include <gtest/gtest.h>

class A {
public:
	A(int n) {
		value = n;
	}
	// error: invalid constructor; you probably meant ‘A (const A&)’
#if ERROR
	A(A other) { 
		value = other.value;
	}
#else
	A(const A& other) { 
		value = other.value;
	}
#endif
	void Print() {
#ifdef CONFIG_DEBUG
		std::cout << value << std::endl;
#endif
	}
private:
	int value;
};

TEST(cpp_concept, copy_construct)
{
	// A a(10);
	A a = 10;
	A b = a;
	b.Print();
}

// 编译错误。
// 在复制构造函数中传入的参数是A的一个实例。由于是传值，把形参拷贝到实参会调用复制构造函数。
// 因此如果允许复制构造函数传值，那么会形成永无休止的递归并造成栈溢出。
// 因此C++的标准不允许复制构造函数传值参数，而必须是传引用或者常量引用。