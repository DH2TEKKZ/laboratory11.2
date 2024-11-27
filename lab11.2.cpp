#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void replace(ifstream & t1, ofstream & t2) {
		string line;
		size_t pos1 = 0;
		size_t pos2 = 0;
		int open_parentheses_count = 0;

		while (getline(t1, line)) {
			pos1 = 0; 
			if (line.find('(') == string::npos && line.find(')') == string::npos) {
				t2 << line << endl;
				continue;
			}

			while ((pos1 = line.find('(', pos1)) != string::npos) {
				open_parentheses_count++; 
				pos2 = line.find(')', pos1);

				if (pos2 == string::npos) {
					cout << "Error: " << endl;
					return;
				}
				line.erase(pos1, pos2 - pos1 + 1); 
			}

			t2 << line << endl; 
		}
	}

int main()
{
	ifstream t1("t1.txt");
	string line;
	if (!t1.is_open()) {
		cerr << "Error opening file!" << endl;
		return -1;
	}
	while (getline(t1, line)) {
		cout << line << endl;
	}
	cout << endl << endl;
	t1.clear();
	t1.seekg(0, ios::beg);

	ofstream t2("t2.txt");

	replace(t1, t2);

	t1.close();
	t2.close();


	ifstream t2new("t2.txt");
	string line2;
	if (!t2new.is_open()) {
		cerr << "Error opening file!" << endl;
		return -1;
	}
	while (getline(t2new, line2)) {
		cout << line2 << endl;
	}

	t2new.close();

	return 0;
}