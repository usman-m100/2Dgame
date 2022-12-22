@echo off

setLocal enableDelayedExpansion

pushd ..\src
for /R %%f in (*.cpp) do (
    set sourceFiles=!sourceFiles! %%f
)
popd

pushd ..\

set vendorFiles=vendor/glad/src/*.cpp vendor/stb_image/src/*.cpp
set includeDirs=-Isrc -Ivendor/glfw/include -Ivendor/glad/include -Ivendor/glm/include -Ivendor/stb_image/include
set defaultLinkingLibraries=-lkernel32 -luser32 -lgdi32 -lwinspool -lcomdlg32 -ladvapi32 -lshell32 -lole32 -loleaut32 -luuid -lodbc32 -lopengl32
set linkerFlags=-Lvendor/glfw/lib -lglfw3_mt %defaultLinkingLibraries%
set compilerFlags=-Wvarargs -Wall -g -std=c++17 -o bin/2dgame.exe 
set predefinedMacros=-DGLFW_INCLUDE_NONE -D_CRT_SECURE_NO_WARNINGS 

echo Starting 2D Game build process...

clang++ %sourceFiles% %vendorFiles% %includeDirs% %linkerFlags% %compilerFlags% %predefinedMacros%

if %ERRORLEVEL% neq 0 (echo: Failed to build 2D Game. Erorr Code: %ERRORLEVEL% && exit)

popd