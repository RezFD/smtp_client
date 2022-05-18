
#include "exceptions/ssl_error.h"

const char * SslError::what() const noexcept {
    return "SSL Handshake Failed !?";
}
