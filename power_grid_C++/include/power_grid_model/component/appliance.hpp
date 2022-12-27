// SPDX-FileCopyrightText: 2022 Contributors to the Power Grid Model project <dynamic.grid.calculation@alliander.com>
//
// SPDX-License-Identifier: MPL-2.0

#pragma once
#ifndef POWER_GRID_MODEL_COMPONENT_APPLIANCE_HPP
#define POWER_GRID_MODEL_COMPONENT_APPLIANCE_HPP

#include "../auxiliary/input.hpp"
#include "../auxiliary/output.hpp"
#include "../calculation_parameters.hpp"
#include "../power_grid_model.hpp"
#include "../three_phase_tensor.hpp"
#include "base.hpp"

namespace power_grid_model {

class Appliance : public Base {
   public:
    using InputType = ApplianceInput;
    using UpdateType = ApplianceUpdate;
    template <bool sym>
    using OutputType = ApplianceOutput<sym>;
    static constexpr char const* name = "appliance";

    Appliance(ApplianceInput const& appliance_input, double u)
        : Base{appliance_input},
          node_{appliance_input.node},
          status_{(bool)appliance_input.status},
          base_i_{base_power_3p / u / sqrt3} {
    }

    // getter
    ID node() const {
        return node_;
    }
    bool status() const {
        return status_;
    }
    double base_i() const {
        return base_i_;
    }
    bool energized(bool is_connected_to_source) const final {
        return is_connected_to_source && status_;
    }

    // setter
    bool set_status(IntS new_status) {
        if (new_status == na_IntS)
            return false;
        if ((bool)new_status == status_)
            return false;
        status_ = (bool)new_status;
        return true;
    }

    // empty output
    template <bool sym>
    ApplianceOutput<sym> get_null_output() const {
        ApplianceOutput<sym> output{};
        static_cast<BaseOutput&>(output) = base_output(false);
        return output;
    }

    template <bool sym>
    ApplianceOutput<sym> get_output(ApplianceMathOutput<sym> const& appliance_math_output) const {
        ApplianceOutput<sym> output{};
        static_cast<BaseOutput&>(output) = base_output(true);
        output.p = base_power<sym> * real(appliance_math_output.s) * injection_direction();
        output.q = base_power<sym> * imag(appliance_math_output.s) * injection_direction();
        output.s = base_power<sym> * cabs(appliance_math_output.s);
        output.i = base_i_ * cabs(appliance_math_output.i);
        // pf
        if constexpr (sym) {
            if (output.s < numerical_tolerance)
                output.pf = 0.0;
            else
                output.pf = output.p / output.s;
        }
        else {
            for (size_t j = 0; j != 3; ++j) {
                if (output.s(j) < numerical_tolerance)
                    output.pf(j) = 0.0;
                else
                    output.pf(j) = output.p(j) / output.s(j);
            }
        }
        return output;
    }
    template <bool sym>
    ApplianceOutput<sym> get_output(ComplexValue<sym> const& u) const {
        if constexpr (sym) {
            return get_output<true>(sym_u2si(u));
        }
        else {
            return get_output<false>(asym_u2si(u));
        }
    }

   protected:
   private:
    ID node_;
    bool status_;
    double base_i_;

    // pure virtual functions for translate from u to s/i
    virtual ApplianceMathOutput<true> sym_u2si(ComplexValue<true> const& u) const = 0;
    virtual ApplianceMathOutput<false> asym_u2si(ComplexValue<false> const& u) const = 0;

    virtual double injection_direction() const = 0;
};

}  // namespace power_grid_model

#endif