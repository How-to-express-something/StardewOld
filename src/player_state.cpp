#include"player_state.h"
#include"state_machine.h"

//const godot::Vector2 LEFT = godot::Vector2(-1, 0);
//const godot::Vector2 RIGHT = godot::Vector2(1, 0);
//const godot::Vector2 UP = godot::Vector2(0, -1);
//const godot::Vector2 DOWN = godot::Vector2(0, 1);
//const godot::Vector2 ZERO = godot::Vector2(0, 0);

void animation_play(AnimatedSprite2D* ani, const Vector2& direction, const String& state)
{	
	if (ani == nullptr)
	{
		UtilityFunctions::print("player_animation failed to set");
		return;
	}
	String name;
	if (direction == Vector2(-1,0)) name = state + String("_left");
	else if (direction == Vector2(1,0)) name = state + String("_right");
	else if (direction == Vector2(0,-1)) name = state + String("_back");
	else if (direction == Vector2(0,1)) name = state + String("_front");

	ani->play(name);
}


void IdleState::_bind_methods()
{
}


void IdleState::handle_input(const godot::Ref<godot::InputEvent>& event)
{	
	
	if (event.is_valid() && event->is_pressed()) {
		Input* input = Input::get_singleton();

		if (input->is_action_pressed("walk_left")) 
		{
			player_data->set_direction(LEFT);
			if (state_machine != nullptr) state_machine->change_state("Move");
			else UtilityFunctions::print("state_machine failed to set");
			
		}
		else if (input->is_action_pressed("walk_right"))
		{
			player_data->set_direction(RIGHT);
			if (state_machine != nullptr) state_machine->change_state("Move");
			else UtilityFunctions::print("state_machine failed to set");
			
		}
		else if (input->is_action_pressed("walk_up"))
		{
			player_data->set_direction(UP);
			if (state_machine != nullptr) state_machine->change_state("Move");
			else UtilityFunctions::print("state_machine failed to set");
		}
		else if (input->is_action_pressed("walk_down"))
		{
			player_data->set_direction(DOWN);
			if (state_machine != nullptr) state_machine->change_state("Move");
			else UtilityFunctions::print("state_machine failed to set");
		}
		else if (input->is_action_just_pressed("left_click"))
		{	
			UtilityFunctions::print("left_click");
			switch (player_data->get_player_tools())
			{
			case PlayerData::ToolsType::AXE:
				UtilityFunctions::print("AXE");
				if (state_machine != nullptr) state_machine->change_state("Chopping");
				else UtilityFunctions::print("state_machine failed to set");
				break;
			case PlayerData::ToolsType::WATER:
				if (state_machine != nullptr) state_machine->change_state("Watering");
				else UtilityFunctions::print("state_machine failed to set");
				break;
			case PlayerData::ToolsType::HOE:
				if (state_machine != nullptr) state_machine->change_state("Tilling");
				else UtilityFunctions::print("state_machine failed to set");
				break;
			case PlayerData::ToolsType::NONE:
				break;
			default:
				break;
			}
		}
	}
}

void IdleState::physics_update(double delta)
{
	animation_play(player_animation, player_data->get_direction(), "idle");
}



void MoveState::handle_input(const godot::Ref<godot::InputEvent>& event)
{
	if (event.is_valid() && event->is_pressed()) {
		Input* input = Input::get_singleton();

		if (input->is_action_just_pressed("left_click"))
		{
			UtilityFunctions::print("left_click");
			switch (player_data->get_player_tools())
			{
			case PlayerData::ToolsType::AXE:
				UtilityFunctions::print("AXE");
				if (state_machine != nullptr) state_machine->change_state("Chopping");
				else UtilityFunctions::print("state_machine failed to set");
				break;
			case PlayerData::ToolsType::WATER:
				if (state_machine != nullptr) state_machine->change_state("Watering");
				else UtilityFunctions::print("state_machine failed to set");
				break;
			case PlayerData::ToolsType::HOE:
				if (state_machine != nullptr) state_machine->change_state("Tilling");
				else UtilityFunctions::print("state_machine failed to set");
				break;
			case PlayerData::ToolsType::NONE:
				break;
			default:
				break;
			}
		}
	}
}

void MoveState::physics_update(double delta)
{
	move();
	animation_play(player_animation, player_data->get_direction(), "walk");
	
}
void MoveState::move()
{
	Input* input = Input::get_singleton();
	bool any_move_key = false;
	Vector2 velo;

	if (input->is_action_pressed("walk_up"))
	{	
		velo += UP; any_move_key = true;
		player_data->set_direction(UP);
	}
	if (input->is_action_pressed("walk_left"))
	{

		velo += LEFT; any_move_key = true;
		player_data->set_direction(LEFT);

	}
	if (input->is_action_pressed("walk_right"))
	{
		velo += RIGHT; any_move_key = true;
		player_data->set_direction(RIGHT);
	}
	if (input->is_action_pressed("walk_down"))
	{
		velo += DOWN; any_move_key = true;
		player_data->set_direction(DOWN);
	}

	if (!any_move_key)
	{
		UtilityFunctions::print("no key input");

		if (state_machine != nullptr) state_machine->change_state("Idle");
		else UtilityFunctions::print("state_machine failed to set");
	}
	else
	{
		velo.normalize();
		player_data->set_velocity(velo * speed);
	}
}


void MoveState::_bind_methods()
{
}

void ChoppingState::_bind_methods()
{
}
void ChoppingState::enter()
{
	animation_play(player_animation, player_data->get_direction(), "chopping");
}

void ChoppingState::exit()
{
	player_animation->stop();
}

void ChoppingState::physics_update(double delta)
{	
	if (!player_animation->is_playing()) state_machine->change_state("Idle");
}

void WateringState::_bind_methods()
{
}

void WateringState::enter()
{
	animation_play(player_animation, player_data->get_direction(), "watering");
}

void WateringState::exit()
{
	player_animation->stop();
}

void WateringState::physics_update(double delta)
{
	if (!player_animation->is_playing()) state_machine->change_state("Idle");
}

void TillingState::_bind_methods()
{
}

void TillingState::enter()
{
	animation_play(player_animation, player_data->get_direction(), "tilling");
}

void TillingState::exit()
{
	player_animation->stop();
}

void TillingState::physics_update(double delta)
{	
	
	if (!player_animation->is_playing()) state_machine->change_state("Idle");
}