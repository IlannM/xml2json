// Ilan Mittelman
// forked from https://github.com/Cheedoong/xml2json

#include <xml2json.hpp>
#include <iostream>
#include <sstream>
#include <fstream>

void convert(const std::istream &input) {
    std::ostringstream oss;
    oss << input.rdbuf();
    const auto &json_str = xml2json(oss.str().data());
    std::cout << json_str << std::endl;
}

int main(int argc, char *argv[]) {
    switch (argc) {
    case 1:
        convert(std::cin);
        break;
    case 2:
        convert(std::ifstream(argv[1]));
        break;
    }
    return 0;
}
