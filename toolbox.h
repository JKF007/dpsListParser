#ifndef TOOLBOX
#define TOOLBOX

#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>

using std::string;

string int_toStr(int input);

int str_toInt(const string& input);

bool isNumeric(const string& input);

bool checkRange(const string& input, int min, int max);

int string_tokenizer (const std::string& input, std::vector <std::string> &container , const char& delimiter);

#endif
