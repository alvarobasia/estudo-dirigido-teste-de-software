//
// Created by alvaro on 2/4/21.
//

#ifndef UNTITLED_TRIANGULOINVALIDOEXCEPTION_H
#define UNTITLED_TRIANGULOINVALIDOEXCEPTION_H

#include <exception>
#include <string>
#include <utility>

class TrianguloInvalidoException: std::exception {
public:
    explicit TrianguloInvalidoException(std::string  msg) : msg_(std::move(msg)) {}
    ~TrianguloInvalidoException() override = default;

    std::string getMessage() const {return(msg_);}

    private:
     std::string msg_;
    };



#endif //UNTITLED_TRIANGULOINVALIDOEXCEPTION_H
