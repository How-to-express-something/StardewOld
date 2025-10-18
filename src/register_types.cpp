#include"register_types.h"

#include <gdextension_interface.h>

#include <godot_cpp/core/class_db.hpp>
#include <godot_cpp/core/defs.hpp>
#include <godot_cpp/godot.hpp>

#include"YZ.h"
#include"state.h"
#include"state_machine.h"
#include"player_state.h"
#include"player_data.h"
#include"player_tools.h"
using namespace godot;

void initialize_YZ_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}

	ClassDB::register_class<YZ>();
	ClassDB::register_class<State>();
	ClassDB::register_class<StateMachine>();
	ClassDB::register_class<IdleState>();
	ClassDB::register_class<MoveState>();
	ClassDB::register_class<ChoppingState>();
	ClassDB::register_class<WateringState>();
	ClassDB::register_class<TillingState>();
	ClassDB::register_class<PlayerData>();
}

void uninitialize_YZ_module(ModuleInitializationLevel p_level) {
	if (p_level != MODULE_INITIALIZATION_LEVEL_SCENE) {
		return;
	}
}

extern "C" {
	// Initialization.
	GDExtensionBool GDE_EXPORT YZ_library_init(GDExtensionInterfaceGetProcAddress p_get_proc_address, GDExtensionClassLibraryPtr p_library, GDExtensionInitialization* r_initialization) {
		godot::GDExtensionBinding::InitObject init_obj(p_get_proc_address, p_library, r_initialization);

		init_obj.register_initializer(initialize_YZ_module);
		init_obj.register_terminator(uninitialize_YZ_module);
		init_obj.set_minimum_library_initialization_level(MODULE_INITIALIZATION_LEVEL_SCENE);

		printf("GDExtension init called\n");
		GDExtensionBool result = init_obj.init();
		printf("GDExtension init result: %d\n", result);
		return result;
	}
}