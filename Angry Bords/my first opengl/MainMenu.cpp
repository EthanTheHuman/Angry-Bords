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

	//Sound
	Sound::GetInstance()->Musicchannel->stop();
	Sound::GetInstance()->audioMgr->playSound(Sound::GetInstance()->bgmTheme, 0, false, &Sound::GetInstance()->Musicchannel);

	//Background elements
	Sprite* TempSprite = new Sprite("Textures/Background/BG.png", MyCamera, SpriteShader);
	BGElements.push_back(TempSprite); 
	TempSprite = new Sprite("Textures/Background/Ground.png", MyCamera, SpriteShader);
	BGElements.push_back(TempSprite);
	TempSprite = new Sprite("Textures/Logos.png", MyCamera, SpriteShader);
	BGElements.push_back(TempSprite);

	//Box2D stuff
	//-------------------------------------------------------------------------------------------------------------------------------
	// Define the ground body.
	groundBodyDef.position.Set(0.0f, -40.0f);
	// Call the body factory which allocates memory for the ground body
	// from a pool and creates the ground box shape (also from a pool).
	// The body is also added to the world.
	groundBody = world.CreateBody(&groundBodyDef);
	groundBody->SetType(b2_staticBody);

	// Define the ground box shape.
	

	// The extents are the half-widths of the box.
	groundBox.SetAsBox(200.0f, 12.0f);

	// Add the ground fixture to the ground body.
	groundBody->CreateFixture(&groundBox, 0.0f);

	Puar.Sprite = Sprite("Textures/Krillin.png", MyCamera, SpriteShader);
	Puar.Box = PhysicsBox(&world, -23.5f, -18.5f, 2.0f, 3.0f, 1.0f, 0.3f, 1.0f, 1.0f);

	Puar2.Sprite = Sprite("Textures/Piccolo.png", MyCamera, SpriteShader);
	Puar2.Box = PhysicsBox(&world, -21.0f, 30.0f, 1.75f, 1.8f, 1.0f, 0.3f, 1.0f, 1.0f);

	GameObject TempGameObject;
	b2Body *ClingHercule;
	b2Body *ClingBox;
	b2Body *PrisBox;
	b2Body *SlideBox;

	//Square
	TempGameObject.Sprite = Sprite("Textures/Roblock.png", MyCamera, SpriteShader);
	TempGameObject.Box = PhysicsBox(&world, 10.0f, -25.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 10.0f, -20.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 10.0f, -15.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 10.0f, 05.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, -10.0f, -25.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	PrisBox = Obstacles.back().Box.body;

	TempGameObject.Box = PhysicsBox(&world, 15.0f, -5.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);

	TempGameObject.Box = PhysicsBox(&world, 20.0f, -25.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 20.0f, -20.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 20.0f, -10.0, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 20.0f, -5.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);

	TempGameObject.Box = PhysicsBox(&world, 30.0f, -25.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 30.0f, -20.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 30.0f, -15.0f, 2.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);

	//2-wide
	TempGameObject.Sprite = Sprite("Textures/Wideblock.png", MyCamera, SpriteShader);
	TempGameObject.Box = PhysicsBox(&world, 12.5f, -10.0f, 4.99f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 27.5f, -10.0f, 4.99f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);

	TempGameObject.Box = PhysicsBox(&world, 0.0f, -20.0f, 4.99f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	SlideBox = Obstacles.back().Box.body;

	//3-wide
	TempGameObject.Sprite = Sprite("Textures/Widerblock.png", MyCamera, SpriteShader);
	TempGameObject.Box = PhysicsBox(&world, 5.0f, -5.0f, 7.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 15.0f, 0.0f, 7.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);
	ClingBox = Obstacles.back().Box.body;
	TempGameObject.Box = PhysicsBox(&world, 20.0f, -15.0f, 7.49f, 2.49f, 1.0f, 0.3f, 1.0f, 1.0f);
	Obstacles.push_back(TempGameObject);


	//Enemies
	TempGameObject.Sprite = Sprite("Textures/Hercule.png", MyCamera, SpriteShader);
	TempGameObject.Sprite.SetScale(glm::vec3(-1, 1, 1));
	//Hanging
	TempGameObject.Box = PhysicsBox(&world, 0.0f, -15.0f, 2.5f, 3.1f, 1.0f, 0.3f, 1.0f, 1.0f);
	Enemies.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 15.0f, -20.0f, 2.5f, 3.1f, 1.0f, 0.3f, 1.0f, 1.0f);
	Enemies.push_back(TempGameObject);
	TempGameObject.Box = PhysicsBox(&world, 20.0f, 10.0f, 2.5f, 3.1f, 1.0f, 0.3f, 1.0f, 1.0f);
	Enemies.push_back(TempGameObject);
	ClingHercule = Enemies.back().Box.body;
	//Cling
	TempGameObject.Box = PhysicsBox(&world, 25.0f, -20.0f, 2.5f, 3.1f, 1.0f, 0.3f, 1.0f, 1.0f);
	Enemies.push_back(TempGameObject);

	//Distance joints
	b2DistanceJointDef dDef;
	dDef.bodyA = ClingHercule;
	dDef.bodyB = ClingBox;
	world.CreateJoint(static_cast<b2JointDef*>(&dDef));

	//PrismaticJoint
	b2PrismaticJointDef pDef;
	pDef.bodyA = PrisBox;
	pDef.bodyB = SlideBox;
	world.CreateJoint(static_cast<b2JointDef*>(&pDef));

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

	//Obstacles
	for (int i = 0; i < Obstacles.size(); i++)
	{
		Obstacles[i].Update();
		Obstacles[i].Sprite.render();
	}

	//Enemies
	for (int i = 0; i < Enemies.size(); i++)
	{
		Enemies[i].Update();
		Enemies[i].Sprite.render();
	}

	Puar.Sprite.render();
	Puar2.Sprite.render();
}

