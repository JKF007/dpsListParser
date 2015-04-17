#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>
#include "line_checker.h"
#include "toolbox.h"
#include <regex>

using std::string;

line_checker::line_checker(){};


    line_checker::line_checker(const std::string& remove_list_file_name, const std::string& retain_list_file_name){
        setList(remove_list_file_name, retain_list_file_name);
    };

    int line_checker::setList(const std::string& remove_list_file_name, const std::string& retain_list_file_name){
        change_list(remove_list, remove_list_file_name);
        change_list(retain_list, retain_list_file_name);
        return 1;
    };

    int line_checker::change_list( std::vector< std::string > &thelist, const std::string& input_file_name){

        std::ifstream file_stream (input_file_name);

        if (file_stream.is_open()) {

            while( file_stream.good() ){

                std::string input;
                file_stream >> input;
                thelist.push_back(input);
            }
        }

        file_stream.close();
        return 1;
    };

    bool line_checker::check(const std::vector <std::string> &tokenizedInput){
        if (tokenizedInput.size() <12){
            return false;
        }
        std::string name = tokenizedInput.at(0);

        if(retained(name)){
            return true;
        }
        if(removed(name)){
            return false;
        }
        std::string mp_marker = name.substr(name.size()-3);
        if(mp_marker.compare("_mp") !=0){
            return false;
        }

        std::string type = tokenizedInput.at(11);
        if(type.compare("small_arms") !=0 ){
            return false;
        }
        int validNum =0;

        for (int cellNum = 4; cellNum <=10; cellNum++){
            string cellString = tokenizedInput.at(cellNum);

            int cellVal = std::atoi (cellString.c_str()) ;
            if (cellVal >0){
                validNum++;
            }
        }

       if (validNum == 0){
           return false;
       }

       return true;
    };




    bool line_checker::retained(const std::string& name){

        for (auto retained_name : retain_list){
            if (name.compare(retained_name)==0) {
                return true;
            }
        }
        return false;
    }

    bool line_checker::removed(const std::string& name){

        for (auto removed_name : remove_list){
            if (name.compare(removed_name) ==0) {
                return true;
            }
            else if (removed_name.compare("everything") ==0){
                return true;
            }

        }
        return false;
    }
