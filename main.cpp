#include <enet/enet.h>
#include <iostream>
#include "shared/protocol/Packets.h"
#include "shared/protocol/Serialize.h"

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

    // Simple event loop
    ENetEvent event;
    while (true) {
        while (enet_host_service(server, &event, 1000) > 0) {
            switch (event.type) {
            case ENET_EVENT_TYPE_CONNECT: {
                std::cout << "Client connected from "
                    << event.peer->address.host << ":" << event.peer->address.port << "\n";

                uint32_t clientId = 1; // TODO: Assign properly
                auto buffer = SerializeHello(clientId);

                ENetPacket* packet = enet_packet_create(buffer.data(), buffer.size(), ENET_PACKET_FLAG_RELIABLE);
                enet_peer_send(event.peer, 0, packet);
                break;
            }
            case ENET_EVENT_TYPE_RECEIVE: {
                std::cout << "Received data from client.\n";
                enet_packet_destroy(event.packet);
                break;
            }
            case ENET_EVENT_TYPE_DISCONNECT: {
                std::cout << "Client disconnected.\n";
                break;
            }
            default: break;
            }
        }
    }

    enet_host_destroy(server);
    enet_deinitialize();
    return EXIT_SUCCESS;
}
