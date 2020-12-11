#include<iostream>
#include<cmath>
#include<ctime>
typedef unsigned int uint;
typedef bool(*funPtrType)(int);
bool isOdd(int val)
{
	return val % 2 != 0 && val > 0;
}
bool isEven(int val)
{
	return val % 2 == 0 && val > 0;
}
bool isNegative(int val)
{
	return val < 0;
}
void find(int*, size_t, bool(*)(int));
funPtrType menu();
bool (*menuViaArray())(int);

double addition(double val1, double val2)
{
	return val1 + val2;
}
double substraction(double val1, double val2)
{
	return val1 - val2;
}
double multiplication(double val1, double val2)
{
	return val1 * val2;
}
double division(double val1, double val2)
{
	return val1 / val2;
}
double arithOperation(double(*)(double, double));
double (*calculatorMenu())(double, double);

double square(double val)
{
	return val * val;
}
double cube(double val)
{
	return val * val * val;
}
double sine(double val)
{
	return sin(val);
}
double resultSCS(double(*)(double));
double (*resultSCSMenu())(double);

int* allocateMem(int* arr, size_t size)
{
	arr = new int[size];
	return arr;
}
int* freeMem(int* arr)
{
	delete[]arr;
	arr = nullptr;
	return arr;
}
void initArray(int* arr, size_t size, int a, int b)
{
	for (size_t i = 0; i < size; i++)
	{
		arr[i] = rand() % (b - a + 1) + a;
	}
}
void printArray(int* arr, size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::cout << arr[i] << " ";
	}
}

size_t defineSizeOfPrimeNums(int*, size_t);
int *primeNums(int*, size_t);
size_t defineSizeOfMultipleOf3(int*, size_t);
int *multipleOf3(int*, size_t);
size_t defineSizeOfEven(int*, size_t);
int *even(int*, size_t);
int *arrayOperation(int(*)(int*, size_t));
int (*arrayMenu())(int*, size_t);


int main()
{
	srand(time(0));
	int *arrDyn = nullptr;
	int *arrResult = nullptr;
	size_t sizeDyn, sizePrimeNums;

	const size_t size = 10;
	int arr[size] = { 2, -7, 8, 5, -6, 4, 10, 7, 5 };
	double val1, val2;
	//find(arr, size, menuViaArray());
	// 1. 
	//std::cout << arithOperation(calculatorMenu()) << std::endl;
	// 2.
	//std::cout << resultSCS(resultSCSMenu()) << std::endl;
	// 3.

	std::cout << arrayOperation(arrayMenu()) << std::endl;

	arrDyn = freeMem(arrDyn);
	arrResult = freeMem(arrDyn);
	system("pause");
	return 0;
}
void find(int*arr, size_t size, bool(*alg)(int))
{
	for (size_t i = 0; i < size; i++)
	{
		if (alg(arr[i])) std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}
funPtrType menu()
{
	bool(*ptr_fun)(int) = nullptr;
	int choice;
	std::cout << "1. isOdd\n2. isEven\n3. isNegative" << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1: ptr_fun = &isOdd; break;
	case 2: ptr_fun = &isEven; break;
	case 3: ptr_fun = &isNegative; break;
	default:
		std::cout << "Wrong choice.\n";
		break;
	}
	return ptr_fun;
}
bool (*menuViaArray())(int)
{
	bool(*funArr[])(int) = { isOdd, isEven, isNegative };
	int choice;
	std::cout << "1. isOdd\n2. isEven\n3. isNegative" << std::endl;
	std::cin >> choice;
	return funArr[choice - 1];
}

double arithOperation(double(*operation)(double, double))
{
	double val1, val2;
	std::cout << "Enter two values:\n";
	std::cin >> val1 >> val2;
	return operation(val1, val2);
}
double (*calculatorMenu())(double, double)
{
	double(*operPtr[])(double, double) = { addition, substraction, multiplication, division };
	int choice;
	std::cout << "1. add\n2. substract\n3. multiplicate\n4. divise" << std::endl;
	std::cin >> choice;
	return operPtr[choice - 1];
}

