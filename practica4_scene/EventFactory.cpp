#include <vcl.h>
#pragma hdrstop

#include "EventFactory.h"

Event* EventFactory::createEvent(String name) {
        if (name == "roll")
                return new EventRoll();
        if (name == "pitch")
                return new EventPitch();
        if (name == "yaw")
                return new EventYaw();
        if (name == "glass")
                return new EventGlass();
        if (name == "house")
                return new EventHouse();
        if (name == "zoom")
                return new EventZoom();
        if (name == "sphere")
                return new EventSphere();
        if(name == "orthogonal")
                return new EventOrthogonal();
        if(name == "perspective")
                return new EventPerspective();
        if(name == "oblique")
                return new EventOblique();
        if(name == "along_axis")
                return new EventAlongAxis();
        if(name == "around_axis")
                return new EventAroundAxis();
        if(name == "move")
                return new EventMoveCamera();
        if(name == "z_rotate")
                return new EventZRotate();
        if(name == "corner")
                return new EventCorner();
        if(name == "scam")
                return new EventScam();
        if(name == "kine")
                return new EventKine();
        if(name == "box")
                return new EventBox();
        if(name == "kine-buildings")
                return new EventKineBuildings();
        if(name == "toggle-lighting")
                return new EventToggleLighting();
        if(name == "toggle-materialing")
                return new EventToggleMaterialing();
        if (name == "toggle-light-model-ambient")
                return new EventToggleLightModelAmbient();
        if (name == "fog")
                return new EventFog();
        if (name == "toggle-fog")
                return new EventToggleFog();

        return NULL;
}



list<String>* EventFactory::getEvents() {
        list<String> *registered_events = new list<String>();

        registered_events->push_back("roll");
        registered_events->push_back("pitch");
        registered_events->push_back("yaw");
        registered_events->push_back("glass");
        registered_events->push_back("house");
        registered_events->push_back("zoom");
        registered_events->push_back("sphere");
        registered_events->push_back("orthogonal");
        registered_events->push_back("perspective");
        registered_events->push_back("oblique");
        registered_events->push_back("along_axis");
        registered_events->push_back("around_axis");
        registered_events->push_back("move");
        registered_events->push_back("z_rotate");
        registered_events->push_back("corner");
        registered_events->push_back("box");
        registered_events->push_back("scam");
        registered_events->push_back("kine");
        registered_events->push_back("kine-buildings");
        registered_events->push_back("toggle-lighting");
        registered_events->push_back("toggle-materialing");
        registered_events->push_back("toggle-light-model-ambient");
        registered_events->push_back("fog");
        registered_events->push_back("toggle-fog");
        registered_events->sort();

        return registered_events;
}

#pragma package(smart_init)
