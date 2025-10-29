#ifndef EXCEPTIONS_H
#define EXCEPTIONS_H

#include <stdexcept>
#include <string>

class Exceptions : public std::runtime_error {
public:
    explicit Exceptions(const std::string& message)
        : std::runtime_error(message) {}
};

#endif
