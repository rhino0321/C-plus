#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

void checkspace(int [], int &, string, string&);
void display(ofstream &, int [], int, string);


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
    string textline, str2;
    getline(in_file, textline);
    int space[100], space_use = 0;
    checkspace(space, space_use, textline, str2);
    display(out_file, space, space_use, str2);
    in_file.close();
    out_file.close();
    cout << "Done!!!" << endl;
    return 0;
}

void checkspace(int space[], int &space_use, string str1, string& str2)
{
    int i=0, j=0;
    while (i < str1.length())
    {
        if (str1[i] == ',' && !(str1[i+1] >= '0' && str1[i+1] <= '9') && !(str1[i+1] == ' '))
        {
            str2 += str1[i];
            str2 += ' ';
        }
        else
            str2 += str1[i];
        i++;
    }
    while (j < str2.length())
    {
        j = str2.find(" ", ++j); // ++i means search space from space next char
        if (j == string::npos)
            break;
        else
        {
            space[space_use] = j;
            space_use++;
        }
    }
}

void display(ofstream& out_file, int space[], int space_use, string str1)
{
    int start = 0, i = 0, line_length = 0;
    while (i < space_use)
    {
        int dot = 0, line_length;
        if (i - 1 < 0)
            line_length = 0;
        else
            line_length = space[i-1] + 1;
        while (space[i] - line_length + dot < 60 && i < space_use)
        {
            for (int j=start; j<=space[i]; j++)
            {
                if (str1[j] == ',' && !(str1[j+1] >= '0' && str1[j+1] <= '9') && !(str1[j+1] == ' '))
                {
                    out_file << str1[j] << " ";
                    dot++;
                }
                else if (str1[j] == '.')
                {
                    line_length = j;
                    out_file << str1[j] << endl;
                }
                else
                    out_file << str1[j];
            }
            start = space[i] + 1;
            i++;
        }
        if (i!= space_use)
            out_file << endl;
    }
    out_file << str1.substr(start, str1.length() - start + 1);
}
