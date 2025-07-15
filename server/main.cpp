#include <enet/enet.h>
#include <iostream>
#include "..\shared\protocol\Packets.h"
#include "..\shared\protocol\Serialize.h"

int main() {
    if (enet_initialize() != 0) {
        std::cerr << "ENet initialization failed!" << std::endl;
        return EXIT_FAILURE;
    }

    ENetAddress address;
    address.host = ENET_HOST_ANY;
    address.port = 1234;

    ENetHost* server = enet_host_create(&address, 32, 2, 0, 0);

    if (!server) {
        std::cerr << "Failed to create server host." << std::endl;
        enet_deinitialize();
        return EXIT_FAILURE;
    }

    std::cout << "Aetherium server started on port 1234.\n";

        uint32_t clientId = 1;
        auto buffer = SerializeHello(clientId);

        // TODO: Send buffer over ENet to connected clients
 
    enet_host_destroy(server);
    enet_deinitialize();
    return EXIT_SUCCESS;
}
