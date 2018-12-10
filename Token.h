//
// Created by Daniel Luna on 2018-12-10.
//

#ifndef MODULARCPU_TOKEN_H
#define MODULARCPU_TOKEN_H

#include <string>

enum TokenType{
    Null,
    LABEL,
    ARITHMETIC,
    LOGIC
};

class Token {
public:
    Token(std::string info, TokenType tokenType);
    unsigned char returnProcessedToken();

private:
    std::string m_Content;
    TokenType m_TokenType;
};


#endif //MODULARCPU_TOKEN_H
