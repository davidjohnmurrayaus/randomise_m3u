#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main(int argc, char** argv)
{
    using namespace std;

    srand(time(NULL));

    if(argc != 2)
    {
        cerr << "Usage: " << argv[0] << " filename.m3u\n";
        return 1;
    }

    ifstream in(argv[1]);
    if(in.good() == false)
    {
        cerr << "Couldn't open file " << argv[1] << " for reading.\n";
        return 1;
    }

    std::string header;
    std::getline(in, header);
    
    std::string buffer;
    std::map <int, std::string> items;

    std::getline(in, buffer);
    while(in.good())
    {
        items[rand()] = buffer;
        std::getline(in, buffer);
    }
    in.close();

    ofstream out(argv[1]);
    if(out.good() == false)
    {
        cerr << "Couldn't open file " << argv[1] << " for writing.\n";
        return 1;
    }

    out << header << '\n';
    std::map <int, std::string> ::iterator it = items.begin();
    while(it != items.end())
    {
        out << it->second << '\n';
        ++it;
    }
}
