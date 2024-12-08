#include <iostream>

bool isLeap(int year) {
	int remainder = year % 4;
	if (remainder == 0) {
		return true;
	}
	else
	{
		return false;
	} 
}


template <typename arrCount>
arrCount arrMidCount(arrCount arr[], int arrSize) {
	arrCount sum = 0;
	for (int i = 0; i < arrSize; i++) {
		sum += arr[i];
	}
	sum = sum / arrSize;
		return sum;
}

int main() {
	const int size = 3;
	float array[size]{ 4.2,2.5,6.5 };
	std::cout << arrMidCount(array, size);
}