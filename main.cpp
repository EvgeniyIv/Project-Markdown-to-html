#include <string.h>
#include <fstream>
#include <string>
#include <iostream>

#include "convertToHTML.h"
#include "Md_file.h"

using namespace std;

/**
 * Bool
 */
bool need_paragraph = true;
bool current_paragraph = false;
bool current_list = false;

string changeExtensionFile(string& file_name);

int main() {

	string file_name;

	string line;
	string parsed_line;

	cout << "Welcome to Markdown-HTML converter" << endl;

	cout << endl;

	cout << "Please to enter a file name" << endl;

	cin >> file_name;

	Md_file* md_file = new Md_file(file_name);

	ofstream outfile;

	outfile.open(changeExtensionFile(file_name).c_str(), ios::out);

	if (!md_file->openFile()) {
		cout << "File not found..." << endl;
		return 1;
	}

	cout << "File opened" << endl;

	convertToHTML convert_to_html;

	cout << endl;

	while (getline(md_file->getFile(), line)) {
		outfile << convert_to_html.parseline(line) << endl;
	}

	md_file->closeFile();

	outfile.close();

	cout << endl;

	delete md_file;

}

string changeExtensionFile(string& file_name) {
	return file_name.substr(0, (file_name.rfind(".") + 1)) + "html";
}
