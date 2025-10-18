#include<godot_cpp/classes/ref.hpp>
#include<godot_cpp/variant/dictionary.hpp>
#include<godot_cpp/core/class_db.hpp>
#include<godot_cpp/classes/node.hpp>
#include <godot_cpp/classes/engine.hpp>
#include <godot_cpp/variant/utility_functions.hpp>
#include <godot_cpp/classes/object.hpp>


#include"state.h"
#include"player_data.h"

class StateMachine : public godot::Node
{
	GDCLASS(StateMachine, Node);
public:
	StateMachine()
	{
		current_state = godot::Ref<State>();
		pre_state = godot::Ref<State>();
		player_data = godot::Ref<PlayerData>();
	}
	void add_state(const godot::String& id, const godot::Ref<State> state);
	void change_state(const godot::String& id);
	void bind_player_data(godot::Ref<PlayerData> player_data_);
	void bind_player_animation(AnimatedSprite2D* player_anima);
	void start();

	void _ready() override;
	void _process(double delta) override;
	void _physics_process(double delta) override;
	void _input(const godot::Ref<godot::InputEvent>& event) override;

	
protected:
	static void _bind_methods();

private:
	godot::Ref<State> current_state;
	godot::Ref<State> pre_state;
	godot::Ref<PlayerData> player_data;
	godot::Dictionary state_pool;
	godot::Node* owner = nullptr;
};

