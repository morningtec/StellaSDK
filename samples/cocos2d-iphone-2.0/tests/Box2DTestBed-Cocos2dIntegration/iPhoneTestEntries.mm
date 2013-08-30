/*
* Copyright (c) 2006-2007 Erin Catto http://www.gphysics.com
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/

//
// File modified for cocos2d integration
// http://www.cocos2d-iphone.org
//

#include "iPhoneTest.h"
//#include "GLES-Render.h"

#include "AddPair.h"
#include "ApplyForce.h"
#include "BodyTypes.h"
#include "Breakable.h"
#include "Bridge.h"
#include "BulletTest.h"
#include "Cantilever.h"
#include "Car.h"
#include "ContinuousTest.h"
#include "Chain.h"
#include "CharacterCollision.h"
#include "CollisionFiltering.h"
#include "CollisionProcessing.h"
#include "CompoundShapes.h"
#include "Confined.h"
#include "DistanceTest.h"
#include "Dominos.h"
#include "DynamicTreeTest.h"
#include "EdgeShapes.h"
#include "EdgeTest.h"
#include "Gears.h"
#include "OneSidedPlatform.h"
#include "Pinball.h"
#include "PolyCollision.h"
#include "PolyShapes.h"
#include "Prismatic.h"
#include "Pulleys.h"
#include "Pyramid.h"
#include "RayCast.h"
#include "Revolute.h"
//#include "Rope.h"
#include "RopeJoint.h"
#include "SensorTest.h"
#include "ShapeEditing.h"
#include "SliderCrank.h"
#include "SphereStack.h"
#include "TheoJansen.h"
#include "Tiles.h"
#include "TimeOfImpact.h"
#include "VaryingFriction.h"
#include "VaryingRestitution.h"
#include "VerticalStack.h"
#include "Web.h"

TestEntry g_testEntries[] =
{
	{"Gears", Gears::Create},
	{"Character Collision", CharacterCollision::Create},
	{"Edge Test", EdgeTest::Create},
	{"Body Types", BodyTypes::Create},
	{"Shape Editing", ShapeEditing::Create},
	{"Tiles", Tiles::Create},
	{"Car", Car::Create},
	{"Apply Force", ApplyForce::Create},
	{"Prismatic", Prismatic::Create},
	{"Vertical Stack", VerticalStack::Create},
	{"SphereStack", SphereStack::Create},
	{"Revolute", Revolute::Create},
	{"Pulleys", Pulleys::Create},
	{"Polygon Shapes", PolyShapes::Create},
	//{"Rope", Rope::Create},
	{"Web", Web::Create},
	{"RopeJoint", RopeJoint::Create},
	{"One-Sided Platform", OneSidedPlatform::Create},
	{"Pinball", Pinball::Create},
	{"Bullet Test", BulletTest::Create},
	{"Continuous Test", ContinuousTest::Create},
	{"Time of Impact", TimeOfImpact::Create},
	{"Ray-Cast", RayCast::Create},
	{"Confined", Confined::Create},
	{"Pyramid", Pyramid::Create},
	{"Varying Restitution", VaryingRestitution::Create},
	{"Theo Jansen's Walker", TheoJansen::Create},
	{"Edge Shapes", EdgeShapes::Create},
	{"PolyCollision", PolyCollision::Create},
	{"Cantilever", Cantilever::Create},
	{"Bridge", Bridge::Create},
	{"Breakable", Breakable::Create},
	{"Chain", Chain::Create},
	{"Collision Filtering", CollisionFiltering::Create},
	{"Collision Processing", CollisionProcessing::Create},
	{"Compound Shapes", CompoundShapes::Create},
	{"Distance Test", DistanceTest::Create},
	{"Dominos", Dominos::Create},
	{"Dynamic Tree", DynamicTreeTest::Create},
	{"Sensor Test", SensorTest::Create},
	{"Slider Crank", SliderCrank::Create},
	{"Varying Friction", VaryingFriction::Create},
	{"Add Pair Stress Test", AddPair::Create},
//	{NULL, NULL}
};

int g_totalEntries = sizeof(g_testEntries) / sizeof(g_testEntries[0]);

