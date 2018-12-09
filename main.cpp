#include <iostream>
#include <sstream>
#include <vector>
#include <chrono>

class Timer{
public:
    void Start(){
        m_StartTime = std::chrono::high_resolution_clock::now();
        m_isRunning = true;
    }

    void Stop(){
        m_EndTime = std::chrono::high_resolution_clock::now();
        m_isRunning = true;
    }

    double elapsedNanoseconds(){
        std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

        if(m_isRunning)
        {
            endTime = std::chrono::high_resolution_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - m_StartTime).count();
    }

    double elapsedMilliseconds(){
        std::chrono::time_point<std::chrono::high_resolution_clock> endTime;

        if(m_isRunning)
        {
            endTime = std::chrono::high_resolution_clock::now();
        }
        else
        {
            endTime = m_EndTime;
        }

        return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
    }

    double elapsedSeconds()
    {
        return elapsedMilliseconds() / 1000.0;
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> m_StartTime;
    std::chrono::time_point<std::chrono::high_resolution_clock> m_EndTime;
    bool m_isRunning = false;
};

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