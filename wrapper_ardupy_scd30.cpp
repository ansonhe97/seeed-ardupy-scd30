/**
 * The MIT License (MIT)
 *
 * Author: Anson He (anson.he@seeed.cc)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "Seeed_Arduino_SCD30/SCD30.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}

#define scd30 (*(SCD30*)self->module)
void * operator new(size_t, void *);

extern "C" {
    void common_hal_scd30_construct(abstract_module_t *self){
        self->module = new (m_new_obj(SCD30)) SCD30();
        scd30.initialize();
    }
    void common_hal_scd30_deinit(abstract_module_t *self){
        scd30.~SCD30();
    }
    bool common_hal_scd30_isAvailable(abstract_module_t *self){
        return scd30.isAvailable();
    }
    void common_hal_scd30_setAutoSelfCalibration(abstract_module_t *self, bool enable){
        return scd30.setAutoSelfCalibration(enable);
    }
    void common_hal_scd30_setMeasurementInterval(abstract_module_t *self, uint16_t interval){
        return scd30.setMeasurementInterval(interval);
    }
    void common_hal_scd30_startPeriodicMeasurment(abstract_module_t *self){
        return scd30.startPeriodicMeasurment();
    }
    void common_hal_scd30_stopMeasurement(abstract_module_t *self){
        return scd30.stopMeasurement();
    }
    void common_hal_scd30_setTemperatureOffset(abstract_module_t *self, uint16_t offset){
        return scd30.setTemperatureOffset(offset);
    }
    void common_hal_scd30_getCarbonDioxideConcentration(abstract_module_t *self, float* result){
        return scd30.getCarbonDioxideConcentration(result);
    }
}