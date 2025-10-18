#include"state_machine.h"

void StateMachine::_bind_methods()
{
	godot::ClassDB::bind_method(godot::D_METHOD("add_state", "id", "state"), &StateMachine::add_state);
	godot::ClassDB::bind_method(godot::D_METHOD("change_state", "id"), &StateMachine::change_state);
	godot::ClassDB::bind_method(godot::D_METHOD("bind_player_data", "player_data_"), &StateMachine::bind_player_data);
	godot::ClassDB::bind_method(godot::D_METHOD("bind_player_animation", "player_anima"), &StateMachine::bind_player_animation);
	godot::ClassDB::bind_method(godot::D_METHOD("start"), &StateMachine::start);
	ADD_SIGNAL(godot::MethodInfo("state_changed", godot::PropertyInfo(godot::Variant::STRING, "from_state"), godot::PropertyInfo(godot::Variant::STRING, "to_state")));
}

void StateMachine::add_state(const godot::String& id, const godot::Ref<State> state)
{

	if (state.is_valid()) state_pool[id] = state;
}

void StateMachine::change_state(const godot::String& id)
{
	if (!state_pool.has(id)) 
	{
		godot::UtilityFunctions::printerr("State '", id, "' not found!");
		return;
	}

	godot::Ref<State> new_state = state_pool[id];

	if (new_state == current_state) return;
	if (current_state.is_valid()) current_state->exit();

	pre_state = current_state;
	current_state = new_state;


	if (current_state.is_valid()) current_state->enter();

	godot::String from_state = pre_state.is_valid() ? pre_state->get_state_name() : "None";
	godot::String to_state = current_state.is_valid() ? current_state->get_state_name() : "None";

	emit_signal("state_changed", from_state, to_state);

	godot::UtilityFunctions::print("State changed: ", from_state, " -> ", to_state);
}

void StateMachine::bind_player_data(godot::Ref<PlayerData> player_data_)
{
	player_data = player_data_;
	godot::Array keys = state_pool.keys();
	for (int i = 0; i < keys.size(); i++) {
		godot::String state_name = keys[i];
		godot::Ref<State> state = state_pool[state_name];
		if (state.is_valid()) {
			if (player_data.is_valid()) state->bind_player_data(player_data);
		}
	}
}

void StateMachine::bind_player_animation(AnimatedSprite2D* player_anima)
{
	godot::Array keys = state_pool.keys();
	for (int i = 0; i < keys.size(); i++) {
		godot::String state_name = keys[i];
		godot::Ref<State> state = state_pool[state_name];
		if (state.is_valid()) {
			if (player_anima != nullptr) state->bind_player_animation(player_anima);
		}
	}
}

void StateMachine::start()
{
	godot::Array keys = state_pool.keys();
	for (int i = 0; i < keys.size(); i++) {
		godot::String state_name = keys[i];

		godot::Ref<State> state = state_pool[state_name];
		if (state.is_valid()) {
			state->set_state_machine(this);
			state->set_owner(owner);
			UtilityFunctions::print("set state_machine");
			state->set_state_name(state_name);
			if (player_data.is_valid())
			{
				UtilityFunctions::print("bind player data");
				state->bind_player_data(player_data);
			}
		}

	}
}



void StateMachine::_ready()
{	
	UtilityFunctions::print("set state_machine");
	owner = get_parent();
}

void StateMachine::_process(double delta) {
	if (current_state.is_valid() && !godot::Engine::get_singleton()->is_editor_hint()) { //!Engine::get_singleton()->is_editor_hint() Æô¶¯ÓÎÏ·
		current_state->update(delta);
	}
}

void StateMachine::_physics_process(double delta) {

	if (current_state.is_valid() && !godot::Engine::get_singleton()->is_editor_hint()) {
		current_state->physics_update(delta);
	}
}

void StateMachine::_input(const godot::Ref<godot::InputEvent>& event) {


	if (current_state.is_valid() && !godot::Engine::get_singleton()->is_editor_hint()) {
		current_state->handle_input(event);
	}
}
