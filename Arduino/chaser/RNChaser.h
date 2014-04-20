//
//  RNChaser.h
//
//  Created by Bill on 3/24/14.
//  Copyright (c) 2014 Ninja Monkey Coders. All rights reserved.
//

#ifndef __RNChaser__
#define __RNChaser__

#include <stdint.h>

#include "RNLights.h"

class RNChaser {
    
public:
    RNChaser();
    void update(RNLights & lights, unsigned long millis); 
    void setRPM(RNLights & lights, uint16_t rpm); 
   
    bool forward;
    bool active;
    unsigned long lastUpdate;
    uint16_t delay;
    int16_t position;
    uint8_t r,g,b;
};

#endif /* defined(__RNChaser__) */