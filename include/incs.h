#pragma once
#ifndef GLFW_CLIENT_INCS_H
#define GLFW_CLIENT_INCS_H

//C++ Libraries
#include <string>
#include <iostream>

//GLFW
#include "../GLFW/include/glfw3.h"

//GLM
//glm itself
#include "../GLM/glm.hpp"
//vectors
#include "../GLM/vector_relational.hpp"
#include "../GLM/vec2.hpp"
#include "../GLM/vec3.hpp"
#include "../GLM/vec4.hpp"
//matrixes
#include "../GLM/matrix.hpp"
#include "../GLM/mat2x2.hpp"
#include "../GLM/mat2x3.hpp"
#include "../GLM/mat2x4.hpp"
#include "../GLM/mat3x2.hpp"
#include "../GLM/mat3x3.hpp"
#include "../GLM/mat3x4.hpp"
#include "../GLM/mat4x2.hpp"
#include "../GLM/mat4x3.hpp"
#include "../GLM/mat4x4.hpp"

//Core
#include "core/KeyListener.h"
#include "core/MouseListener.h"
#include "core/Scene.h"
#include "core/Camera.h"
#include "core/Window.h"

//Game
#include "game/TestScene.h"

#endif
