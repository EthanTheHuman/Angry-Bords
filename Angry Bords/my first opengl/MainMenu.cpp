#include "MainMenu.h"

// Define the gravity vector.
b2Vec2 gravity(0.0f, -10.0f);

// Construct a world object, which will hold and simulate the rigid bodies.
b2World world(gravity);

MainMenu::MainMenu()
{
}

void MainMenu::Init()
{
	MyCamera = new Camera(glm::vec3(0, 0, -3), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	SpriteShader = shaderloader.CreateProgram("Shaders/Sprite.vs", "Shaders/Sprite.fs");
	UISpriteShader = shaderloader.CreateProgram("Shaders/UISprite.vs", "Shaders/UISprite.fs");
	ModelBasicShader = shaderloader.CreateProgram("Shaders/ModelBasic.vs", "Shaders/ModelBasic.fs");
	AmbientShader = shaderloader.CreateProgram("Shaders/Ambient.vs", "Shaders/Ambient.fs");
	TextShader = shaderloader.CreateProgram("Shaders/Text.vs", "Shaders/Text.fs");
	SkyboxShader = shaderloader.CreateProgram("Shaders/Cubemap.vs", "Shaders/Cubemap.fs");

	//Background elements
	Sprite* TempSprite = new Sprite("Textures/Background/BG.png", MyCamera, SpriteShader);
	BGElements.push_back(TempSprite); 
	TempSprite = new Sprite("Textures/Background/Ground.png", MyCamera, SpriteShader);
	BGElements.push_back(TempSprite);

	//Box2D stuff
	//-------------------------------------------------------------------------------------------------------------------------------

	// Define the ground body.
	groundBodyDef.position.Set(0.0f, -10.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundBody = world.CreateBody(&groundBodyDef);

	// Define the ground box shape.
	

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(50.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	// Define the dynamic body. We set its position and call the body factory.
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(0.0f, 400.0f);
	body = world.CreateBody(&bodyDef);

	// Define another box shape for our dynamic body.
	dynamicBox.SetAsBox(31.0f, 52.0f);

	// Define the dynamic body fixture.
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = 1.0f;

	// Override the default friction.
	fixtureDef.friction = 0.3f;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
	Puar = new Sprite("Textures/Puar.png", MyCamera, SpriteShader);


	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.

	timeStep = 1.0f / 60.0f;
	velocityIterations = 6;
	positionIterations = 2;

	//-------------------------------------------------------------------------------------------------------------------------------

	MenuUpdate();
}

void MainMenu::Deconstruct()
{
	delete MyCamera;
	delete _Player;
	delete MySkybox;
	nextScene = NOTHING;
	menu = MAIN;
	selection = 0;
}

void MainMenu::Render()
{
	MyCamera->Update();
	glFrontFace(GL_CCW);

	//Background
	for (int i = 0; i < BGElements.size(); i++)
	{
		BGElements[i]->render();
	}

	Puar->SetTranslation(glm::vec3(body->GetPosition().x, body->GetPosition().y, 0));
	Puar->render();

}


void MainMenu::Update()
{
	float currentTime = glutGet(GLUT_ELAPSED_TIME);
	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.
	world.Step(timeStep, velocityIterations, positionIterations);
}

MainMenu::~MainMenu()
{
}

void MainMenu::MoveCharacter(unsigned char KeyState[255]) {
	if (KeyState[(unsigned char)'a'] == INPUT_FIRST_PRESS)
	{

	}
	if (KeyState[(unsigned char)'d'] == INPUT_FIRST_PRESS)
	{

	}
	if (KeyState[(unsigned char)' '] == INPUT_FIRST_PRESS)
	{

	}
	if (KeyState[(unsigned char)'\x1b'] == INPUT_FIRST_PRESS)
	{

	}
	if (KeyState[(unsigned char)'w'] == INPUT_FIRST_PRESS)
	{

	}
	if (KeyState[(unsigned char)'s'] == INPUT_FIRST_PRESS)
	{
	}
}

void MainMenu::MenuUpdate() {
	
}

void MainMenu::ChangeNames(std::vector<std::string> _strings)
{
	
}

void MainMenu::ChangeHostNames(std::vector<std::string> _strings)
{
	
}
