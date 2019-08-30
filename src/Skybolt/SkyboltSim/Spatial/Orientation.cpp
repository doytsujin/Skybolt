/* Copyright 2012-2020 Matthew Reid
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */

#include "Orientation.h"
#include "SimMath.h"
#include "Geocentric.h"
#include "GreatCircle.h"
#include <assert.h>

namespace skybolt {
namespace sim {

GeocentricOrientation toGeocentric(const Orientation& orientation, const LatLon& latLon)
{
	switch (orientation.type)
	{
		case Orientation::TypeGeocentric:
		{
			return static_cast<const GeocentricOrientation&>(orientation);
		}
		case Orientation::TypeLtpNed:
		{
			sim::Quaternion ltpOriRelGeocentric = latLonToGeocentricLtpOrientation(latLon);

			const LtpNedOrientation& ori = static_cast<const LtpNedOrientation&>(orientation);

			sim::Quaternion oriRelLtp = ori.orientation;

			GeocentricOrientation result;
			result.orientation = ltpOriRelGeocentric * oriRelLtp;
			return result;
		}
		default:
			assert(!"Not implemented");
	}
	return GeocentricOrientation();
}

LtpNedOrientation toLtpNed(const Orientation& orientation, const LatLon& latLon)
{
	switch (orientation.type)
	{
	case Orientation::TypeGeocentric:
	{
		sim::Quaternion ltpOriRelGeocentric = latLonToGeocentricLtpOrientation(latLon);

		const GeocentricOrientation& ori = static_cast<const GeocentricOrientation&>(orientation);

		sim::Quaternion geocentricOri = ori.orientation;

		LtpNedOrientation result;
		result.orientation = glm::inverse(ltpOriRelGeocentric) * geocentricOri;
		return result;
	}
	case Orientation::TypeLtpNed:
	{
		return static_cast<const LtpNedOrientation&>(orientation);
	}
	default:
		assert(!"Not implemented");
	}
	return LtpNedOrientation();
}

} // namespace skybolt
} // namespace sim