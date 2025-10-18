extends CharacterBody2D

@onready var state_machine = $StateMachine
@onready var animation = $AnimatedSprite2D

var player_data = PlayerData.new()
var state : String = "none"

func _ready():
	# 添加状态
	#state_machine.init_player_data
	# 先检查 state_machine 是否存在
	player_data.velocity = Vector2.ZERO;
	player_data.tool_type = 1
	
	if state_machine == null:
		print("错误：StateMachine 节点未找到！路径可能错误")
		return  # 如果节点不存在，后续代码无需执行
	state_machine.add_state("Idle", IdleState.new())
	state_machine.add_state("Move", MoveState.new())
	state_machine.add_state("Chopping", ChoppingState.new())
	state_machine.add_state("Watering", WateringState.new())
	state_machine.add_state("Tilling", TillingState.new())
	state_machine.start()
	state_machine.bind_player_data(player_data)
	state_machine.bind_player_animation(animation)
	# 设置初始状态
	state_machine.state_changed.connect(_on_state_changed)
	state_machine.change_state("Idle")

	
func _on_state_changed(from_state, to_state):
	state = to_state
	print("State changed from ", from_state, " to ", to_state)


func _physics_process(_delta: float) -> void:
	if state_machine == null:
		print("错误：StateMachine 节点未找到！路径可能错误")
		return  # 如果节点不存在，后续代码无需执行d
	velocity = player_data.velocity 
	move_and_slide()
	
