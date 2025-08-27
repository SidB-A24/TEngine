//
// Created by Sid B on 26/08/25.
//

#pragma once

/*
 * So we use these 'modules' which we can plug into the TObjects, be it physics or photon.
 * On objects, we can call a update_module_systems() method to link the modules to the respective module systems.
 * The systems modify the modules / use the modules in different ways each tick.
 * The modules serve as storage location for data specific to given object instances, which are unecessary to store within the object directly.
 * Allows a unified TObject, instead of loads of inheritance like TRigidBody, TAffector, etc etc.
*/


namespace TEngine
{
    class TModule {
    public:
        virtual ~TModule() = default;
    };
} // TEngine

