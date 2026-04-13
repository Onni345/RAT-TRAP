#include <GLFW/glfw3.h>
#include <iostream>
#include <vector>
#include "Camera.h"
#include "Scene.h"
#include "Sphere.h"
#include "Lambertian.h"
#include "Vector3.h"
#include <cfloat>

Vector3 color(const Ray& _r, const Scene& _s, int _d);
void random_scene();

// Global resolution (low for CPU real-time)
unsigned int width = 384; 
unsigned int height = 216;
int ray_num = 1; // 1 sample per pixel for movement

Scene tmp_scene;
Vector3 look_from(13, 2, 3);
Vector3 look_at(0, 0, 0);
float vfov = 30.0;
float aperture = 0.1;

// Global Camera instance
Camera tmp_camera(look_from, look_at, Vector3(0, 1, 0), vfov, float(width) / float(height), aperture, (look_from - look_at).length(), 0, 0);

unsigned char* pixel_buffer = new unsigned char[width * height * 3];

void process_input(GLFWwindow* window) {
    float speed = 0.1f;
    bool moved = false;
    if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) { look_from += Vector3(0, 0, -speed); moved = true; }
    if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) { look_from += Vector3(0, 0, speed); moved = true; }
    if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) { look_from += Vector3(-speed, 0, 0); moved = true; }
    if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) { look_from += Vector3(speed, 0, 0); moved = true; }

    if (moved) {
        // Update the existing camera with new coordinates
        tmp_camera = Camera(look_from, look_at, Vector3(0, 1, 0), vfov, float(width) / float(height), aperture, (look_from - look_at).length(), 0, 0);
    }
}

void update_buffer() {
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            Vector3 tmp_color(0,0,0);
            double u = float(j + ((double)rand() / (RAND_MAX))) / float(width);
            double v = float(i + ((double)rand() / (RAND_MAX))) / float(height);
            
            Ray tmp_ray = tmp_camera.gen_ray(u, v);
            tmp_color = color(tmp_ray, tmp_scene, 0); 

            int r = int(255.99 * sqrt(tmp_color.r()));
            int g = int(255.99 * sqrt(tmp_color.g()));
            int b = int(255.99 * sqrt(tmp_color.b()));

            // // OpenGL texture coordinate adjustment (bottom-to-top)
            // int index = ((height - 1 - i) * width + j) * 3;
            int index = (i * width + j) * 3;
            pixel_buffer[index]     = (unsigned char)std::min(255, r);
            pixel_buffer[index + 1] = (unsigned char)std::min(255, g);
            pixel_buffer[index + 2] = (unsigned char)std::min(255, b);
        }
    }
}

int main() {
    if (!glfwInit()) return -1;
    GLFWwindow* window = glfwCreateWindow(width, height, "RAT-TRAP! Real-Time Acoustic Debugger", NULL, NULL);
    glfwMakeContextCurrent(window);
    
    random_scene();

    GLuint texID;
    glGenTextures(1, &texID);
    glBindTexture(GL_TEXTURE_2D, texID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    while (!glfwWindowShouldClose(window)) {
        process_input(window);
        update_buffer();

        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, pixel_buffer);
        
        glClear(GL_COLOR_BUFFER_BIT);
        glEnable(GL_TEXTURE_2D);
        glBegin(GL_QUADS);
            glTexCoord2f(0, 0); glVertex2f(-1, -1);
            glTexCoord2f(1, 0); glVertex2f(1, -1);
            glTexCoord2f(1, 1); glVertex2f(1, 1);
            glTexCoord2f(0, 1); glVertex2f(-1, 1);
        glEnd();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }
    glfwTerminate();
    return 0;
}

Vector3 color(const Ray& _r, const Scene& _s, int _d) {
    HitInfo tmp_info;
    if (_s.hit(_r, 0.001, DBL_MAX, tmp_info)) {
        Ray scatter_ray;
        Vector3 attenuation_vec;
        if (_d < 20 && tmp_info.material_ptr->scatter(_r, tmp_info, attenuation_vec, scatter_ray)) {
            return attenuation_vec * color(scatter_ray, _s, _d + 1);
        } else {
            return Vector3(0, 0, 0);
        }
    } else {
        Vector3 unit_vec = _r.direction();
        double t = 0.5 * (unit_vec.y() + 1.0);
        return (1.0 - t) * Vector3(1, 1, 1) + t * Vector3(0.5, 0.7, 1.0);
    }
}

void random_scene() {
    tmp_scene.addObject(new Sphere(Vector3(0, -1000, 0), 1000, new Lambertian(Vector3(0.5, 0.5, 0.5))));
    tmp_scene.addObject(new Sphere(Vector3(5, 0.6, 0), 0.5, new Lambertian(Vector3(0.8, 0.3, 0.3))));
    // ... add any other spheres you want here ...
}