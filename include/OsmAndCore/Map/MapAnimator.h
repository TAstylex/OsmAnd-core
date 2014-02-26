#ifndef _OSMAND_CORE_MAP_ANIMATOR_H_
#define _OSMAND_CORE_MAP_ANIMATOR_H_

#include <OsmAndCore/stdlib_common.h>
#include <functional>

#include <OsmAndCore/QtExtensions.h>

#include <OsmAndCore.h>
#include <OsmAndCore/CommonTypes.h>
#include <OsmAndCore/Map/MapTypes.h>

namespace OsmAnd
{
    class IMapRenderer;

    class MapAnimator_P;
    class OSMAND_CORE_API MapAnimator
    {
        Q_DISABLE_COPY(MapAnimator);
    private:
        const std::unique_ptr<MapAnimator_P> _d;
    protected:
    public:
        MapAnimator();
        virtual ~MapAnimator();

        void setMapRenderer(const std::shared_ptr<IMapRenderer>& mapRenderer);
        const std::shared_ptr<IMapRenderer>& mapRenderer;

        bool isAnimationPaused() const;
        bool isAnimationRunning() const;

        void pauseAnimation();
        void resumeAnimation();
        void cancelAnimation();

        void update(const float timePassed);

        void animateZoomBy(
            const float deltaValue, const float duration,
            const MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            const MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void animateZoomWith(const float velocity, const float deceleration);

        void animateTargetBy(
            const PointI& deltaValue, const float duration,
            const MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            const MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void animateTargetBy(
            const PointI64& deltaValue, const float duration,
            const MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            const MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void animateTargetWith(const PointD& velocity, const PointD& deceleration);

        void parabolicAnimateTargetBy(
            const PointI& deltaValue, const float duration,
            MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void parabolicAnimateTargetBy(
            const PointI64& deltaValue, const float duration,
            MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void parabolicAnimateTargetWith(const PointD& velocity, const PointD& deceleration);

        void animateAzimuthBy(
            const float deltaValue, const float duration,
            const MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            const MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void animateAzimuthWith(const float velocity, const float deceleration);

        void animateElevationAngleBy(
            const float deltaValue, const float duration,
            const MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            const MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void animateElevationAngleWith(const float velocity, const float deceleration);

        void animateMoveBy(
            const PointI& deltaValue, const float duration,
            const bool zeroizeAzimuth, const bool invZeroizeElevationAngle,
            const MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            const MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void animateMoveBy(
            const PointI64& deltaValue, const float duration,
            const bool zeroizeAzimuth, const bool invZeroizeElevationAngle,
            const MapAnimatorEasingType easingIn = MapAnimatorEasingType::Quadratic,
            const MapAnimatorEasingType easingOut = MapAnimatorEasingType::Quadratic);
        void animateMoveWith(const PointD& velocity, const PointD& deceleration, const bool zeroizeAzimuth, const bool invZeroizeElevationAngle);
    };
}

#endif // !defined(_OSMAND_CORE_MAP_ANIMATOR_H_)
