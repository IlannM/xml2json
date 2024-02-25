// Ilan Mittelman
// forked from https://github.com/Cheedoong/xml2json

#include <xml2json.hpp>
#include <fmt/format.h>
#include <iostream>
#include <sstream>
#include <fstream>
#include <cstring>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cout << "Please supply a XML file path.\n";
        return 1;
    } else if (argc > 3) {
        std::cout << "Too many args.\n";
        return 1;
    }
    std::ifstream input(argv[1]);
    input.seekg(0, std::ios::end);
    const auto &size = input.tellg();
    input.seekg (0, std::ios::beg);
    char * memblock = new char [size];
    input.read(memblock, size);
    input.close();
    const std::string &json_str = xml2json(memblock, argc == 3 ? (std::atoi(argv[2])) : 0);
    const auto& len = strlen(argv[1]);
    argv[1][len-3] = 0;
    std::ofstream file(fmt::format("{}json", argv[1]));
    file << json_str;
    file.close();
    return 0;
}
