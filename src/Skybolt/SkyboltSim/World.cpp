/* Copyright 2012-2020 Matthew Reid
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


#include "SkyboltSim/World.h"
#include "SkyboltSim/Components/NameComponent.h"

namespace skybolt {
namespace sim {

World::World()
{
}

World::~World()
{
	// Set flag to skip indirect calls to addEntity and removeEntity from clearing mEntities.
	// This could happen if an entity removes its child from the world when it is destroyed.
	// TODO: Investigate cleaner solutions.
	mDestructing = true;
	mEntities.clear();
}

void World::addEntity(const EntityPtr& entity)
{
	if (mDestructing)
	{
		return;
	}

	mEntities.push_back(entity);
	CALL_LISTENERS(entityAdded(entity));
}

void World::removeEntity(Entity* entity)
{
	if (mDestructing)
	{
		return;
	}

	auto it = std::find_if(mEntities.begin(), mEntities.end(), [entity](const EntityPtr& item) {
		return item.get() == entity;
	});

	if (it != mEntities.end())
	{
		EntityPtr objectPtr = *it;
		CALL_LISTENERS(entityAboutToBeRemoved(objectPtr));
		mEntities.erase(it);
		CALL_LISTENERS(entityRemoved(objectPtr));
	}
}

void World::removeAllEntities()
{
	while (!mEntities.empty())
	{
		removeEntity(mEntities.front().get());
	}
}

Vector3 World::calcGravity(const Vector3& position, double mass) const
{
	// Apply gravity towards world origin, which is assumed to be centre of planet
	double magnitude = mass * -9.81f;
	double r = glm::length(position);
	if (r > 1e-8)
	{
		sim::Vector3 dir = position / r;
		return dir * magnitude;
	}
	return Vector3(0, 0, 0);
}

EntityPtr findObjectByName(const World& world, const std::string& name)
{
	if (!name.empty())
	{
		const World::Entities &entities = world.getEntities();
		for (const EntityPtr& entity : entities)
		{
			if (getName(*entity) == name)
			{
				return entity;
			}
		}
	}

	return nullptr;
}

} // namespace sim
} // namespace skybolt