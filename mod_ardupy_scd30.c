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

#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"

void common_hal_scd30_construct(abstract_module_t *self);
void common_hal_scd30_deinit(abstract_module_t *self);
bool common_hal_scd30_isAvailable(abstract_module_t *self);
void common_hal_scd30_setAutoSelfCalibration(abstract_module_t *self, bool enable);
void common_hal_scd30_setMeasurementInterval(abstract_module_t *self, uint16_t interval);
void common_hal_scd30_startPeriodicMeasurment(abstract_module_t *self);
void common_hal_scd30_stopMeasurement(abstract_module_t *self);
void common_hal_scd30_setTemperatureOffset(abstract_module_t *self, uint16_t offset);
void common_hal_scd30_getCarbonDioxideConcentration(abstract_module_t *self, float* result);
extern const mp_obj_type_t grove_scd30_type;

m_generic_make(scd30) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 0, false);
    common_hal_scd30_construct(self);
    return self;
}

mp_obj_t scd30_isAvailable(mp_obj_t self_in)
{
    bool ret_val = common_hal_scd30_isAvailable((abstract_module_t *)self_in);
    return mp_obj_new_bool(ret_val);
}

MP_DEFINE_CONST_FUN_OBJ_1(scd30_isAvailable_obj, scd30_isAvailable);

mp_obj_t scd30_setAutoSelfCalibration(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    bool enable = mp_obj_is_true(pos_args[1]);
    common_hal_scd30_setAutoSelfCalibration(self, enable);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(scd30_setAutoSelfCalibration_obj, 1, scd30_setAutoSelfCalibration);

mp_obj_t scd30_setMeasurementInterval(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t interval = mp_obj_get_int(pos_args[1]);
    common_hal_scd30_setMeasurementInterval(self, interval);
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_KW(scd30_setMeasurementInterval_obj, 1, scd30_setMeasurementInterval);

mp_obj_t scd30_startPeriodicMeasurment(mp_obj_t self_in)
{
    common_hal_scd30_startPeriodicMeasurment((abstract_module_t *)self_in);
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_1(scd30_startPeriodicMeasurment_obj, scd30_startPeriodicMeasurment);

mp_obj_t scd30_stopMeasurement(mp_obj_t self_in)
{
    common_hal_scd30_stopMeasurement((abstract_module_t *)self_in);
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_1(scd30_stopMeasurement_obj, scd30_stopMeasurement);

mp_obj_t scd30_setTemperatureOffset(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args)
{
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t offset = mp_obj_get_int(pos_args[1]);
    common_hal_scd30_setTemperatureOffset(self, offset);
    return mp_const_none;
}

MP_DEFINE_CONST_FUN_OBJ_KW(scd30_setTemperatureOffset_obj, 1, scd30_setTemperatureOffset);

mp_obj_t scd30_getCarbonDioxideConcentration(size_t n_args, const mp_obj_t *args)
{
    abstract_module_t *self = (abstract_module_t *)args[0];

    float *buff = (float *)m_malloc(3 * sizeof(float));
    mp_obj_t *ret_val = (mp_obj_t *)m_malloc(3 * sizeof(mp_obj_t));

    common_hal_scd30_getCarbonDioxideConcentration(self, buff);

    for (int i = 0; i < 3; i++)
    {
        ret_val[i] = mp_obj_new_float(buff[i]);
    }
    mp_obj_t ret = mp_obj_new_tuple(3, ret_val);
    m_free(buff);
    m_free(ret_val);
    return ret;
}

STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(scd30_getCarbonDioxideConcentration_obj, 1, 1, scd30_getCarbonDioxideConcentration);

const mp_rom_map_elem_t scd30_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&scd30_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&scd30_obj___exit___obj) },
    {MP_ROM_QSTR(MP_QSTR_isAvailable), MP_ROM_PTR(&scd30_isAvailable_obj)},
    {MP_ROM_QSTR(MP_QSTR_setAutoSelfCalibration), MP_ROM_PTR(&scd30_setAutoSelfCalibration_obj)},
    {MP_ROM_QSTR(MP_QSTR_setMeasurementInterval), MP_ROM_PTR(&scd30_setMeasurementInterval_obj)},
    {MP_ROM_QSTR(MP_QSTR_startPeriodicMeasurment), MP_ROM_PTR(&scd30_startPeriodicMeasurment_obj)},
    {MP_ROM_QSTR(MP_QSTR_stopMeasurement), MP_ROM_PTR(&scd30_stopMeasurement_obj)},
    {MP_ROM_QSTR(MP_QSTR_setTemperatureOffset), MP_ROM_PTR(&scd30_setTemperatureOffset_obj)},
    {MP_ROM_QSTR(MP_QSTR_getCarbonDioxideConcentration), MP_ROM_PTR(&scd30_getCarbonDioxideConcentration_obj)},

};

MP_DEFINE_CONST_DICT(scd30_locals_dict, scd30_locals_dict_table);

const mp_obj_type_t grove_scd30_type = {
    {&mp_type_type},
    .name = MP_QSTR_grove_scd30,
    .make_new = scd30_make_new,
    .locals_dict = (mp_obj_t)&scd30_locals_dict,
};
