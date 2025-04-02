#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cstring>
#include <string>

/* Constants */
// Screen dimensions
constexpr int kScreenWidth {640};
constexpr int kScreenHeight {480};

/* Global Variables */
// Window will be rendering
SDL_Window* gWindow{nullptr};
// Surface contained by gWindow
SDL_Surface* gScreenSurface{nullptr};

// The image that will be loaded
SDL_Surface* gHelloWorld{nullptr};

/* Function Prototypes */
//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

int main( int argc, char* args[] )
{
    //Final exit code
    int exitCode{ 0 };

    //Initialize
    if( !init() )
    {
        SDL_Log( "Unable to initialize program!\n" );
        exitCode = 1;
    }
    else
    {
        //Load media
        if( !loadMedia() )
        {
            SDL_Log( "Unable to load media!\n" );
            exitCode = 2;
        }
        else
        {
            //The quit flag
            bool quit{ false };

            //The event data
            SDL_Event e;
            //SDL_zero( e );
            
            //The main loop
            while( quit == false )
            {
                //Get event data
                while( SDL_PollEvent( &e ) )
                {
                    //If event is quit type
                    if( e.type == SDL_EVENT_QUIT )
                    {
                        //End the main loop
                        quit = true;
                    }
                }

                //Fill the surface white
                SDL_FillSurfaceRect( gScreenSurface, nullptr, SDL_MapSurfaceRGB( gScreenSurface, 0xFF, 0xFF, 0xFF ) );
            
                //Render image on screen
                SDL_BlitSurface( gHelloWorld, nullptr, gScreenSurface, nullptr );

                //Update the surface
                SDL_UpdateWindowSurface( gWindow );
            } 
        }
    }

    //Clean up
    close();

    return exitCode;
}


bool init()
{
    // Init flag
    bool success{true};

    // Init SDL
    if (!SDL_Init(SDL_INIT_VIDEO)) {
        SDL_Log("SDL could not be initialize! SDL error: %s\n", SDL_GetError());
        success = false;
    } else {
        // Create window
        gWindow = SDL_CreateWindow("SDL3 Tutorial: Hello SDL3", kScreenWidth, kScreenHeight, SDL_WINDOW_METAL);
        if (gWindow == nullptr) {
            SDL_Log( "Window could not be created! SDL error: %s\n", SDL_GetError() );
            success = false;
        } else {
            //Get window surface
            gScreenSurface = SDL_GetWindowSurface( gWindow );
        }
    }
    return success;
}

bool loadMedia()
{
    //File loading flag
    bool success{ true };

    const char* base_path = SDL_GetBasePath();
    if (base_path) {
        SDL_Log("Base path: %s\n", base_path);
    } else {
        SDL_Log("SDL_GetBasePath failed: %s\n", SDL_GetError());
    }


    //Load splash image
    std::string imagePath = std::string(base_path) + "hello-sdl3.bmp";
    gHelloWorld = SDL_LoadBMP(imagePath.c_str());
    if(gHelloWorld == nullptr)
    {
        SDL_Log( "Unable to load image %s! SDL Error: %s\n", imagePath.c_str(), SDL_GetError() );
        success = false;
    }

    return success;
}

void close()
{
    //Clean up surface
    SDL_DestroySurface( gHelloWorld );
    gHelloWorld = nullptr;
    
    //Destroy window
    SDL_DestroyWindow( gWindow );
    gWindow = nullptr;
    gScreenSurface = nullptr;

    //Quit SDL subsystems
    SDL_Quit();
}