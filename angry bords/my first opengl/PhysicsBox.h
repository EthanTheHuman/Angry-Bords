#include "dependencies\Box2D\Box2D.h"
#pragma once


class PhysicsBox
{
public:
	PhysicsBox();

	/*
		Defines a physics box
		If unsure, these should be the default:
		_x = 0.0f
		_y = 0.0f
		_width = 1.0f
		_height = 1.0f
		_density = 1.0f
		_friction = 0.3f
		_linearDampening = 1.0f
		_gravityScale = 1.0f
	*/
	PhysicsBox(b2World * _world, float _x, float _y, float _width, float _height, float _density, float _friction, float _linearDampening, float _gravityScale);
	~PhysicsBox();

	b2BodyDef bodyDef;
	b2Body* body;
	b2PolygonShape dynamicBox;
	b2FixtureDef fixtureDef;

};

