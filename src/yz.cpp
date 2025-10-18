#include"yz.h"
#include<godot_cpp/core/class_db.hpp>

using namespace godot;

double YZ::get_hp()
{
	return hp;
}

void YZ::set_hp(double hp_)
{

	hp = hp_;
}

void YZ::_bind_methods()
{
	ClassDB::bind_method(D_METHOD("add", "x", "y"), &add);
	ClassDB::bind_method(D_METHOD("get_hp"), &get_hp);
	ClassDB::bind_method(D_METHOD("set_hp","hp_"), &get_hp);
	

	ADD_PROPERTY(PropertyInfo(Variant::FLOAT, "hp"),"set_hp","get_hp");
}

double YZ::add(double a, double b)
{
	return a + b;
}