/* Copyright 2012-2020 Matthew Reid
 *
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at https://mozilla.org/MPL/2.0/. */


#pragma once

#include <memory>

namespace skybolt {
namespace vis {

using std::shared_ptr;

class AsyncTileLoader;
class ElevationProvider;
class LlaToNedConverter;
class GpuTextureGenerator;
class JsonTileSourceFactory;
struct OsgTile;
class OsgTileFactory;
class PagedForest;
class PlanetFeatures;
struct PlanetSubdivisionPredicate;
struct PlanetTileSources;
struct RenderContext;
class ScreenQuad;
struct ShaderPrograms;
class TextureCompiler;
class TileImageLoader;
struct TileProgressCallback;
class TileSource;
class Arrows;
class BuildingsBatch;
class Billboard;
class BillboardForest;
class Camera;
class Cloud;
class EmbeddedWindow;
class LakesBatch;
class Light;
class VisMarker;
class Model;
class ModelFactory;
class Viewport;
class VisObject;
class Ocean;
class Planet;
class PlanetSurface;
class PlanetSky;
class Polyline;
class RenderTarget;
class RenderTexture;
class RoadsBatch;
class RunwaysBatch;
class RootNode;
class Scene;
class Starfield;
class Terrain;
class Viewport;
class Window;

typedef shared_ptr<AsyncTileLoader> AsyncTileLoaderPtr;
typedef shared_ptr<ElevationProvider> ElevationProviderPtr;
typedef shared_ptr<JsonTileSourceFactory> JsonTileSourceFactoryPtr;
typedef shared_ptr<LlaToNedConverter> LlaToNedConverterPtr;
typedef shared_ptr<OsgTile> OsgTilePtr;
typedef shared_ptr<OsgTileFactory> OsgTileFactoryPtr;
typedef shared_ptr<PagedForest> PagedForestPtr;
typedef shared_ptr<TileImageLoader> TileImageLoaderPtr;
typedef shared_ptr<TileProgressCallback> ProgressCallbackPtr;
typedef shared_ptr<TileSource> TileSourcePtr;
typedef shared_ptr<Arrows> ArrowsPtr;
typedef shared_ptr<BillboardForest> BillboardForestPtr;
typedef shared_ptr<Billboard> BillboardPtr;
typedef shared_ptr<BuildingsBatch> BuildingsBatchPtr;
typedef shared_ptr<Camera> CameraPtr;
typedef shared_ptr<Cloud> CloudPtr;
typedef shared_ptr<LakesBatch> LakesBatchPtr;
typedef shared_ptr<Light> LightPtr;
typedef shared_ptr<VisMarker> VisMarkerPtr;
typedef shared_ptr<Model> ModelPtr;
typedef shared_ptr<ModelFactory> ModelFactoryPtr;
typedef shared_ptr<VisObject> VisObjectPtr;
typedef shared_ptr<Ocean> OceanPtr;
typedef shared_ptr<Planet> PlanetPtr;
typedef shared_ptr<Polyline> PolylinePtr;
typedef shared_ptr<RoadsBatch> RoadsBatchPtr;
typedef shared_ptr<RunwaysBatch> RunwaysBatchPtr;
typedef shared_ptr<RootNode> RootNodePtr;
typedef shared_ptr<Scene> ScenePtr;
typedef shared_ptr<Terrain> TerrainPtr;
typedef shared_ptr<Window> WindowPtr;

typedef size_t InstantMs; //!< Instant of time in milliseconds

} // namespace vis
} // namespace skybolt

namespace px_sched
{
class Scheduler;
class Sync;
}
