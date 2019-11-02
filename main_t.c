#include <SDL2/SDL.h>
#include "libft.h"
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 800;

//Screen dimension constants

int main( int argc, char* args[] )
{
//The window we'll be rendering to
SDL_Window* window = NULL;
//The surface contained by the window
SDL_Surface* screenSurface = NULL;
SDL_Surface* texturSurface = NULL;

SDL_Event e;
*

//Initialize SDL
if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
{
printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
}
else
{
//Create window
window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
if( window == NULL )
{
printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
}
else
{
//Get window surface
screenSurface = SDL_GetWindowSurface(window );
texturSurface = SDL_LoadBMP("wolf3d/textures/wolfwall/WALL0.bmp")
if (texturSurface == NULL)
{
 ft_putstr("Error with surface_texture")
}

//Fill the surface white
//SDL_FillRect( screenSurface, NULL, SDL_MapRGB( screenSurface->format, 0xFF, 0xFF, 0xFF ) );

//Update the surface
//SDL_UpdateWindowSurface( window );

//Wait two seconds
//SDL_Delay( 5000 );
}
}

while(1)
if (SDL_PollEvent(&e)){if (e.type == SDL_QUIT){break;}}

SDL_DestroyWindow( window );

//Quit SDL subsystems
SDL_Quit();

return 0;
}

