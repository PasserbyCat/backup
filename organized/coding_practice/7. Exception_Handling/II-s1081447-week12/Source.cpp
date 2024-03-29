#include "StackType.h"
#include <iostream>
//week12
int main()
{
	while (1) {
		char testing[100];
		std::cin >> testing;
		StackType check;
		for (int i = 0; i < strlen(testing); i++) {
			if (check.IsEmpty()) {
				check.Push(testing[i]);
				continue;
			}
			if (testing[i] == '(' || testing[i] == '[' || testing[i] == '{') {
				try {
					check.Push(testing[i]);
				}
				catch (FullStack& fullStack) {
					std::cout << "Exception occured: " << fullStack.what() << std::endl;
				}
			}
			try {
				if ((testing[i] == ')' && check.Top() == '(') || (testing[i] == ']' && check.Top() == '[') || (testing[i] == '}' && check.Top() == '{')) {
					check.Pop();
				}
				else if (testing[i] == ')' || testing[i] == ']' || testing[i] == '}') {
					check.Push(testing[i]);
				}
			}
			catch (EmptyStack& emptyStack) {
				std::cout << "Exception occured: " << emptyStack.what() << std::endl;
			}
		}
		if (check.IsEmpty())
			std::cout << "Well formed" << std::endl;
		else
			std::cout << "Not well formed" << std::endl;
	}
}