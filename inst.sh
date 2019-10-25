echo "Install brew"
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh;
source ~/.zshrc;
echo "Start install SDL2."
brew install sdl2;
echo "Start configure SDL2."
pkg-config --libs --cflags ./sdl2lib/pkgconfig/sdl2.pc                 
#-D_THREAD_SAFE -I/Users/drafe/.brew/include/SDL2 -L/Users/drafe/.brew/lib -lSDL2
echo "SDL2 config done."

#pkg-config --libs --cflags /usr/local/Cellar/vulkan-headers/1.1.125;
#
#pkg-config --libs --cflags ~/.brew/Cellar/glfw/3.3/lib/pkgconfig/glfw3.pc
#add to make:-I/Users/drafe/.brew/Cellar/glfw/3.3/include -L/Users/drafe/.brew/Cellar/glfw/3.3/lib -lglfw
#pkg-config --libs --cflags ~/.brew/Cellar/cglm/0.6.0/lib/pkgconfig/cglm.pc
#add to make:-I/Users/drafe/.brew/Cellar/cglm/0.6.0/include -L/Users/drafe/.brew/Cellar/cglm/0.6.0/lib -lcglm -lm

#pkg-config --libs --cflags ./sdl2lib/pkgconfig/sdl2.pc                 
#-D_THREAD_SAFE -I/Users/drafe/.brew/include/SDL2 -L/Users/drafe/.brew/lib -lSDL2
#cd SDL2;./configure; make; make install;cd ..;
#echo $PKG_CONFIG_PATH
#set
#${workspaceFolder}/**
#/Users/drafe/.brew/Cellar/glfw/3.3/include/GLFW/**
#/Users/drafe/.brew/Cellar/glfw/3.3/include/GLFW
#/Users/drafe/.brew/Cellar/glfw/3.3/include
#/Users/drafe/.brew/Cellar/cglm/0.6.0/include/**
#/Users/drafe/.brew/Cellar/cglm/0.6.0/include
#/Users/drafe/.brew/Cellar/vulkan-headers/1.1.125/include/**
#/Users/drafe/.brew/Cellar/vulkan-headers/1.1.125/include