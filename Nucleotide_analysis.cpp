#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
using namespace std;

int main() {

    string filename;
    cout << "Enter FASTA filename: ";
    cin >> filename;

    ifstream infile(filename);

    if (!infile) {
        cout << "Error: File not found!" << endl;
        return 1;
    }

    string line;
    string sequence = "";
    string header = "";

   
    while (getline(infile, line)) {
        if (line[0] == '>') {
            header = line;   
        } 
        else {
            sequence = sequence + line;  
        }
    }

    infile.close();

    
    string accession = "";
    string description = "";

    int space_pos = header.find(' ');

    if (space_pos != -1) {
        accession = header.substr(1, space_pos - 1);
        description = header.substr(space_pos + 1);
    } 
    else {
        accession = header.substr(1);
        description = "No description available";
    }

    
    int A = 0, T = 0, G = 0, C = 0, unknown = 0;

    for (int i = 0; i < sequence.length(); i++) {
        char base = toupper(sequence[i]);

        if (base == 'A') A++;
        else if (base == 'T') T++;
        else if (base == 'G') G++;
        else if (base == 'C') C++;
        else unknown++;   
    }

    int length = sequence.length();


    double A_percent = (double(A) / length) * 100;
    double T_percent = (double(T) / length) * 100;
    double G_percent = (double(G) / length) * 100;
    double C_percent = (double(C) / length) * 100;
    double gc_percent = (double(G + C) / length) * 100;

    
    cout << "\n===== Nucleotide Sequence Analysis =====\n";
    cout << "Accession Number : " << accession << endl;
    cout << "Description      : " << description << endl;
    cout << "Total Length     : " << length << endl;

    cout << "\nBase Percentages:\n";
    printf("A %%  : %.2f%%\n", A_percent);
    printf("T %%  : %.2f%%\n", T_percent);
    printf("G %%  : %.2f%%\n", G_percent);
    printf("C %%  : %.2f%%\n", C_percent);
    printf("GC %% : %.2f%%\n", gc_percent);
    

    cout << "\nUnknown bases : " << unknown << endl;

    return 0;
}


                                                                                                                   75,1          80%
