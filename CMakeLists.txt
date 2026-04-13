list(APPEND CMAKE_PREFIX_PATH "/opt/homebrew")

cmake_minimum_required(VERSION 3.10)
project(ray_tracing_starter)

set(CMAKE_CXX_STANDARD 14)

# 1. Find Packages
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# 2. Define Executable
add_executable(ray_tracing_starter 
    main.cpp 
    Scene.cpp 
    Sphere.cpp 
    Vector3.cpp 
    Camera.cpp 
    Lambertian.cpp 
    Metal.cpp 
    Material.cpp 
    Dielectric.cpp 
    Movement.cpp
)

# 3. Linking
# Use the namespaced targets which handle headers/paths automatically
target_link_libraries(ray_tracing_starter PRIVATE OpenGL::GL glfw)
target_compile_options(ray_tracing_starter PRIVATE -pthread)

add_definitions(-DGL_SILENCE_DEPRECATION)