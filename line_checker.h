#ifndef LINE_CHECKER
#define LINE_CHECKER

#include <cstdlib>
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
#include <map>

class line_checker{
    private:
        //std::vector< std::vector<std::string> > retain_list;
        //std::vector< std::vector<std::string> > remove_list;

        //std::map< std::string, std::vector<std::string> >  retain_list;
        //std::map< std::string, std::vector<std::string> >  remove_list;

        std::vector< std::string > remove_list;
        std::vector< std::string > retain_list;

        int change_list( std::vector< std::string > &list, const std::string& input_file);

    public:
        line_checker();

        line_checker(const std::string& remove_list, const std::string& retain_list);

        int setList(const std::string& remove_list, const std::string& retain_list);

        bool check(const std::vector <std::string> &tokenizedInput);

        bool removed(const std::string& name);

        bool retained(const std::string& name);

};
#endif
