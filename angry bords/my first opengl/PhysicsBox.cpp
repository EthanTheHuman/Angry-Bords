#include "PhysicsBox.h"



PhysicsBox::PhysicsBox()
{
}


PhysicsBox::PhysicsBox(b2World * _world, float _x, float _y, float _width, float _height, float _density, float _friction, float _linearDampening, float _gravityScale)
{
	// Define the dynamic body. We set its position and call the body factory.
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(_x, _y);
	body = _world->CreateBody(&bodyDef);
	body->SetLinearDamping(_linearDampening);
	body->SetGravityScale(_gravityScale);

	// Define another box shape for our dynamic body.
	dynamicBox.SetAsBox(_width, _height);

	// Define the dynamic body fixture.
	fixtureDef.shape = &dynamicBox;

	// Set the box density to be non-zero, so it will be dynamic.
	fixtureDef.density = _density;

	// Override the default friction.
	fixtureDef.friction = _friction;

	// Add the shape to the body.
	body->CreateFixture(&fixtureDef);
}

PhysicsBox::~PhysicsBox()
{
}
