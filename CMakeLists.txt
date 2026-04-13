cmake_minimum_required(VERSION 3.10)
project(ray_tracing_starter)

set(CMAKE_CXX_STANDARD 14)
add_executable(ray_tracing_starter  main.cpp Object.h Scene.h Scene.cpp Ray.h Sphere.h Sphere.cpp Vector3.cpp Vector3.h Camera.cpp Camera.h Material.h HitInfo.h Lambertian.cpp Lambertian.h Metal.cpp Metal.h Material.cpp Dielectric.cpp Dielectric.h Movement.cpp Movement.h)
SET(CMAKE_CXX_FLAGS -pthread)
