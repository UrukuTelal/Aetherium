#include <SDL.h>
#include <iostream>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }
    
    SDL_Window* window = SDL_CreateWindow(
        "Aetherium Client",
        SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        1280, 720,
        SDL_WINDOW_SHOWN
    );

    if (!window) {
        std::cerr << "Window creation failed: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // After SDL window creation
    float angle = 0.0f;
    float dt = 0.016f;

    while (running) {
        angle += dt;
        glm::vec3 pos1 = OrbitPosition(5.0f, angle, glm::vec3(0));
        glm::vec3 pos2 = OrbitPosition(2.0f, angle * 2, pos1);

        // For now just print positions
        std::cout << "P1: " << pos1.x << "," << pos1.z << " | P2: " << pos2.x << "," << pos2.z << std::endl;

        SDL_Delay(16);
    }


    SDL_Delay(3000); // show window for 3 sec
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
