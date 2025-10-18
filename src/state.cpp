#include "state.h"

void State::_bind_methods()
{
	godot::ClassDB::bind_method(godot::D_METHOD("enter"),&State::enter);
	godot::ClassDB::bind_method(godot::D_METHOD("exit"),&State::exit);
	godot::ClassDB::bind_method(godot::D_METHOD("update","delta"), &State::update);
	godot::ClassDB::bind_method(godot::D_METHOD("physics_update","delta"), &State::physics_update);
	godot::ClassDB::bind_method(godot::D_METHOD("handle_input", "event"), &State::handle_input);

	ADD_SIGNAL(godot::MethodInfo("state_entered"));
	ADD_SIGNAL(godot::MethodInfo("state_exited"));

	godot::ClassDB::bind_method(godot::D_METHOD("set_state_name", "name_"), &State::set_state_name);
	godot::ClassDB::bind_method(godot::D_METHOD("get_state_name"), &State::get_state_name);
	ADD_PROPERTY(godot::PropertyInfo(godot::Variant::STRING,"state_name"), "set_state_name", "get_state_name");

	/*godot::ClassDB::bind_method(godot::D_METHOD("set_state_machine","state_machine_"), &State::set_state_machine);
	godot::ClassDB::bind_method(godot::D_METHOD("set_owner","owner"), &State::set_owner);*/
}

void State::set_state_name(const godot::String& name_)
{
	state_name = name_;
}

godot::String State::get_state_name()
{
	return state_name;
}

void State::set_state_machine(StateMachine* state_machine_)
{
	state_machine = state_machine_;
}

void State::set_owner(godot::Node* owner)
{

	node = owner;
}

void State::bind_player_data(godot::Ref<PlayerData> player_data_)
{

	player_data = player_data_;
}

void State::bind_player_animation(AnimatedSprite2D* player_anima)
{
	player_animation = player_anima;
}
