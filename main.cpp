#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "Timer.h"
#include "Logger.h"

#define byteCode std::vector<unsigned char>

std::vector<unsigned char> parseCode(std::string code);
bool processForInstruction(std::string token);
unsigned char getInstructionOpcode(std::string instruction);

Logger logger;

bool allDebug = false;

void checkForFlags(const char* value);

void checkForFlags(const char* value){
    if(strncmp(value, "-wall", 10) == 0){
        logger.setDebug();
    }
}

// TODO: Fix timer for Windows as High_Resolution_Clock is accurate to about a millisecond on Windows
int main(int argc, char* argv[]) {
    //std::string testASM = "mov raa, 5\n"
    //                      "mov rab, 5";

    std::string Code;

    for(int i = 2; i < argc; i++){
        checkForFlags(argv[i]);
    }

    if(argc <= 1){
        std::cout << "Usage: ./ModularCPU <aasm code> <flags>";
    }else{
        logger.print(std::string("Processing File at: ") + argv[1] + "\n");

        std::filebuf codeBuffer;
        if(codeBuffer.open(argv[1], std::ios::in)){
            std::istream codeStream(&codeBuffer);
            std::string temp(std::istreambuf_iterator<char>(codeStream), {});
            Code = temp;
            codeBuffer.close();
        }

        if(Code.empty()){
            std::cout << "Error, file is blank" << std::endl;
        }
    }

    //byteCode bCode = parseCode(testASM);
    byteCode bCode = parseCode(Code);
    //emualteBytecode(bCode, configuration);

    return 0;
}

std::vector<unsigned char> parseCode(std::string code){
    logger.print(std::string("Parsing Code") + "\n" + "------------");

    std::vector <std::string> lines;
    std::vector <std::string> tokens;
    std::vector <unsigned char> parsedCode;

    std::stringstream codeStream(code);
    std::string intermediate;

    logger.startTimer();

    while (std::getline(codeStream, intermediate, '\n')){
        lines.push_back(intermediate);
    }

    logger.endTimer();
    logger.print("Processing Code / Lines took " + logger.elapsedNanoseconds() + " ns");
    logger.print("File has " + std::to_string(lines.size()) + " lines\n");

    logger.print("Printing Lines");
    logger.print("--------------");

    logger.startTimer();

    for(int i = 0; lines.size() > i; i++){
        logger.print("Line " + std::to_string(i + 1) + ". " + lines[i]);

        std::stringstream lineStream(lines[i]);

        while(std::getline(lineStream, intermediate, ' ')){
            tokens.push_back(intermediate);
        }
    }

    Timer timer;

    logger.endTimer();
    logger.print("Separating Tokens took " + logger.elapsedNanoseconds() + " ns\n");

    logger.print("\nPrinting Tokens");
    logger.print("---------------");

    for (int i = 0; tokens.size() > i; i++) {
        logger.print(tokens[i]);
    }

    logger.print("\nCleaning Tokens");
    logger.print("---------------");

    logger.startTimer();

    for(int i = 0; tokens.size() > i; i++){
        std::stringstream tokenStream(tokens[i]);

        while(std::getline(tokenStream, intermediate, ',')){
            tokens[i] = intermediate;
        }
    }

    logger.endTimer();
    logger.print("Cleaning Tokens took " + logger.elapsedNanoseconds() + " ns");

    logger.print("\nProcessing Tokens");
    logger.print("-----------------");

    logger.startTimer();

    for(int i = 0; tokens.size() > i; i++){
        if(processForInstruction(tokens[i])){
            parsedCode.push_back(getInstructionOpcode(tokens[i]));
        }/*else if(processForLabel(tokens[i])){
        }*/

    }

    logger.endTimer();
    logger.print("Processing Tokens took " + logger.elapsedNanoseconds() + " ns");

    return parsedCode;
}

bool processForInstruction(std::string token){

    return true;
}

unsigned char getInstructionOpcode(std::string instruction){

    return 0x0;
}