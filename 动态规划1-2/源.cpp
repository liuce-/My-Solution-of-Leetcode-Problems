//ì³²¨ÄÇÆõÊıÁĞ 


#include<iostream>
int* result=nullptr;

int func(int n) {
	if (n < 0)
		exit(-1);

	if (n == 1)
		return 1;
	else if (n == 0)
		return 0;
	else if (result[n-1] != -1)
		return result[n-1];
	else 
		return result[n-1] = func(n - 1) + func(n - 2);
}

int main() {
	int n = 40;
	result = new int[n];

	for (int i = 0; i < n; i++)
		result[i] = -1;
	
	
	std::cout << func(n);
	delete[] result;

	system("pause");
	return 0;

}