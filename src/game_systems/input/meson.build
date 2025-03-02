game_systems_input_files = ['ControllerInputConfig.cpp', 'DesktopInputConfig.cpp', 'InputManager.cpp']

game_systems_input_lib = static_library(
    'game_systems_input_lib', 
    game_systems_input_files, 
    include_directories: [inc, include_directories('../../../include/game_systems/input')], 
    dependencies: [sdl2, nlohmann_json]
)