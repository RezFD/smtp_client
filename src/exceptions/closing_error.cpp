#include "exceptions/closing_error.h"

const char * ClosingError::what() const noexcept {
    return "Closing client connection failed !";
}