#include <iostream>
#include <sstream>
#include <vector>

#define byteCode std::vector<unsigned char>

std::vector<unsigned char> parseCode(std::string code);
bool processForInstruction(std::string token);
unsigned char getInstructionOpcode(std::string instruction);

int main() {
    std::string testASM = "mov raa, 5\n"
                          "mov rab, 5";

    byteCode bCode = parseCode(testASM);
    //emualteBytecode(bCode, configuration);

    return 0;
}

std::vector<unsigned char> parseCode(std::string code){
    std::cout << "Parsing Code\n" << std::endl;

    std::vector <std::string> lines;
    std::vector <std::string> tokens;
    std::vector <unsigned char> parsedCode;

    std::stringstream codeStream(code);
    std::string intermediate;

    while (std::getline(codeStream, intermediate, '\n')){
        lines.push_back(intermediate);
    }

    std::cout << "Printing Lines" << std::endl;
    std::cout << "--------------\n" << std::endl;

    for(int i = 0; lines.size() > i; i++){
        std::cout << "Line " << i + 1 << ". " << lines[i] << std::endl;
        std::stringstream lineStream(lines[i]);

        while(std::getline(lineStream, intermediate, ' ')){
            tokens.push_back(intermediate);
        }
    }

    std::cout << "\nPrinting Tokens" << std::endl;
    std::cout << "---------------\n" << std::endl;

    for(int i = 0; tokens.size() > i; i++){
        std::cout << tokens[i] << std::endl;
    }

    std::cout << "\nProcessing Tokens" << std::endl;
    std::cout << "-----------------\n" << std::endl;

    for(int i = 0; tokens.size() > i; i++){
        if(processForInstruction(tokens[i])){
            parsedCode.push_back(getInstructionOpcode(tokens[i]));
        }/*else if(processForLabel(tokens[i])){

        }*/

    }

    return parsedCode;
}

bool processForInstruction(std::string token){

    return true;
}

unsigned char getInstructionOpcode(std::string instruction){

    return 0x0;
}