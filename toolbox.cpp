#include "toolbox.h"
#include <sstream>
#include <vector>

    string int_toStr(int input){
        std::ostringstream intConverter;

        intConverter <<input;

        return intConverter.str();
    };

    int str_toInt(const string& input){
        std::istringstream stringConverter (input);

        int result;

        stringConverter >>result;

        return result;
    };

    bool isNumeric(const string& input){
        if( input.size() ==0){
            return false;
        }

        for (const char& oneChar : input){

            if (!isdigit(oneChar)){
                return false;
            }
        }
        return true;
    };

    bool checkRange(const string& input, int min, int max){

        if(isNumeric(input)){
            int inputAsInt = str_toInt(input);
            if(min <= inputAsInt && inputAsInt <=max){
                return true;
            }

        }
        return false;
    };

    int string_tokenizer (const std::string& input, std::vector <std::string> &container , const char& delimiter){
        size_t inputIndex =0;
        int containerIndex = container.size();

        while (inputIndex < input.size()){
            if( input.at(inputIndex) == delimiter){
                inputIndex++;//found delimiter, skip character
            }
            else{
                container.push_back("");
                while (inputIndex < input.size() && input.at(inputIndex) != delimiter){
                    //combine the character until the code hit another delimiter or end of line
                    container.at(containerIndex) += input.at(inputIndex);
                    inputIndex ++;
                }
                    containerIndex++;
            }
        }

        return 0;
    };
