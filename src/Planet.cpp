//
//  Jupiter.cpp
//  EarthQuakeStudent
//
//  Created by Lawson Busch on 3/13/17.
//
//

#include "Planet.hpp"

namespace basicgraphics {
    using namespace std;
    using namespace glm;
    
    Planet::Planet(float r, string TEXT_PATH) {
        shared_ptr<Texture> tex = Texture::create2DTextureFromFile(TEXT_PATH);
        tex->setTexParameteri(GL_TEXTURE_WRAP_S, GL_REPEAT);
        tex->setTexParameteri(GL_TEXTURE_WRAP_T, GL_REPEAT);
        tex->setTexParameteri(GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        tex->setTexParameteri(GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        radius = r;
        textures.push_back(tex);
        setUpGeometry();
    }
    
    void Planet::setUpGeometry() {
        // TODO: Write your own code here to tesselate and create texture coordinates for the Earth
        // and then save the data to a mesh (i.e. VBO). The tesselation
        // should be based on the STACKS and SLICES parameters.
        const int STACKS = 80;
        const int SLICES = 80;
        
        std::vector<Mesh::Vertex> cpuVertexArray;
        std::vector<int> cpuIndexArray;
        
        ////Top layer
        //Mesh::Vertex vTop;
        //vTop.position = vec3(0, 1, 0);
        //vTop.normal = vec3(0, 1, 0);
        //vTop.texCoord0 = vec2(0.5, 0);
        //cpuVertexArray.push_back(vTop);
        int thisVertexIndex = -1;
        
        for (int stack = 0; stack < STACKS; stack++) {
            
            int stackStartIndex = thisVertexIndex + 1;
            for (int slice = 0; slice < SLICES + 1; slice++) {
                
                vec3 pt;
                if (stack == 0) {
                    pt = vec3(0, 1, 0);
                }
                else if (stack == STACKS - 1) {
                    pt = vec3(0, -1, 0);
                }
                else {
                    //Calc lat/long and get point
                    double lat = -((stack / (double)STACKS) - .5) * pi<double>();
                    double longitude = ((slice / (double)SLICES) - .5) * two_pi<double>();
                    pt = getPosition(lat, longitude);
                }
                
                Mesh::Vertex vertex;
                vertex.position = pt;
                vertex.normal = normalize(pt);
                vertex.texCoord0 = vec2((slice / (double)SLICES), stack / (double)STACKS);
                cpuVertexArray.push_back(vertex);
                thisVertexIndex++;
                
                if(stack > 0) {
                    int indexVertexAbove = thisVertexIndex - (SLICES + 1);
                    int indexNextVertexOnSameLayer = stackStartIndex + ((thisVertexIndex - stackStartIndex + 1) % (SLICES + 1));
                    int indexNextVertexOnLayerAbove = indexNextVertexOnSameLayer - (SLICES + 1);
                    
                    cpuIndexArray.push_back(indexVertexAbove);
                    cpuIndexArray.push_back(thisVertexIndex);
                    cpuIndexArray.push_back(indexNextVertexOnSameLayer);
                    
                    cpuIndexArray.push_back(indexVertexAbove);
                    cpuIndexArray.push_back(indexNextVertexOnSameLayer);
                    cpuIndexArray.push_back(indexNextVertexOnLayerAbove);
                }
            }
        }
        
        const int cpuVertexByteSize = sizeof(Mesh::Vertex) * cpuVertexArray.size();
        const int cpuIndexByteSize = sizeof(int) * cpuIndexArray.size();
        
        mesh.reset(new Mesh(textures, GL_TRIANGLES, GL_STATIC_DRAW, cpuVertexByteSize,
                            cpuIndexByteSize, 0, cpuVertexArray, cpuIndexArray.size(), cpuIndexByteSize, &(cpuIndexArray[0])));
    }
    
    glm::vec3 Planet::getPosition(double stack, double slice) {
        return vec3(
                    cos(stack)*cos(slice) * radius,
                    sin(stack)* radius,
                    -cos(stack)*sin(slice) * radius);
    }
    
    void Planet::draw(GLSLProgram &shader) {
        mesh->draw(shader);
    }
}
