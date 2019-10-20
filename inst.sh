echo "Install brew"
curl -fsSL https://rawgit.com/kube/42homebrew/master/install.sh | zsh;
source ~/.zshrc;
echo "Install vulkan-headers"
brew install vulkan-headers;
echo "Install glfw"
brew install glfw;
echo "Install glm"
brew install glm;
echo "Now config libraries from brew"
pkg-config --libs --cflags /usr/local/Cellar/vulkan-headers/1.1.125;
#
pkg-config --libs --cflags ~/.brew/Cellar/glfw/3.3/lib/pkgconfig/glfw3.pc
#add to make:-I/Users/drafe/.brew/Cellar/glfw/3.3/include -L/Users/drafe/.brew/Cellar/glfw/3.3/lib -lglfw
pkg-config --libs --cflags ~/.brew/Cellar/cglm/0.6.0/lib/pkgconfig/cglm.pc
#add to make:-I/Users/drafe/.brew/Cellar/cglm/0.6.0/include -L/Users/drafe/.brew/Cellar/cglm/0.6.0/lib -lcglm -lm

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