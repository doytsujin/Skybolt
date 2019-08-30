/* Copyright 2012-2020 Matthew Reid
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#pragma once

#include "SimVisBinding.h"
#include <SkyboltVis/SkyboltVisFwd.h>

namespace skybolt {

class PlanetVisBinding : public SimpleSimVisBinding
{
public:
	PlanetVisBinding(JulianDateProvider dateProvider, const sim::Entity* entity, const vis::PlanetPtr& visObject);
	void syncVis(const GeocentricToNedConverter& converter) override;

private:
	JulianDateProvider mDateProvider;
};

} // namespace skybolt