#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Timer.h"

#define byteCode std::vector<unsigned char>

std::vector<unsigned char> parseCode(std::string code);
bool processForInstruction(std::string token);
unsigned char getInstructionOpcode(std::string instruction);

int main(int argc, char* argv[]) {
    //std::string testASM = "mov raa, 5\n"
    //                      "mov rab, 5";

    std::string Code;

    if(argc <= 1){
        std::cout << "Usage: ./ModularCPU <aasm code>";
    }else{
        std::filebuf codeBuffer;
        if(codeBuffer.open(argv[1], std::ios::in)){
            std::istream codeStream(&codeBuffer);
            std::string temp(std::istreambuf_iterator<char>(codeStream), {});
            Code = temp;
            codeBuffer.close();
        }
    }

    //byteCode bCode = parseCode(testASM);
    byteCode bCode = parseCode(Code);
    //emualteBytecode(bCode, configuration);

    return 0;
}

std::vector<unsigned char> parseCode(std::string code){
    std::cout << "Parsing Code" << std::endl;
    std::cout << "------------" << std::endl;

    std::vector <std::string> lines;
    std::vector <std::string> tokens;
    std::vector <unsigned char> parsedCode;

    std::stringstream codeStream(code);
    std::string intermediate;

    Timer timer;
    timer.Start();

    while (std::getline(codeStream, intermediate, '\n')){
        lines.push_back(intermediate);
    }

    timer.Stop();
    std::cout << "Processing Lines took " << timer.elapsedNanoseconds() << " ns" << "\n" << std::endl;

    std::cout << "Printing Lines" << std::endl;
    std::cout << "--------------\n" << std::endl;

    timer.Start();
    for(int i = 0; lines.size() > i; i++){
        std::cout << "Line " << i + 1 << ". " << lines[i] << std::endl;
        std::stringstream lineStream(lines[i]);

        while(std::getline(lineStream, intermediate, ' ')){
            tokens.push_back(intermediate);
        }
    }

    timer.Stop();
    std::cout << "Separating Tokens took " << timer.elapsedNanoseconds() << " ns" << std::endl;

    std::cout << "\nPrinting Tokens" << std::endl;
    std::cout << "---------------\n" << std::endl;

    for(int i = 0; tokens.size() > i; i++){
        std::cout << tokens[i] << std::endl;
    }

    std::cout << "\nProcessing Tokens" << std::endl;
    std::cout << "-----------------\n" << std::endl;

    timer.Start();

    for(int i = 0; tokens.size() > i; i++){
        if(processForInstruction(tokens[i])){
            parsedCode.push_back(getInstructionOpcode(tokens[i]));
        }/*else if(processForLabel(tokens[i])){

        }*/

    }

    timer.Stop();
    std::cout << "Processing Tokens took " << timer.elapsedNanoseconds() << " ns" << std::endl;

    return parsedCode;
}

bool processForInstruction(std::string token){

    return true;
}

unsigned char getInstructionOpcode(std::string instruction){

    return 0x0;
}