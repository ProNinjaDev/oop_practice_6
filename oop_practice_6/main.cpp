#include <iostream>
#include <vector>
#include <locale.h>
#include "Stack.h"

int main() {
	setlocale(LC_ALL, "Rus");

	try {
		std::vector<int> arr = { 0, 5, 3 };

		int choice = 0;
		std::cout << "1) Division by zero" << std::endl;
		std::cout << "2) Out of range .ar()" << std::endl;
		std::cout << "3) Out of range []" << std::endl;
		std::cout << "4) Stack error" << std::endl;
		std::cin >> choice;

		std::cout << "+-+-+-+-+-+-+-+-+-+-+-+-+-+-+-+" << std::endl;

		if (choice == 1) {

			if (arr[0] != 0)
				int zero = arr[1] / arr[0];

			else
				throw std::runtime_error("Division by zero!");
		}

		else if (choice == 2) {
			std::cout << "Использование \".at()\":\n" << arr.at(3) << std::endl;
		}

		else if (choice == 3) {
			int index = 3;
			if (index >= arr.size())
				throw std::out_of_range("Out of range!");
			else
				std::cout << arr[index] << std::endl;
		}

		else if (choice == 4) {
			Stack<int> arrayStack(2);

			for (int i = 0; i < 5; i++) 
				arrayStack.Push(i);
			
			for (int i = 0; i < 6; i++)
				std::cout << arrayStack.Pop() << " ";
		}

		else {
			std::cout << "Invalid choice!" << std::endl;
			return 0;
		}
		
	}
	catch (const std::runtime_error& e) {
		std::cerr << e.what();
	}
	catch (const std::out_of_range& e) {
		std::cerr << e.what();
	}
	catch (const CustomError& e) {
		std::cerr << e.what();
	}


}