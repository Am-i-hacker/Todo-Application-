#include <bits/stdc++.h>
using namespace std;



void delete_line(const char *file_name, int n)
{
	fstream obj;
	obj.open(file_name, ios :: in);
	string str;
	std::vector<string> v;

	while (getline(obj, str)) {
		v.push_back(str);
	}
	obj.close();
	v.erase(v.begin() + n - 1);
	obj.open(file_name, ios::out);
	for (int i = 0; i < v.size(); i++) {
		obj << v[i] << "\n";
	}
	obj.close();

}

int main(int argc, char *argv[])
{

	if (argc == 1) {
		cout << "Usage :-\n$ ./todo add \"todo item\"  # Add a new todo\n$ ./todo ls               # Show remaining todos\n$ ./todo del NUMBER       # Delete a todo\n$ ./todo done NUMBER      # Complete a todo\n$ ./todo help             # Show usage\n$ ./todo report           # Statistics" << endl;
		return 0;
	}
	string s(argv[1]);

	if (s == "help" || argc == 1) {
		cout << "Usage :-\n$ ./todo add \"todo item\"  # Add a new todo\n$ ./todo ls               # Show remaining todos\n$ ./todo del NUMBER       # Delete a todo\n$ ./todo done NUMBER      # Complete a todo\n$ ./todo help             # Show usage\n$ ./todo report           # Statistics" << endl;
	}
	else if (s == "add") {
		if (argc == 2) {
			cout << "Error: Missing todo string. Nothing added!\n";
		}
		else {
			string temp(argv[2]);
			if (temp.length() == 0)
				cout << "Error: Missing todo string. Nothing added!\n";
			else {
				cout << "Added todo: " << '"' << argv[2] 	<< '"';
				ofstream finput;
				finput.open ("todo.txt", ios::app);
				finput << temp << "\n";
				finput.close();
			}
		}


	}
	else if (s == "ls") {
		ifstream file("todo.txt");
		string str;
		//int i = 1;
		std::vector<string> v;
		while (std::getline(file, str)) {

			v.push_back(str);

		}
		file.close();
		if (v.size() == 0)
			cout << "There are no pending todos!\n";
		else {
			for (int i = v.size() - 1; i >= 0; i--) {
				cout << "[" << i + 1 << "] " << v[i] << endl;
			}
		}

	}
	else if (s == "del") {
		if (argc == 2) {
			cout << "Error: Missing NUMBER for deleting todo.\n";
		}
		else {
			int n = atoi(argv[2]);

			ifstream file("todo.txt");
			string str;
			//int i = 1;
			std::vector<string> v;
			while (std::getline(file, str)) {

				v.push_back(str);

			}
			file.close();
			if (n == 0)
				cout << "Error: todo #0 does not exist. Nothing deleted.\n";
			else if (v.size() < n)
				cout << "Error: todo #" << n << " does not exist. Nothing deleted.\n";
			else {
				cout << "Deleted todo #" << n << endl;
				delete_line("todo.txt", n);
			}

		}


	}
	else if (s == "done") {

		if (argc == 2) {
			cout << "Error: Missing NUMBER for marking todo as done.\n";
		}
		else {

			int n = atoi(argv[2]);

			ifstream file("todo.txt");
			string str;
			//int i = 1;
			std::vector<string> v;
			while (std::getline(file, str)) {

				v.push_back(str);

			}
			file.close();
			if (n == 0)
				cout << "Error: todo #0 does not exist.\n";
			else if (v.size() < n)
				cout << "Error: todo #" << n << " does not exist.\n";
			else {
				cout << "Marked todo #" << n << " as done." << endl;
				delete_line("todo.txt", n);


				ofstream finput;
				finput.open ("done.txt", ios::app);
				finput << "x ";

				//date
				time_t now = time(0);



				tm *ltm = localtime(&now);
				finput << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " ";
				finput << v[n - 1] << "\n";
				finput.close();
			}

		}

	} else if (s == "report") {
		time_t now = time(0);



		tm *ltm = localtime(&now);
		cout << 1900 + ltm->tm_year << "-" << 1 + ltm->tm_mon << "-" << ltm->tm_mday << " ";
		long long pend = 0, comp = 0;
//for todo.txt

		ifstream file("todo.txt");
		string str;
		//int i = 1;

		while (std::getline(file, str)) {

			pend++;

		}
		file.close();

		ifstream file1("done.txt");
		string str1;
		//int i = 1;

		while (std::getline(file1, str1)) {

			comp++;

		}
		file1.close();
		cout << "Pending : " << pend << " Completed : " << comp << endl;
	}

	return 0;
}
