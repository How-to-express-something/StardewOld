#pragma once
#include"state.h"


using namespace godot;

class IdleState : public State
{
	GDCLASS(IdleState, State)
public:
	IdleState()
	{
		String str = "Idle";
		set_state_name(str);
	}

	void exit() override
	{
		player_animation->stop();
	}
	void physics_update(double delta) override;
	void handle_input(const godot::Ref<godot::InputEvent>& event) override;
protected:
	static void _bind_methods();

private:

};

class MoveState : public State
{
	GDCLASS(MoveState, State)
public:
	MoveState()
	{
		state_name = "Move";
	}
	void handle_input(const godot::Ref<godot::InputEvent>& event) override;
	void physics_update(double delta) override;
	void exit() override
	{	
		player_animation->stop();
		player_data->set_velocity(ZERO);
	}

	
	
protected:
	static void _bind_methods();
	

private:
	int speed = 50;

	void move();
};

class ChoppingState : public State
{
	GDCLASS(ChoppingState, State)
public:
	ChoppingState()
	{
		state_name = "Chopping";
	}

	void enter() override;
	void exit() override;
	void physics_update(double delta) override;

protected:
	static void _bind_methods();
private:

};

class WateringState : public State
{
	GDCLASS(WateringState, State)
public:
	WateringState()
	{
		state_name = "Watering";
	}

	void enter() override;
	void exit() override;
	void physics_update(double delta) override;
protected:
	static void _bind_methods();
private:

};

class TillingState : public State
{
	GDCLASS(TillingState, State)
public:
	TillingState()
	{
		state_name = "Tilling";
	}

	void enter() override;
	void exit() override;
	void physics_update(double delta) override;
protected:
	static void _bind_methods();
private:

};