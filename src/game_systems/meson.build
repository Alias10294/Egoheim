subdir('event')
subdir('input')
subdir('render')
subdir('resource')
subdir('scene')

game_systems_files = ['GameContext.cpp']

game_systems_lib = static_library(
    'game_systems_lib', 
    game_systems_files, 
    include_directories: [inc, include_directories('../../include/game_systems')], 
    dependencies: dep,
)