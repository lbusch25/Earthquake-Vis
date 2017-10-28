//
//  Planet.hpp
//  EarthQuakeStudent
//
//  Created by Lawson Busch on 3/13/17.
//
//

#ifndef Planet_hpp
#define Planet_hpp

#include <stdio.h>
#include "GLSLProgram.h"
#include "config.h"
#include "Texture.h"
#include "Mesh.h"
#define GLM_FORCE_RADIANS
#include <glm/glm/glm.hpp>
#include <glm/glm/gtc/constants.hpp>

namespace basicgraphics {
    class Planet {
    //Memeber Functions
    public:
        Planet(float r, std::string TEXT_PATH);
        ~Planet(){};
        
        glm::vec3 getPosition(double stack, double slice);
        
        void setUpGeometry();
        
        void draw(GLSLProgram &shader);
        
    //Member Variables
    protected:
        std::vector<std::shared_ptr<Texture>> textures;
        std::shared_ptr<Mesh> mesh;
        float radius;
    };
}

#endif /* Planet_hpp */
