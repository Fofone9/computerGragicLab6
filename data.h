#pragma once
#include "Camera.h"
#include "GL/freeglut.h"
#include "graphicObject.h"
#include "Light.h"
#include "PhongMaterial.h"
#include <fstream>
#include <GL/gl.h>
#include <GL/glu.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include<iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <windows.h>
#include "Mesh.h"
#include "GameObject.h"
using namespace std;
using namespace glm;

extern vector<GraphicObject> graphicObjects;
extern vector<shared_ptr<PhongMaterial>> materials;

extern Camera camera;
extern LARGE_INTEGER ticks, ticksPerSecond;
extern Light light;
extern vector<shared_ptr<Mesh>> meshes;
extern int passabilityMap[21][21];
// карта проходимости

// список игровых объектов расположенных на карте
extern shared_ptr<GameObject> mapObjects[21][21];
// графический объект для плоскости (частный случай)
extern GraphicObject planeGraphicObject;
void initData();
