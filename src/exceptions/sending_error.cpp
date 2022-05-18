#include "exceptions/sending_error.h"

const char * SendingError::what() const noexcept {
    return "Failed to send packets to server !";
}