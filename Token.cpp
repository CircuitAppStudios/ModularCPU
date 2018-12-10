#include <utility>

//
// Created by Daniel Luna on 2018-12-10.
//

#include "Token.h"

Token::Token(std::string info, TokenType tokenType) {
    m_Content = std::move(info);
    m_TokenType = tokenType;
}

unsigned char Token::returnProcessedToken() {

    unsigned char returnValue = 0;

    switch (m_TokenType){
        case TokenType::Null:
            returnValue = 0;
            break;
        case TokenType::LABEL:
            break;
        case TokenType::ARITHMETIC:
            break;
        case TokenType::LOGIC:
            break;
    }


    return returnValue;
}
