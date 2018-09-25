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
#include "dependencies\Box2D\Rope\b2Rope.h"
#include "PhysicsBox.h"
#include <vector>

enum Menus {
	MAIN,
	PLAY,
	CONTROL,
	COOP,
	HOST,
	JOIN,
	LOBBY
};

struct GameObject
{
	PhysicsBox Box;
	Sprite Sprite;

	void ChangePos(glm::vec2 Pos , float Angle) {
		float tempA;
		if (Angle == NULL) {
			tempA = Box.body->GetAngle();
		}
		else {
			tempA = Angle;
		}
		Box.body->SetTransform({ Pos.x, Pos.y }, tempA);
		Sprite.SetTranslation({ Pos.x * 20, Pos.y * 20, 0 });
	}

	void Update() {
		Sprite.SetTranslation(glm::vec3(Box.body->GetPosition().x * 20, Box.body->GetPosition().y * 20, 0));
		Sprite.SetRotation(glm::vec3((Box.body->GetAngle() / 3.14 * 180), (Box.body->GetAngle() / 3.14 * 180), (Box.body->GetAngle() / 3.14 * 180)));
	}
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
	void MouseInput(float, float);
	void MouseClicks(unsigned char MouseState[3]);

	void MoveOnSling(float slingX, float slingY, GameObject * fling);

	void ReleaseFromSling(GameObject * fling);

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
	int i2DScalar = 20;

	//Box 2D 
	b2BodyDef groundBodyDef;
	b2Body* groundBody;
	b2Body* SlingBody;
	b2PolygonShape groundBox;

	GameObject Puar;
	GameObject Puar2;
	std::vector<GameObject> Obstacles;
	std::vector<GameObject> Enemies;

	float32 timeStep;
	int32 velocityIterations;
	int32 positionIterations;

	float worldX;
	float worldY;
	bool impulse = true;
	glm::vec2 Slingforce;
};
