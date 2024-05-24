#include "PlatformWindows.h"
#include <iostream>

PlatformWindows::PlatformWindows() : window(nullptr), renderer(nullptr), texture(nullptr) {}

PlatformWindows::~PlatformWindows() {}

int PlatformWindows::Init() {
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return 1;
    }

    window = SDL_CreateWindow("Infinity Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE);
    if (!window) {
        std::cerr << "Erro ao criar janela: " << SDL_GetError() << std::endl;
        return 1;
    }

    // Carregar a imagem do ícone
    SDL_Surface* iconSurface = IMG_Load("C://Users//RudeB//Documents//Infinity Engine//resources//images//InfinityEngine.png");
    if (!iconSurface) {
        SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "Unable to load icon image! SDL_Error: %s\n", SDL_GetError());
        return -1;
    }

    // Definir o ícone da janela
    SDL_SetWindowIcon(window, iconSurface);

    // Liberar a superfície do ícone, pois ela não é mais necessária após definir o ícone
    SDL_FreeSurface(iconSurface);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        std::cerr << "Erro ao criar renderizador: " << SDL_GetError() << std::endl;
        SDL_DestroyWindow(window);
        return 1;
    }

    int flags = (IMG_INIT_PNG | IMG_INIT_JPG);
    if (IMG_Init(flags) != flags) {
        std::cerr << "Falha ao inicializar SDL_image: " << IMG_GetError() << std::endl;
        return 1;
    }

    LoadAssets();
    return 0;
}

void PlatformWindows::HandleEvents(bool &game_running) {
    SDL_Event e;
    while (SDL_PollEvent(&e) != 0) {
        if (e.type == SDL_QUIT) {
            game_running = false;
        } else if (e.type == SDL_KEYDOWN) {
            if (e.key.keysym.sym == SDLK_ESCAPE) {
                game_running = false;
            }
        }
    }
}

void PlatformWindows::Render() {
    SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 255);
    SDL_RenderClear(renderer);

    // Renderizar sua textura carregada
    
    SDL_Rect dstRect = {0, 0, 640, 480}; // Posição e dimensões da textura na janela
    SDL_RenderCopy(renderer, texture, nullptr, &dstRect);

    SDL_RenderPresent(renderer);
}

void PlatformWindows::LoadAssets() {
    // Carregar imagens aqui
    SDL_Surface* surface = IMG_Load("C://Users//RudeB//Documents//Infinity Engine//resources//images//RemainOnEarth.gif");
    if (!surface) {
        std::cerr << "Falha ao carregar imagem: " << IMG_GetError() << std::endl;
        return;
    }

    SDL_Texture* tex = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Armazenar a textura carregada
    texture = tex;
}

bool PlatformWindows::IsSupportedImageFile(const std::string& filename) {
    std::string extension = filename.substr(filename.find_last_of(".") + 1);
    return (extension == "bmp" || extension == "gif" || extension == "jpg" || extension == "jpeg" || extension == "png");
}

void PlatformWindows::PlaySound(const std::string& sound_file) {
    // Carregar arquivo de áudio como Uint8
    SDL_AudioSpec spec;
    Uint8 *audio_buf;
    Uint32 audio_len;

    if (SDL_LoadWAV(sound_file.c_str(), &spec, &audio_buf, &audio_len) == nullptr) {
        std::cerr << "Falha ao carregar arquivo de áudio: " << SDL_GetError() << std::endl;
        return;
    }

    // Abrir dispositivo de áudio
    audio_device = SDL_OpenAudioDevice(nullptr, 0, &spec, nullptr, 0);
    if (audio_device == 0) {
        std::cerr << "Falha ao abrir dispositivo de áudio: " << SDL_GetError() << std::endl;
        SDL_FreeWAV(audio_buf);
        return;
    }

    // Enfileirar áudio para reprodução
    SDL_QueueAudio(audio_device, audio_buf, audio_len);

    // Iniciar reprodução de áudio
    SDL_PauseAudioDevice(audio_device, 0);

    // Liberação de memória
    SDL_FreeWAV(audio_buf);
}


void PlatformWindows::PauseSound() {
    SDL_PauseAudioDevice(audio_device, 1);
}

void PlatformWindows::StopSound() {
    SDL_ClearQueuedAudio(audio_device);
    SDL_CloseAudioDevice(audio_device);
}

//void PlatformWindows::HandleEvents(bool& game_running){}

void PlatformWindows::Shutdown()
{
    if (audio_device != 0) {
        SDL_CloseAudioDevice(audio_device);
    }
}

void PlatformWindows::Initialize(){}

SDL_Window *PlatformWindows::getWindow() const {
    return window;
}

SDL_Renderer *PlatformWindows::getRenderer() const {
    return renderer;
}

void PlatformWindows::setWindow(SDL_Window *window) {
    if (this->window) {
        SDL_DestroyWindow(this->window);
    }
    this->window = window;
}

void PlatformWindows::setRenderer(SDL_Renderer *renderer) {
    if (this->renderer) {
        SDL_DestroyRenderer(this->renderer);
    }
    this->renderer = renderer;
}
