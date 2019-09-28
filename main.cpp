#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char** argv)
{
	const char* filename;
	const int buffer_size = 50;
	if(argc!=2)
		exit(0);
	filename = argv[1];
	ifstream inputfile;
	inputfile.open(filename, ios::in);
	if(!inputfile.is_open())
		exit(0);
	cout <<"File Opened"<<endl;
	char *something = new char[buffer_size];
	char *a = something;
	while(!inputfile.eof())
	{
		*something = inputfile.get();	
		cout.put(*something);
		something++;
	}
	cout << a << endl;
	return 0;
}