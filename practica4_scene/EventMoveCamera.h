//---------------------------------------------------------------------------

#ifndef EventMoveCameraH
#define EventMoveCameraH

#include "Event.h"

class EventMoveCamera : public Event {

public:
        String getName();
        bool event(ViewPort3D *_viewport, Scene3D *_scene, String type, WORD key, TShiftState shift);

};

#endif