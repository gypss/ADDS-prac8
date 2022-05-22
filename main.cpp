#include <iostream>
#include <string>
#include <sstream>
#include "Node.h"
#include "LinkedList.h"
using namespace std;

int main(void) {

	string input;
	int values[100];
	string func = "  ";
	int f = 0;
	int j = 0;

	getline(cin, input);
	int inpLen = input.length();

	for (int i = 0; i < inpLen; i++) {

		if (input[i] >= 65 && input[i] <= 90) {
			func[f] = input[i];
			f++;
		}

		if (input[i] != ' ' && input[i + 1] != ' ' && i < inpLen - 7) {
			values[j] = ((input[i] - '0') * 10) + (input[i + 1] - '0');
			j++;
			i++;
		}
		else if (input[i] != ' ' && i < (int)input.length() - 7) {
			values[j] = input[i] - '0';
			j++;
		}

	}



	int param1 = input[inpLen -3] - '0';
	int param2 = input[inpLen-1] - '0';

	int valsLen = j;
	LinkedList list = LinkedList(values, valsLen);

	if (func == "AF") {
		list.addFront(param1);
	}
	else if (func == "AE") {
		list.addEnd(param1);
	}
	else if (func == "AP") {
		list.addAtPosition(param1, param2);
	}
	else if (func == "S ") {
		list.search(param1);
	}
	else if (func == "DF") {
		list.deleteFront();
	}
	else if (func == "DP") {
		list.deletePosition(param1);
	}
	else if (func == "DE") {
		list.deleteEnd();
	}
	else if (func == "GI") {
		list.getItem(param1);
	}


	list.printItems();
	


}