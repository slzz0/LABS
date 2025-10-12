#pragma once
#include <exception>
#include <string>


class InvalidException : public std::exception {
   private:
    std::string message;

   public:
    InvalidException(const std::string& input, const std::string& requirement);
    explicit InvalidException(const std::string& customMessage);
    const char* what() const noexcept override;
};