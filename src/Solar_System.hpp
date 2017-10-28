//
//  Solar_System.hpp
//  EarthQuakeStudent
//
//  Created by Lawson Busch on 3/22/17.
//
//

#ifndef Solar_System_hpp
#define Solar_System_hpp

#include "BaseApp.h"
#include "EarthquakeDatabase.h"
#include "Earth.h"
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include <string.h>
#include <glm/glm/gtc/matrix_transform.hpp>
#include "Planet.hpp"


namespace basicgraphics {
    class Solar_System : public BaseApp {
    public:
        
        Solar_System(int argc, char** argv, std::string windowName, int windowWidth, int windowHeight);
        ~Solar_System();
        
        
        void onSimulation(double rdt);
        void onRenderGraphics() override;
        void onEvent(std::shared_ptr<Event> event) override;
        
        
    protected:
        
        void initializeText(); // Initialized the font rendering library
        void drawText(); // Draws the current time on the screen.
        struct FONScontext* fs;
        GLSLProgram _textShader;
        
        double lastTime;
        glm::vec3 eye_world;
        bool mouseDown; // Signifies whether the left mouse button is currently held down.
        glm::vec2 lastMousePos;
        
        double currentTime;
        bool playing;
        double playbackScale;
        
        // Database through which you can access the earthquakes
        EarthquakeDatabase eqd;
        
        // Object representing the earth
        std::shared_ptr<Earth> earth;
        std::unique_ptr<Sphere> earthquakeVisualRed;
        std::unique_ptr<Sphere> earthquakeVisualOrange;
        std::unique_ptr<Sphere> earthquakeVisualYellow;
        std::unique_ptr<Planet> sun;
        
        // Rotation matrix for the earth and displayed earthquakes
        glm::mat4 rotation;
        
    };
}

#endif /* Solar_System_hpp */
