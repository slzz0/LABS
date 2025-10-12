#include "../include/invalidException.h"

#include "../include/transport.h"

InvalidException::InvalidException(const std::string& input, const std::string& requirement) {
    message = "Invalid input: '" + input + "'. " + requirement;
}

InvalidException::InvalidException(const std::string& customMessage) : message(customMessage) {}

const char* InvalidException::what() const noexcept { return message.c_str(); }