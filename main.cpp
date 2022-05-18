#include <iostream>
#include <netdb.h>
#include "arpa/inet.h"
#include "smtp_server.h"

int main() {
    const char host_address [] {"smtp.gmail.com"};
    const char port [] {"587"};
    struct addrinfo hints {AI_PASSIVE, AF_UNSPEC, SOCK_STREAM};
    struct addrinfo * smtp_server_info;
    int status;
    if ((status = getaddrinfo(host_address, port, & hints, & smtp_server_info)) != 0) {
        std::cout << "DNS resolve failed : " << gai_strerror(status) << std::endl;
        return 1;
    }
    SmtpServer * connection_server {new SmtpServer {smtp_server_info}};
    try {
        connection_server->handshake();
        connection_server->tls_handshake();
        connection_server->login("r.fooladvand77@gmail.com", "");
        connection_server->mail_send("nitrozeusdev@gmail.com", "Test", "Mail Send.");
        connection_server->closed();
    } catch (SmtpError & e) {
        std::cout << e.what() << std::endl;
    }
    freeaddrinfo(smtp_server_info);
    delete connection_server;
    return 0;
}
