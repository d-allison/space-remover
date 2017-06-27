#include <iostream>
#include <string>
#include <fstream>


using namespace std;

string replace(string subject, const string& search, const string& replace) {
    size_t pos = 0;
    while ((pos = subject.find(search, pos)) != string::npos) {
         subject.replace(pos, search.length(), replace);
         pos += replace.length();
    }
    return subject;
}
int main()
{
    string filePath;

    cout << "Running v1.0 of space-remover" << endl;
    cout << "Please provide the path to the file you wish to remove spaces from." << endl;

    cin >> filePath;

    ifstream inputFile;
    inputFile.open(filePath);

    ofstream outputFile;
    outputFile.open("output.csv");

    string currentLine;
    string line;

    if(inputFile.is_open() & outputFile.is_open())
    {
        while(getline(inputFile, line))
        {
            currentLine = line;
            outputFile << replace(line, ", ", ",") << '\n';

        }
    }
    inputFile.close();
    outputFile.close();

    return 0;
}
