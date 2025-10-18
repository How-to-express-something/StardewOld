extends Node2D

var house_scence = preload("res://scenes/Houses/house_tile_map.tscn")

@onready var player: CharacterBody2D = $"../Player"




	
	
func on_interactable_activated() -> void:
	add_house_scence()
	
func add_house_scence() ->void:
	var instance = house_scence.instantiate() as Node2D
	get_parent().add_child(instance)
	


func _physics_process(_delta: float) -> void:
	if(Input.is_action_pressed("test")) :
		call_deferred("add_house_scence")
		player.global_position = Vector2(9,18)
		queue_free()
	
