// SPDX-FileCopyrightText: 2022 Contributors to the Power Grid Model project <dynamic.grid.calculation@alliander.com>
//
// SPDX-License-Identifier: MPL-2.0

#pragma once
#ifndef POWER_GRID_MODEL_COMPONENT_BASE_HPP
#define POWER_GRID_MODEL_COMPONENT_BASE_HPP

#include "../auxiliary/input.hpp"
#include "../auxiliary/output.hpp"
#include "../enum.hpp"
#include "../power_grid_model.hpp"

namespace power_grid_model {

class Base {
   public:
    using InputType = BaseInput;
    using UpdateType = BaseInput;
    template <bool sym>
    using OutputType = BaseOutput;
    static constexpr char const* name = "base";
    virtual ComponentType math_model_type() const = 0;

    Base(BaseInput const& base_input) : id_{base_input.id} {
    }
    virtual ~Base() = default;
    ID id() const noexcept {
        return id_;
    }
    BaseOutput base_output(bool is_energized) const {
        return BaseOutput{id_, is_energized};
    }
    virtual bool energized(bool is_connected_to_source) const = 0;

   private:
    ID id_;
};

}  // namespace power_grid_model

#endif