#include "MainMenu.h"

// Define the gravity vector.
b2Vec2 gravity(0.0f, -9.81f);

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
	AmbientShader = shaderloader.CreateProgram("Shaders/Ambient.vs", "Shaders/Ambient.fs");
	TextShader = shaderloader.CreateProgram("Shaders/Text.vs", "Shaders/Text.fs");

	//Background elements
	Sprite* TempSprite = new Sprite("Textures/Background/BG.png", MyCamera, SpriteShader);
	BGElements.push_back(TempSprite); 
	TempSprite = new Sprite("Textures/Background/Ground.png", MyCamera, SpriteShader);
	BGElements.push_back(TempSprite);

	//Box2D stuff
	//----------------------------------------------------------------------------------------
	// Define the ground body.
	groundBodyDef.position.Set(0.0f, -40.0f);

	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundBody = world.CreateBody(&groundBodyDef);

	

	DebugDraw bebugDraw;
	world.SetDebugDraw(&bebugDraw);
	uint32 flags = 0;
	flags += b2Draw::e_shapeBit;
	bebugDraw.SetFlags(flags);

	// Define the ground box shape.
	

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(200.0f, 10.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	Puar.Sprite = Sprite("Textures/Krillin.png", MyCamera, SpriteShader);
	Puar.Box = PhysicsBox(&world, -23.5f, -18.5f, 2.0f, 3.0f, 1.0f, 0.3f, 1.0f, 1.0f);

<<<<<<< HEAD
	//Rope joint
	RopeJoint.gravity = gravity;
=======
	Puar2.Sprite = Sprite("Textures/Krillin.png", MyCamera, SpriteShader);
	Puar2.Box = PhysicsBox(&world, -21.0f, 30.0f, 2.0f, 3.0f, 1.0f, 0.3f, 1.0f, 1.0f);

	GameObject TempGameObject;
	TempGameObject.Sprite = Sprite("Textures/Roblock.png", MyCamera, SpriteShader);
	TempGameObject.Box = PhysicsBox(&world, 15.0f, 00.0f, 2.5f, 2.5f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 15.0f, 5.0f, 2.5f, 2.5f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 15.0f, 10.0f, 2.5f, 2.5f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 15.0f, 15.0f, 2.5f, 2.5f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 15.0f, 20.0f, 2.5f, 2.5f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);

>>>>>>> bfcf5f789ee2f7a4aa85825a31ec93588e6cbb65


	// Prepare for simulation. Typically we use a time step of 1/60 of a
	// second (60Hz) and 10 iterations. This provides a high quality simulation
	// in most game scenarios.

	timeStep = 1.0f / 60.0f;
	velocityIterations = 6;
	positionIterations = 2;
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
<<<<<<< HEAD
=======

	//Obstacles
	for (int i = 0; i < Obstacles.size(); i++)
	{
		Obstacles[i].Update();
		Obstacles[i].Sprite.render();
	}

>>>>>>> bfcf5f789ee2f7a4aa85825a31ec93588e6cbb65
	Puar.Sprite.render();
}

float oldTimeSinceStart = 0;
void MainMenu::Update()
{
	float TimeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = TimeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = TimeSinceStart;
	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.

	Puar.Update();

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

void MainMenu::MouseInput(int x, int y)
{
	worldX = (x - 400) / 10;
	worldY = (y - 300) / 10;

	cout << worldY << " ";

	b2MouseJointDef md;
	b2BodyDef temp;
	md.bodyA = world.CreateBody(&temp);
	md.bodyB = Puar.Box.body;

	md.target.Set(worldX, worldY);

	md.collideConnected = false;
	md.maxForce = 5000;
	md.frequencyHz = 5;
	md.dampingRatio = 0.9;
	cout << md.target.y << endl;

	if (mouseJoint != nullptr) {
		world.DestroyJoint(mouseJoint);
		mouseJoint = NULL;
	}
	mouseJoint = static_cast<b2MouseJoint*>(world.CreateJoint(&md));
}

void MainMenu::MouseClicks(unsigned char MouseState[3])
{
	if (MouseState[0] == INPUT_RELEASED) {
		world.DestroyJoint(mouseJoint);
		mouseJoint = NULL;
	}
}
