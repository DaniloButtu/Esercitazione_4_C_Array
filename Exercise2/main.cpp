#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "Utils.hpp"

using namespace std;

int main()
{
    string input_file = "data.txt";
    double S;
    size_t n;
    double *ptr_w = nullptr;
    double *ptr_r = nullptr;

    if(!import_data(input_file, S, n, ptr_w, ptr_r))
    {
        cerr<<"Error: failed to open the file "<<input_file<<endl;
        return 1;
    }

    double V = final_value(S, n, ptr_w, ptr_r); //Compute the final value of the wallet
    double R = total_rate(S, V); //Compute the final total rate after the investment

    /*Make a summary string with the whole output*/
    string output_str = summarize_result(S, n, ptr_w, ptr_r, R, V);
    cout<<output_str<<endl; /*If I want to see results by screen*/

    /*Delete the dynamic arrays that I used in the programm*/
    delete [] ptr_w;
    delete [] ptr_r;

    /*Export results in a file*/
    string output_file = "result.txt";
    if(!export_data(output_file, output_str))
    {
        cerr<<"Error: falied to export data to the file "<<output_file<<endl;
        return 2;
    }

    return 0;
}

