#pragma once
#ifndef GLFW_CLIENT_INCS_H
#define GLFW_CLIENT_INCS_H

//C++ Libraries
#include <string>
#include <iostream>

//GLFW
#include "../lib/GLFW/include/glfw3.h"

//GLM
//glm itself
#include "../lib/GLM/glm.hpp"
//vectors
#include "../lib/GLM/vector_relational.hpp"
#include "../lib/GLM/vec2.hpp"
#include "../lib/GLM/vec3.hpp"
#include "../lib/GLM/vec4.hpp"
//matrixes
#include "../lib/GLM/matrix.hpp"
#include "../lib/GLM/mat2x2.hpp"
#include "../lib/GLM/mat2x3.hpp"
#include "../lib/GLM/mat2x4.hpp"
#include "../lib/GLM/mat3x2.hpp"
#include "../lib/GLM/mat3x3.hpp"
#include "../lib/GLM/mat3x4.hpp"
#include "../lib/GLM/mat4x2.hpp"
#include "../lib/GLM/mat4x3.hpp"
#include "../lib/GLM/mat4x4.hpp"

//Core
#include "core/KeyListener.h"
#include "core/MouseListener.h"
#include "core/Scene.h"
#include "core/Camera.h"
#include "core/Shader.h"
#include "core/Window.h"

//Game
#include "game/MainMenuScene.h"
#include "game/GameLoadingScene.h"

#endif
