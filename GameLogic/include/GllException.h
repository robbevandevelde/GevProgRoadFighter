/**
 * @file
 * this file contains a exception class used throughout the entire game logic library
 */
#include <exception>
#include <iostream>
#ifndef GEVPROGROADFIGHTER_GLLEXCEPTION_H
#define GEVPROGROADFIGHTER_GLLEXCEPTION_H
namespace roadfighter {
/**
 * This class is used for game logic exceptions
 */
    class GllException : public std::exception {
    private:
        std::string _msg;

    public:
        /**
         * Constructor for GllException taking its error message as argument
         */
        explicit GllException(std::string msg) { _msg = std::move(msg); }

        /**
         * Throw function
         * @return C-string with error message
         */
        const char *what() const noexcept override {
            return _msg.c_str();
        }
    };
}
#endif //GEVPROGROADFIGHTER_GLLEXCEPTION_H
