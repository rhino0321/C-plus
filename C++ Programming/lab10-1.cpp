#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void checkspace(int [], int &, string);
void display(ofstream &, int [], int, string, int);


int main(int argc, char *argv[])
{
    char *infile = argv[1];
    char *outfile = argv[2];
    ifstream in_file(infile);
    ofstream out_file(outfile);
    if (in_file.fail())
    {
        cout << "Error open input file !";
        exit(1);
    }
    if (out_file.fail())
    {
        cout << "Error open output file !" << endl;
        exit(1);
    }
    string textline;
    int count = 1;
    while (getline(in_file, textline, '\n'))
    {
        int space[10], space_use = 0;
        checkspace(space, space_use, textline);
        display(out_file, space, space_use, textline, count);
        count++;
    }
    in_file.close();
    out_file.close();
    cout << "Done!!!" << endl;
    return 0;
}

void checkspace(int space[], int &space_use, string str1)
{
    int i=0;
    while (i < str1.length())
    {
        i = str1.find(" ", ++i); // ++i means search space from space next char
        if (i == string::npos)
            break;
        else
        {
            space[space_use] = i;
            space_use++;
        }
    }
}

void display(ofstream& out_file, int space[], int space_use, string str1, int count)
{
    int start=0;
    out_file << "line " << count << " has " << space_use + 1 << " words,";
    for (int i=0; i<space_use; i++)
    {
        out_file << " \"" << str1.substr(start, space[i] - start) << "\",";
        start = space[i] + 1;
    }
    out_file << " \"" << str1.substr(start, str1.length() - start - 1) << "\"" << endl;
}