double resultSCS(double(*operation)(double))
{
	double val;
	std::cout << "Enter value:\n";
	std::cin >> val;
	return operation(val);
}
double (*resultSCSMenu())(double)
{
	double(*operPtr[])(double) = { square, cube, sine };
	int choice;
	std::cout << "1. square\n2. cube\n3. sine\n" << std::endl;
	std::cin >> choice;
	return operPtr[choice - 1];
}

size_t defineSizeOfPrimeNums(int* A, size_t size)
{
	size_t counter = 0;
	for (int* i = A; i < A + size; i++)
	{
		if (*i == 2 || *i == 3) counter++;
		int div = *i / 2;
		for (div; div > 1; div--)
		{
			if (*i % div == 0) break;
			else if (div == 2) counter++;
		}
	}
	return counter;
}
int *primeNums(int* A, size_t size)
{
	int* newArr = nullptr;
	size_t newSize = defineSizeOfPrimeNums(A, size);
	newArr = allocateMem(newArr, newSize);
	for (size_t i = 0; i < newSize; i++)
	{
		newArr[i] = 0;
	}
	size_t j = 0;
	for (int* i = A; i < A + size; i++)
	{
		if (*i == 2 || *i == 3)
		{
			newArr[j] = *i;
			j++;
		}
		int div = *i / 2;
		for (div; div > 1; div--)
		{
			if (*i % div == 0) break;
			else if (div == 2)
			{
				newArr[j] = *i;
				j++;
			}
		}
	}
	return newArr;
}
size_t defineSizeOfMultipleOf3(int* A, size_t size)
{
	size_t counter = 0;
	for (int* i = A; i < A + size; i++)
	{
		if (*i % 3 == 0) counter++;
	}
	return counter;
}
int *multipleOf3(int*A, size_t size)
{
	int* newArr = nullptr;
	size_t newSize = defineSizeOfMultipleOf3(A, size);
	newArr = allocateMem(newArr, newSize);
	for (size_t i = 0; i < newSize; i++)
	{
		newArr[i] = 0;
	}
	size_t j = 0;
	for (int* i = A; i < A + size; i++)
	{
		if (*i % 3 == 0)
		{
			newArr[j] = *i;
			j++;
		}
	}
	return newArr;
}
size_t defineSizeOfEven(int*A, size_t size)
{
	size_t counter = 0;
	for (int* i = A; i < A + size; i++)
	{
		if (*i % 2 == 0) counter++;
	}
	return counter;
}
int *even(int*A, size_t size)
{
	int* newArr = nullptr;
	size_t newSize = defineSizeOfEven(A, size);
	newArr = allocateMem(newArr, newSize);
	for (size_t i = 0; i < newSize; i++)
	{
		newArr[i] = 0;
	}
	size_t j = 0;
	for (int* i = A; i < A + size; i++)
	{
		if (*i % 2 == 0)
		{
			newArr[j] = *i;
			j++;
		}
	}
	return newArr;
}

// stuck
//int *arrayOperation(int(*operation)(int*, size_t))
//{
//	int* A = nullptr;
//	size_t size;
//	std::cout << "Enter array size:\n";
//	std::cin >> size;
//	A = allocateMem(A, size);
//	initArray(A, size, 0, 150);
//	std::cout << "Initial array:\n";
//	printArray(A, size);
//	return operation(A, size);
//}
//int (*arrayMenu())(int*, size_t)
//{
//	int(*operPtr[])(int*, size_t) = { primeNums, multipleOf3, even };
//	int choice;
//	std::cout << "1. primeNums\n2. multipleOf3\n3. even\n" << std::endl;
//	std::cin >> choice;
//	return operPtr[choice - 1];
//}
