Make sure to clone using --recursive as GLEW, GLFW and Assimp are submodules.

On Clion + Mac I seem to run into an issue where the first time it initialises the cmake project it uses Shared Libraries when it is set to use Static. Reloading the cmake project seems to fix it to use the static libs. 