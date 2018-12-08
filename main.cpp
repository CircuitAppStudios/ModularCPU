#include <iostream>
#include <sstream>
#include <vector>

#define byteCode std::vector<unsigned char>

std::vector<unsigned char> parseCode(std::string code);

int main() {
    std::string testASM = "mov raa, 5\n"
                          "mov rab, 5";

    std::cout << testASM << std::endl;

    byteCode bCode = parseCode(testASM);
    //emualteBytecode(bCode, configuration);

    return 0;
}

std::vector<unsigned char> parseCode(std::string code){
    std::cout << "Parsing Code" << std::endl;


}