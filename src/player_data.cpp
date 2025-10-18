#include"player_data.h"


void PlayerData::_bind_methods()
{	
	BIND_ENUM_CONSTANT(ToolsType::NONE);
	BIND_ENUM_CONSTANT(ToolsType::AXE);
	BIND_ENUM_CONSTANT(ToolsType::WATER);
	BIND_ENUM_CONSTANT(ToolsType::HOE);

	ClassDB::bind_method(D_METHOD("set_direction", "dire"), &PlayerData::set_direction);
	ClassDB::bind_method(D_METHOD("get_direction"), &PlayerData::get_direction);
	ADD_PROPERTY(PropertyInfo(Variant::VECTOR2, "direction"), "set_direction", "get_direction");

	ClassDB::bind_method(D_METHOD("set_velocity", "velo"), &PlayerData::set_velocity);
	ClassDB::bind_method(D_METHOD("get_velocity"), &PlayerData::get_velocity);
	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "velocity"), "set_velocity", "get_velocity");

	ClassDB::bind_method(D_METHOD("set_player_tools", "tool_type"), &PlayerData::set_player_tools);
	ClassDB::bind_method(D_METHOD("get_player_tools"), &PlayerData::get_player_tools);

	ADD_PROPERTY(PropertyInfo(Variant::INT, "tool_type", PROPERTY_HINT_ENUM, "NONE,AXE,WETER,HOE"), "set_player_tools","get_player_tools");
}



Vector2 PlayerData::get_direction()
{
	return direction;
}

void PlayerData::set_direction(const Vector2& dire)
{
	direction = dire;
}

Vector2 PlayerData::get_velocity()
{
	return velocity;
}

void PlayerData::set_velocity(const Vector2& velo)
{
	velocity = velo;
}

int PlayerData::get_player_tools()
{
	return (int)player_tools;
}

void PlayerData::set_player_tools(int tool_type)
{
	player_tools = (ToolsType)tool_type;
}
