#include <vector>
#include <string>

int string_tokenizer (const std::string& input, std::vector <std::string> &container , const char& delimiter){
    int inputIndex =0;
    int containerIndex = container.size();

    while (inputIndex < input.size()){
        if( input[inputIndex] == delimiter){
            inputIndex++;//found delimiter, skip character
        }
        else{
            container.push_back("");
            while (input[inputIndex] != delimiter && inputIndex < input.size()){
                //combine the character until the code hit another delimiter or end of line
                container.at(containerIndex) += input[inputIndex];
                inputIndex ++;
             }
                    containerIndex++;
        }
    }

        return 0;
}


