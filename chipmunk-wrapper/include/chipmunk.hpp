#ifndef CHIPMUNK_HPP
#define CHIPMUNK_HPP

#include <functional>
#include <memory>
#include "chipmunk.h"

namespace cp
{
    using BB = cpBB;
    using Position = cpVect;
    using Vect = cpVect;

    struct Body
    {
        Body(double mass = .0, double inertia = .0) : Body{cpBodyNew(mass, inertia)} {}
        Body(cpBody* body) : body{body, cpBodyFree} {}
        operator cpBody*() { return body.get(); }

        void       SetAngle(double a) { cpBodySetAngle(*this, a); }
        void       SetAngularVelocity(double value) { cpBodySetAngularVelocity(*this, value); }
        void       SetCenterOfGravity(const Vect& cog) { cpBodySetCenterOfGravity(*this, cog); }
        void       SetForce(const cpVect& value) { cpBodySetForce(*this, value); }
        void       SetMass(double m) { cpBodySetMass(*this, m); }
        void       SetMoment(double i) { cpBodySetMoment(*this, i); }
        void       SetPosition(const Position& p) { cpBodySetPosition(*this, p); }
        void       SetTorque(double value) { cpBodySetTorque(*this, value); }
        void       SetType(cpBodyType type) { cpBodySetType(*this, type); }
        void       SetVelocity(const Vect& value) { cpBodySetVelocity(*this, value); }

        double     GetAngle() { return cpBodyGetAngle(*this); }
        double     GetAngularVelocity() { return cpBodyGetAngularVelocity(*this); }
        Vect       GetCenterOfGravity() { return cpBodyGetCenterOfGravity(*this); }
        Vect       GetForce() { return cpBodyGetForce(*this); }
        double     GetMass() { return cpBodyGetMass(*this); }
        double     GetMoment() { return cpBodyGetMoment(*this); }
        Position   GetPosition() { return cpBodyGetPosition(*this); }
        Vect       GetRotation() { return cpBodyGetRotation(*this); }
        double     GetTorque() { return cpBodyGetTorque(*this); }
        cpBodyType GetType() { return cpBodyGetType(*this); }
        Vect       GetVelocity() { return cpBodyGetVelocity(*this); }

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
        Shape(cpShape* shape) : shape{shape, cpShapeFree} {}
        operator cpShape*() { return shape.get(); }

        void   SetCollisionType(float value) { cpShapeSetCollisionType(*this, value); }
        void   SetElasticity(float value) { cpShapeSetElasticity(*this, value); }
        void   SetFriction(double value) { cpShapeSetFriction(*this, value); }
        void   SetSensor(bool value) { cpShapeSetSensor(*this, value); }

        BB     GetBoundingBox() { return cpShapeGetBB(*this); }
        float  GetCollisionType() { return cpShapeGetCollisionType(*this); }
        float  GetElasticity() { return cpShapeGetElasticity(*this); }
        double GetFriction() { return cpShapeGetFriction(*this); }
        bool   GetSensor() { return cpShapeGetSensor(*this); }

    private:
        std::unique_ptr<cpShape, std::function<void(cpShape*)>> shape;
    };

    struct Circle : public Shape
    {
        Circle(Body& body, double radius, Vect offset = {.0, .0})
            : Shape{cpCircleShapeNew(body, radius, offset)}
        {}
    };

    struct Segment : public Shape
    {
        Segment(Body& body, const Vect& a, const Vect& b, double radius = .0)
            : Shape{cpSegmentShapeNew(body, a, b, radius)}
        {}
    };

    struct Space
    {
        Space()
            : space{cpSpaceNew(), cpSpaceFree}
            , staticBody{cpBodyNewStatic()}
        {
            Add(staticBody);
        }
        operator cpSpace*() { return space.get(); }
        void Add(Body& body) { cpSpaceAddBody(*this, body); }
        void Add(Constraint& constraint) { cpSpaceAddConstraint(*this, constraint); }
        void Add(Shape& shape) { cpSpaceAddShape(*this, shape); }

        void SetDamping(double value) { cpSpaceSetDamping(*this, value); }
        void SetGravity(const Vect& value) { cpSpaceSetGravity(*this, value); }

        double GetDamping() { return cpSpaceGetDamping(*this); }
        Vect GetGravity() { return cpSpaceGetGravity(*this); }
        Body& GetStaticBody() { return staticBody; }
        void Step(double dt) { return cpSpaceStep(*this, dt); }

    private:
        std::unique_ptr<cpSpace, std::function<void(cpSpace*)>> space;
        Body staticBody;
    };
}

#endif
