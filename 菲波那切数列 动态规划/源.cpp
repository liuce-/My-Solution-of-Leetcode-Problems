#include<iostream>
//标准
//int main() {
//	int n = 40;
//
//	int* result = new int[n + 1];
//	result[0] = 0;
//	result[1] = 1;
//	for (int i = 2; i < n + 1; i++) {
//		result[i] = result[i - 1] + result[i - 2];
//	}
//	std::cout << result[n];
//	system("pause");
//
//}

//节省空间
int main() {
	int n = 40;
	int result[3];
	result[0] = 0;
	result[1] = 1;
	
	for (int i = 2; i < n + 1; i++)
		result[i % 3] = result[(i - 1) % 3] + result[(i - 2) % 3];
	std::cout << result[n % 3];
	system("pause");
	return 0;
	
}