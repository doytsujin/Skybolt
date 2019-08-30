/* Copyright 2012-2020 Matthew Reid
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


#pragma once

#include "SkyboltVis/SkyboltVisFwd.h"

#include <osg/Camera>

namespace skybolt {
namespace vis {

osg::ref_ptr<RenderTarget> createAndAddViewportToWindow(Window& window, const osg::ref_ptr<osg::Program>& compositorProgram);

} // namespace vis
} // namespace skybolt