float oldTimeSinceStart = 0;
void MainMenu::Update()
{
	float TimeSinceStart = glutGet(GLUT_ELAPSED_TIME);
	float deltaTime = TimeSinceStart - oldTimeSinceStart;
	oldTimeSinceStart = TimeSinceStart;
	// Instruct the world to perform a single step of simulation.
	// It is generally best to keep the time step and iterations fixed.

	world.Step(timeStep, velocityIterations, positionIterations);

	Puar.Update();
	Puar2.Update();
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

void MainMenu::MouseInput(float x, float y)
{
	worldX = (x - 400) / 10;
	worldY = (y - 300) / 10;
}

void MainMenu::MouseClicks(unsigned char MouseState[3])
{
	if (MouseState[0] == INPUT_HOLD) {
		MoveOnSling(-23.5f, 19.0f, &Puar);
		cout << worldX << " " << worldY << endl;
		impulse = true;
	}
	if (MouseState[0] == INPUT_RELEASED) {
		if (impulse) {
			ReleaseFromSling(&Puar);
			impulse = false;
		}
	}
}

void MainMenu::MoveOnSling(float slingX, float slingY, GameObject * fling) {

	const double x_diff = slingX - worldX;
	const double y_diff = slingY - worldY;
	float distance = std::sqrt(x_diff * x_diff + y_diff * y_diff);

	glm::vec2 SlingPos;

	if (distance < 10) {
		SlingPos.x = worldX;
		SlingPos.y = -worldY;

		Slingforce.x = -x_diff;
		Slingforce.y = y_diff;
		fling->ChangePos(SlingPos, NULL);
	}
	else {
		SlingPos.x = (-(x_diff / distance) * 10) + slingX;
		SlingPos.y = ((y_diff / distance) * 10) - slingY;

		Slingforce.x = -(x_diff / distance) * 10;
		Slingforce.y = (y_diff / distance) * 10;

		fling->ChangePos(SlingPos, NULL);
	}
}

void MainMenu::ReleaseFromSling(GameObject * fling) {
	fling->Box.body->ApplyLinearImpulse({ -Slingforce.x * 1000, -Slingforce.y * 1000 }, fling->Box.body->GetWorldCenter(), true);
}