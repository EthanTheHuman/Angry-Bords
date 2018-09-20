#pragma once
#include "Scene.h"

// Dependencies
#include <iostream>
#include "ShaderLoader.h"
#include "Dependencies\glew\glew.h"
#include "Dependencies\freeglut\freeglut.h"
#include "Dependencies\soil\SOIL.h"
#include "Dependencies\glm\glm.hpp"
#include "Dependencies\glm\gtc\matrix_transform.hpp"
#include "Dependencies\glm\gtc\type_ptr.hpp"
#include <iterator>
#include <map>

#include "Camera.h"
#include "GameManager.h"
#include "Sound.h"
#include "Sprite.h"
#include "UISprite.h"
#include "Model.h"
#include "TextLabel.h"
#include "Utils.h"
#include "CubeMap.h"
#include "Player.h"
#include "UFO.h"
#include "dependencies\FMOD\fmod.hpp"
#include "dependencies\Box2D\Box2D.h"

enum Menus {
	MAIN,
	PLAY,
	CONTROL,
	COOP,
	HOST,
	JOIN,
	LOBBY
};

class MainMenu :
	public Scene
{
public:
	MainMenu();
	void Init();
	void Deconstruct();
	~MainMenu();
	void Render();
	void Update();
	void MoveCharacter(unsigned char KeyState[255]);
	void MenuUpdate();
	void ChangeNames(std::vector<std::string> _strings);
	void ChangeHostNames(std::vector<std::string> _strings);

	b2BodyDef groundBodyDef;
	b2Body* groundBody;
	b2PolygonShape groundBox;
	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape dynamicBox;
	b2FixtureDef fixtureDef;
	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;
	Sprite* Puar;

private:
	// List of objects
	Camera * MyCamera;
	std::vector<Sprite*> BGElements;
	CubeMap * MySkybox;
	ShaderLoader shaderloader;
	Player * _Player;

	// List of Shaders
	GLuint SpriteShader;
	GLuint UISpriteShader;
	GLuint ModelBasicShader;
	GLuint AmbientShader;
	GLuint TextShader;
	GLuint SkyboxShader;

	//menu stuff
	int selection = 0;
	Menus menu = MAIN;
	TextLabel * TempLabel;
};
