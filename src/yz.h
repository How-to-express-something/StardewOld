#pragma once
#include<godot_cpp/classes/ref_counted.hpp>

using namespace godot;

class YZ : public RefCounted
{
	GDCLASS(YZ, RefCounted);

public:
	double add(double a, double b);
	double hp = 100.0;
	double get_hp();
	void set_hp(double hp_);

protected:
	static void _bind_methods();

private:

};

