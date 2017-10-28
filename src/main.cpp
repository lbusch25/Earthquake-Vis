//
//  main.cpp
//  
//
//  Created by Bret Jackson on 1/29/17.
//
//

#include <stdio.h>

#include "App.h"
#include "Solar_System.hpp"

using namespace basicgraphics;

int main(int argc, char** argv)
{

	App *app = new App(argc, argv, "Earth Quake Visualization", 1024, 768);
	app->run();
	delete app;
    
//    Solar_System *solar = new Solar_System(argc, argv, "Earth Quake Visualization", 1024, 768);
//    solar->run();
//    delete solar;

	return 0;

}
