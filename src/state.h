#pragma once

#include<godot_cpp/classes/node.hpp>
#include<godot_cpp/core/class_db.hpp>
#include <godot_cpp/classes/resource.hpp>

#include <godot_cpp/classes/input_event.hpp>
#include<godot_cpp/classes/ref.hpp>
#include <godot_cpp/variant/vector2.hpp>
#include<godot_cpp/variant/string.hpp>
#include <godot_cpp/classes/input.hpp>     
#include <godot_cpp/classes/input_event_key.hpp>
#include <godot_cpp/classes/animated_sprite2d.hpp>

#include"player_data.h"


class StateMachine;



class State : public godot::Resource
{
	GDCLASS(State, Resource);

public:

	State()
	{
		state_name = "";
	}

	

	const godot::Vector2 LEFT = godot::Vector2(-1, 0);
	const godot::Vector2 RIGHT = godot::Vector2(1, 0);
	const godot::Vector2 UP = godot::Vector2(0, -1);
	const godot::Vector2 DOWN = godot::Vector2(0, 1);
	const godot::Vector2 ZERO = godot::Vector2(0, 0);



	void set_state_machine(StateMachine* state_machine_);
	void set_owner(godot::Node* owner);
	void bind_player_data(godot::Ref<PlayerData> player_data_);
	void bind_player_animation(AnimatedSprite2D* player_anima);


	virtual void enter() {
		godot::UtilityFunctions::print(get_state_name(), " enter");
	};
	virtual void exit() { godot::UtilityFunctions::print(get_state_name(), "exit"); };
	virtual void update(double delta) {};
	virtual void physics_update(double delta) {};
	virtual void handle_input(const godot::Ref<godot::InputEvent>& event) {};

	void set_state_name(const godot::String& name_);
	godot::String get_state_name();

protected:
	static void _bind_methods();


	godot::String state_name;

	Ref<PlayerData> player_data = Ref<PlayerData>();
	StateMachine* state_machine = nullptr;
	godot::Node* node = nullptr;
	AnimatedSprite2D* player_animation = nullptr;

private:
	
	
	
};

