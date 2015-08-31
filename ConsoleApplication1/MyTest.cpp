#include <iostream>
#include <string>

using namespace std;

void trim(string& s) {
	size_t blank = s.find_first_of(" ");
	//size_t last = s.find_last_not_of(" \t\n\f");
	//size_t last = s.find_last_not_of(" \t\n\f");
	if (blank != string::npos) {
		s.erase(blank);
		//blank = s.find_first_of(" ", blank+1);
	}
}

string parenthetical(const std::string& s) {
	string temp = "------- Possible Strings were found! ---------\n";
	if (s.empty() || s == " ")
		return "blank";	
	size_t found = s.find_first_of('(');
	int index = 0;
	if (found == string::npos) {
		return "close";
	}
	else {
		while (found != string::npos) {
			size_t found2 = s.find_last_of(')');
			if (found2 == string::npos) {
				return "open";
			}
			else {				
				while (found2 != string::npos) {
					for (int i = found + 1; i < found2; i++) {
						temp += s[i];
					}
					temp += '\n';
					found2 = s.find_last_of(')', found2 - 1);
				}
				found = s.find_first_of('(', found + 1);
			}			
		}
	}
	return temp;
}


int main() {

	string test = " asdfsdf 2    ";
	//string test2 = "3";
	//cout << test2 + test << endl;
	trim(test);
	cout << test<< endl;

	/*string temp = "  sefr)";
	string temp2 = "(  ";
	string temp3 = " ";
	string temp4 = " (S)A(DFSDx  FS(FSDFS DF)";
	string str = parenthetical(temp);
	string str2 = parenthetical(temp2);
	string str3 = parenthetical(temp3);
	string str4 = parenthetical(temp4);
	
	cout << str << '\n';
	cout << str2 << '\n';
	cout << str3 << '\n';
	cout << str4 << '\n';*/

	system("pause>nul");

	return 0;
}
