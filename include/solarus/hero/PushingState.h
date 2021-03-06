/*
 * Copyright (C) 2006-2016 Christopho, Solarus - http://www.solarus-games.org
 *
 * Solarus is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Solarus is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
#ifndef SOLARUS_HERO_PUSHING_STATE_H
#define SOLARUS_HERO_PUSHING_STATE_H

#include "solarus/hero/BaseState.h"
#include <memory>

namespace Solarus {

class PathMovement;

/**
 * \brief The state "Pushing" of the hero.
 */
class Hero::PushingState: public Hero::BaseState {

  public:

    explicit PushingState(Hero& hero);

    virtual void start(const State* previous_state) override;
    virtual void stop(const State* next_state) override;
    virtual void update() override;
    virtual bool can_avoid_stream(const Stream& stream) const override;
    virtual bool can_start_sword() const override;
    virtual bool is_moving_grabbed_entity() const override;
    virtual void notify_grabbed_entity_collision() override;
    virtual void notify_movement_finished() override;
    virtual void notify_obstacle_reached() override;
    virtual void notify_position_changed() override;

    virtual bool can_be_hurt(Entity* attacker) const override;
    virtual bool can_pick_treasure(EquipmentItem& item) const override;
    virtual bool is_shallow_water_obstacle() const override;
    virtual bool is_deep_water_obstacle() const override;
    virtual bool is_hole_obstacle() const override;
    virtual bool is_lava_obstacle() const override;
    virtual bool is_prickle_obstacle() const override;

  private:

    void stop_moving_pushed_entity();

    int pushing_direction4;            /**< Direction where the hero is looking (0 to 3). */
    Entity* pushed_entity;             /**< The entity the hero is pushing or nullptr. */
    std::shared_ptr<PathMovement>
        pushing_movement;              /**< The movement created by this state.
                                        * The movement of the hero is also this object,
                                        * unless a script decided to change it. */
};

}

#endif

