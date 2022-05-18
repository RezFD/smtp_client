#include "exceptions/handshaking_error.h"

const char * HandshakingError::what() const noexcept {
    return "handshaking failed !";
}
