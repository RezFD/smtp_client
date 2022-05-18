#include "exceptions/connection_error.h"

const char * ConnectionError::what() const noexcept {
    return "Failed to connect to the server !";
}
