#pragma once

#include<godot_cpp/core/class_db.hpp>
#include<godot_cpp/classes/resource.hpp>
#include"player_tools.h"



using namespace godot;

class PlayerData : public Resource
{
	GDCLASS(PlayerData,Resource)

public:

	enum  ToolsType
	{
		NONE = 0,
		AXE = 1,
		WATER = 2,
		HOE = 3
	};


	Vector2 direction;
	Vector2 velocity;
	ToolsType player_tools;

	Vector2 get_direction();
	void set_direction(const Vector2& dire);

	Vector2 get_velocity();
	void set_velocity(const Vector2& dire);

	int get_player_tools();
	void set_player_tools(int tool_type);

	
	
protected:
	static void _bind_methods();

private:
	
};


VARIANT_ENUM_CAST(PlayerData::ToolsType);