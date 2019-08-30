/* Copyright 2012-2020 Matthew Reid
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "SkyboltVis/DefaultRootNode.h"

namespace skybolt {
namespace vis {

class BillboardForest : public DefaultRootNode
{
public:
	struct Tree
	{
		osg::Vec3f position;
		float height;
		float yaw;
		int type;
	};

	BillboardForest(const std::vector<Tree>& trees, osg::ref_ptr<osg::Program> sideProgram, osg::ref_ptr<osg::Program> topProgram, float maxVisibilityRange);

	static void addGeodes(osg::Group& node, const std::vector<Tree>& trees, osg::ref_ptr<osg::Program> sideProgram, osg::ref_ptr<osg::Program> topProgram, float maxVisibilityRange);
};

} // namespace vis
} // namespace skybolt
