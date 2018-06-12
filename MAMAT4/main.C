#include "Office.H"
#include "Class.H"
#include "Child.H"
#include "Teacher.H"

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::cin;
using std::cerr;
using std::endl;
using std::string;
using std::istringstream;

int stringToInt(const string s) {
	istringstream istr(s);
	int i = 0;
	istr >> i;
	return i;
}

double stringToDouble(const string s1, const string s2) {

	istringstream istr1(s1);
	istringstream istr2(s2);
	int i; //integer part
	int j; //fraction part
	double a = 0;
	istr1 >> i;
	istr2 >> j;
	a = double(i) + double(j) / 1000; //assuming fraction part is alwways 3 digits
	return a;
}

vector<string> tokenize(string line, const char* delim) {
	unsigned int i, j;
	vector<string> tokens;
	while (!line.empty()) {
		i = line.find_first_not_of(delim);
		j = line.find_first_of(delim, i + 1);
		tokens.push_back(line.substr(i, j - i));
		if (j > line.size() - 1)
			line = "";
		else
			line = line.substr(j + 1, line.size() - j - 1);
	}
	return tokens;
}

bool check_Valid_Args(vector<string> tokens, int num) {
	if ((int)tokens.size() == num + 1)
		return true;
	else {
		cerr << "Failed - " << tokens[0]; //Is there a special way to congegate cerr outputs?
		for (unsigned int i = 1; i < tokens.size(); i++)
			cerr << " " << tokens[i];
		cerr << endl;
	}
	return false;
}

int main() {

	Office KG_Office; //KinderGarten Office
	const char* delims = " \t\n";
	vector<string> tokens;
	string line;
	unsigned int lineNumber = 1;

	while (!cin.eof()) {
		getline(cin, line);
		tokens = tokenize(line, delims);
		if (tokens.size() == 0) { //empty line
			continue;
		}

		if (tokens[0] == "addClass") {
			if (check_Valid_Args(tokens, 4)) {
				vector<string> ratio = tokenize(tokens[2], ".");
				if (KG_Office.Add_Class(stringToInt(tokens[1]), stringToDouble(ratio[0], ratio[1]), stringToInt(tokens[4]), stringToInt(tokens[3])) == FAILURE)
					cerr << "Failed - " << tokens[0] << " " << tokens[1] << " " << tokens[2] << " "
					<< tokens[3] << " " << tokens[4] << " " << endl;
			}
		}

		if (tokens[0] == "removeClass") {
			if (check_Valid_Args(tokens, 1))
				if (KG_Office.Remove_Class(stringToInt(tokens[1])) == FAILURE)
					cerr << "Failed - " << tokens[0] << " " << tokens[1] << endl;
		}

		if (tokens[0] == "addChild") {
			if (check_Valid_Args(tokens, 3))
				if (KG_Office.Add_Child(tokens[2], stringToInt(tokens[1]), tokens[3]) == FAILURE)
					cerr << "Failed - " << tokens[0] << " " << tokens[1] << " " << tokens[2] << " "
					<< tokens[3] << " " << endl;
		}

		if (tokens[0] == "addTeacher") {
			if (check_Valid_Args(tokens, 3))
				if (KG_Office.Add_Teacher(tokens[2], stringToInt(tokens[1]), stringToInt(tokens[3])) == FAILURE)
					cerr << "Failed - " << tokens[0] << " " << tokens[1] << " " << tokens[2] << " "
					<< tokens[3] << " " << endl;
		}

		if (tokens[0] == "removeChild") {
			if (check_Valid_Args(tokens, 1))
				if (KG_Office.Remove_Child(tokens[1]) == FAILURE)
					cerr << "Failed - " << tokens[0] << " " << tokens[1] << endl;
		}

		if (tokens[0] == "removeTeacher") {
			if (check_Valid_Args(tokens, 1))
				if (KG_Office.Remove_Teacher(tokens[1]) == FAILURE)
					cerr << "Failed - " << tokens[0] << " " << tokens[1] << endl;
		}

		if (tokens[0] == "PrintKindergarten") {
			if (check_Valid_Args(tokens, 0))
				KG_Office.Print();
		}

		if (tokens[0] == "sickChild") {
			if (check_Valid_Args(tokens, 1))
				if (KG_Office.Set_Sick_Child(tokens[1]) == FAILURE)
					cerr << "Failed - " << tokens[0] << " " << tokens[1] << endl;
		}

		lineNumber++;
	}
	return 0;
};
