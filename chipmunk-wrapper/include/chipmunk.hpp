#ifndef CHIPMUNK_HPP
#define CHIPMUNK_HPP

#include "chipmunk.h"
#include <functional>
#include <memory>
#include <vector>

namespace cp
{
    using BoundingBox = cpBB;
    using Inertia = cpFloat;
    using Mass = cpFloat;
    using Position = cpVect;
    using Transform = cpTransform;
    using Vect = cpVect;

    inline Inertia momentForCircle(Mass m, float innerRadius, float outerRadius, Vect offset = {})
    {
        return cpMomentForCircle(m, innerRadius, outerRadius, offset);
    }

    inline Inertia momentForCircle(Mass m, float radius)
    {
        return cpMomentForCircle(m, 0, radius, {});
    }

    struct Body
    {
        Body(Mass m = .0, Inertia i = .0) : Body{cpBodyNew(m, i)} {}
        Body(cpBody* body) : body{body, cpBodyFree} {}
        operator cpBody*() { return body.get(); }

        void       applyForceAtWorldPoint(const Vect& force, const Vect& point) { cpBodyApplyForceAtWorldPoint(*this, force, point); }
        void       applyForceAtLocalPoint(const Vect& force, const Vect& point) { cpBodyApplyForceAtLocalPoint(*this, force, point); }
        void       applyImpulseAtWorldPoint(const Vect& impulse, const Vect& point) { cpBodyApplyImpulseAtWorldPoint(*this, impulse, point); }
        void       applyImpulseAtLocalPoint(const Vect& impulse, const Vect& point) { cpBodyApplyImpulseAtLocalPoint(*this, impulse, point); }
        void       setAngle(double a) { cpBodySetAngle(*this, a); }
        void       setAngularVelocity(double value) { cpBodySetAngularVelocity(*this, value); }
        void       setCenterOfGravity(const Vect& cog) { cpBodySetCenterOfGravity(*this, cog); }
        void       setForce(const cpVect& value) { cpBodySetForce(*this, value); }
        void       setMass(double m) { cpBodySetMass(*this, m); }
        void       setMoment(double i) { cpBodySetMoment(*this, i); }
        void       setPosition(double x, double y) { setPosition({x, y}); }
        void       setPosition(const Position& p) { cpBodySetPosition(*this, p); }
        void       setTorque(double value) { cpBodySetTorque(*this, value); }
        void       setType(cpBodyType type) { cpBodySetType(*this, type); }
        void       setVelocity(double vx, double vy) { setVelocity({vx, vy}); }
        void       setVelocity(const Vect& value) { cpBodySetVelocity(*this, value); }

        double     getAngle() { return cpBodyGetAngle(*this); }
        double     getAngularVelocity() { return cpBodyGetAngularVelocity(*this); }
        Vect       getCenterOfGravity() { return cpBodyGetCenterOfGravity(*this); }
        Vect       getForce() { return cpBodyGetForce(*this); }
        double     getMass() { return cpBodyGetMass(*this); }
        double     getMoment() { return cpBodyGetMoment(*this); }
        Position   getPosition() { return cpBodyGetPosition(*this); }
        Vect       getRotation() { return cpBodyGetRotation(*this); }
        double     getTorque() { return cpBodyGetTorque(*this); }
        cpBodyType getType() { return cpBodyGetType(*this); }
        Vect       getVelocity() { return cpBodyGetVelocity(*this); }

    private:
        std::unique_ptr<cpBody, std::function<void(cpBody*)>> body;
    };

    struct Constraint
    {
        // TODO
        operator cpConstraint*() { return constraint.get(); }
    private:
        std::unique_ptr<cpConstraint, std::function<void(cpConstraint*)>> constraint;
    };

    struct Shape
    {
        static Shape makeCircle(Body& body, double radius, Vect offset = {.0, .0})
        {
            return Shape{cpCircleShapeNew(body, radius, offset)};
        }

        static Shape makeSegment(Body& body, const Vect& a, const Vect& b, double radius = .0)
        {
            return Shape{cpSegmentShapeNew(body, a, b, radius)};
        }

        static Shape makePolygon(Body& body, const std::vector<Vect> verts, Transform transform = {}, double radius = .0)
        {
            return Shape{cpPolyShapeNew(body, verts.size(), verts.data(), transform, radius)};
        }

        operator cpShape*() { return shape.get(); }

        void   setCollisionType(float value) { cpShapeSetCollisionType(*this, value); }
        void   setElasticity(float value) { cpShapeSetElasticity(*this, value); }
        void   setFriction(double value) { cpShapeSetFriction(*this, value); }
        void   setSensor(bool value) { cpShapeSetSensor(*this, value); }

        BoundingBox getBoundingBox() { return cpShapeGetBB(*this); }
        float  getCollisionType() { return cpShapeGetCollisionType(*this); }
        float  getElasticity() { return cpShapeGetElasticity(*this); }
        double getFriction() { return cpShapeGetFriction(*this); }
        bool   getSensor() { return cpShapeGetSensor(*this); }

    private:
        Shape(cpShape* shape) : shape{shape, cpShapeFree} {}

        std::unique_ptr<cpShape, std::function<void(cpShape*)>> shape;
    };

    struct Space
    {
        Space()
            : space{cpSpaceNew(), cpSpaceFree}
            , staticBody{cpBodyNewStatic()}
        {
            add(staticBody);
        }
        operator cpSpace*() { return space.get(); }

        void   add(Body& body) { cpSpaceAddBody(*this, body); }
        void   add(Constraint& constraint) { cpSpaceAddConstraint(*this, constraint); }
        void   add(Shape& shape) { cpSpaceAddShape(*this, shape); }

        void   setDamping(double value) { cpSpaceSetDamping(*this, value); }
        void   setGravity(const Vect& value) { cpSpaceSetGravity(*this, value); }

        double getDamping() { return cpSpaceGetDamping(*this); }
        Vect   getGravity() { return cpSpaceGetGravity(*this); }
        Body&  getStaticBody() { return staticBody; }

        void   step(double dt) { return cpSpaceStep(*this, dt); }

    private:
        std::unique_ptr<cpSpace, std::function<void(cpSpace*)>> space;
        Body staticBody;
    };
}

#endif
