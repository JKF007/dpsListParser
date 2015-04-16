/*
 * File:   main.cpp
 * Author: James
 *
 * Created on March 21, 2015, 2:33 PM
 */

#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include "line_checker.h"
#include "toolbox.h"

using std::cout;
using std::cin;
using std::string;
using std::getline;

string rangeCheckedInput (int lower, int upper){
    string inputLine;
    std::getline(cin, inputLine);
    while ( !checkRange(inputLine,lower,upper) ) {
        cout <<"invalid input, please try again\n";
        cout << inputLine<<std::endl ;
        std::getline(cin, inputLine);
    }

    return inputLine;
};

int main() {
    std::ifstream input_file;
    std::ofstream output_file;
    std::vector<string> tokenizedInput;
    string inputLine;
    line_checker parser;

    cout <<"please enter removal option \n";
    cout <<"1. all small arms \n";
    cout <<"2. infantry weapon only\n";

    inputLine = rangeCheckedInput(1,2);

    if(inputLine.compare("1") ==0){
        parser.setList("remove_list.txt","retain_list.txt");
    }
    else{
        parser.setList("remove_list_for_adjusted.txt","retain_list_for_adjusted.txt");
    }

    cout <<"please enter operating mode\n";
    cout <<"1.normal mode\n";
    cout <<"2.test mode\n";

    inputLine = rangeCheckedInput(1,2);

    if(inputLine.compare("1") ==0){
        input_file.open("coh2WeaponDpsInput.csv");
    }
    else{
        input_file.open("test.csv");
    }

    output_file.open("coh2WeaponDpsOutput.csv");


    if(input_file.is_open()){
        output_file <<"weapon name,0,10,20,30,40,50,60\n";
        while(input_file.good()){

            tokenizedInput.clear();

            std::getline (input_file,inputLine);
            string_tokenizer(inputLine,tokenizedInput, ',');

            if( parser.check(tokenizedInput)){

                string weapon_name = tokenizedInput.at(0);
                output_file << weapon_name << ",";

                for (int cellNum = 4; cellNum <= 10; cellNum++){
                    string stringToken = tokenizedInput.at(cellNum);
                    output_file << stringToken <<",";
                }
                output_file<<"\n" ;
            }

        }
    }

    input_file.close();
    output_file.close();
    return 1;
}
