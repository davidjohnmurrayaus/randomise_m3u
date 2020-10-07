#include <climits>
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <random>

/**
 * Entry point.
 * @param argc Number of command line arguments.
 * @param argv Array of command line arguments.
 */
int main(int argc, char** argv)
{
    using std::cerr;

    std::default_random_engine generator;
    std::uniform_int_distribution<int> distribution(INT_MIN, INT_MAX);

    std::string inputFilename;
    std::string outputFilename;

    if (argc == 2)
    {
        inputFilename = argv[1];
        outputFilename = inputFilename;
    }
    else if (argc == 3)
    {
        inputFilename = argv[1];
        outputFilename = argv[2];
    }
    else
    {
        cerr << "Usage:\n"
            << "\t" << argv[0] << " <filename.m3u>\n"
            << "\t" << argv[0] << " <input.m3u> <output.m3u>\n";
        return 1;
    }

    std::ifstream in(inputFilename.c_str());
    if (in.good() == false)
    {
        cerr << "Couldn't open file " << inputFilename << " for reading.\n";
        return 1;
    }

    std::string header;
    std::getline(in, header);

    std::string buffer;
    std::multimap <int, std::string> items;

    std::getline(in, buffer);
    while (in.good())
    {
        items.insert(std::pair<int, std::string>(rand(), buffer));
        std::getline(in, buffer);
    }
    in.close();

    std::ofstream out(outputFilename.c_str());
    if (out.good() == false)
    {
        cerr << "Couldn't open file " << outputFilename << " for writing.\n";
        return 1;
    }

    out << header << '\n';
    for (const auto& it : items)
    {
        out << it.second << '\n';
    }
}
