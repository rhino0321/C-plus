#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <sstream>
using namespace std;

// function declaration
typedef struct
{
    string name;
    long id;
    int age;
    string gender;
} student;

void display(ofstream &, student *, int);
void read_txt(char*, char*, student*);

int main(int argc, char *argv[])
{
    student* uee1302;
    char *infile, *outfile;
    if (strcmp(argv[1], "-i") == 0 && strcmp(argv[3], "-o") == 0)
    {
        infile = argv[2];
        outfile = argv[4];
        read_txt(infile, outfile, uee1302);
    }
    else if (strcmp(argv[1], "-o") == 0 && strcmp(argv[3], "-i") == 0)
    {
        infile = argv[4];
        outfile = argv[2];
        read_txt(infile, outfile, uee1302);
    }
    delete []uee1302;
    return 0;
}

void read_txt(char* infile, char* outfile, student* uee1302)
{
    int num, idx = 0;
    string tok, token;
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
    getline(in_file, tok);
    num = stoi(tok);
    uee1302 = new student[num];
    while (getline(in_file, tok))
    {
        istringstream iss(tok);
        int index = 0;
        while (getline(iss, token, ' '))
        {
            switch (index){
                case 0 : (uee1302 + idx)->name = token; break;
                case 1 : (uee1302 + idx)->id = stol(token); break;
                case 2 : (uee1302 + idx)->age = stoi(token); break;
                case 3 : (uee1302 + idx)->gender = token; break;
            }
            index++;
        }
        idx++;
    }
    display(out_file, uee1302, num);
}

void display(ofstream& out_file, student* uee1302, int num)
{
    int num_boy = 0;
    double avg_age = 0;
    out_file << "There are:";
    for (int i = 0; i < num; i++)
    {
        if (i == 0)
            out_file << " " << (uee1302 + i) -> name;
        else if (i == num - 1)
            out_file << " and " << (uee1302 + i) -> name << endl;
        else
            out_file << ", " << (uee1302 + i) -> name;
        if ((uee1302 + i) -> gender == "M")
            num_boy++;
        avg_age += (uee1302 + i) -> age;
    }
    out_file << "Their average age is " << avg_age / 5 << " years old." << endl;
    out_file << "There are " << num_boy
         << " boys and "
         << num - num_boy
         << " girls." 
         << endl;
    cout << "Done!!" << endl;
}