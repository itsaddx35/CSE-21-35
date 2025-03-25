#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int countLines(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Could not open file " << filename << endl;
        return -1;
    }

    int lineCount = 0;
    string line;

    while (getline(file, line))
    {
        lineCount++;
    }

    file.close();
    return lineCount;
}

int main()
{
    string filename;

    cout << "Enter the filename: ";
    getline(cin, filename);

    int lines = countLines(filename);

    if (lines >= 0)
    {
        cout << "The file '" << filename << "' has " << lines << " lines." << endl;
    }

    return 0;
}
