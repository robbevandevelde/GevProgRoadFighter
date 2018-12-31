//
// Created by thibaut on 31.12.18.
//
#include <exception>
#include <iostream>
#ifndef GEVPROGROADFIGHTER_SFMLCONVERSIONEXCEPTION_H
#define GEVPROGROADFIGHTER_SFMLCONVERSIONEXCEPTION_H
namespace roadfighterSFML {
/**
 * This class is used for game logic exceptions
 */
    class SFMLConversionException : public std::exception {
    private:
        std::string _msg;

    public:
        /**
         * Constructor for SFMLConversionException taking its error message as argument
         */
        explicit SFMLConversionException(std::string msg) { _msg = std::move(msg); }

        /**
         * Throw function
         * @return C-string with error message
         */
        const char *what() const noexcept override {
            return _msg.c_str();
        }
    };
}

#endif //GEVPROGROADFIGHTER_SFMLCONVERSIONEXCEPTION_H
