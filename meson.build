project('Egoheim', 'cpp', default_options: ['cpp_std=c++20'])

# Dependencies
dep = []
sdl2 = dependency('sdl2', required: true)
dep += sdl2

if host_machine.system() == 'windows'
    sdl2main = dependency('sdl2main', required: true)
    dep += sdl2main
endif

nlohmann_json = dependency('nlohmann_json', required: true)
dep += nlohmann_json

# Include directories
inc = include_directories('include')

# Sub-directory
subdir('src')

# Create executable
executable('egoheim', 'main.cpp', 
    dependencies: dep, 
    include_directories: inc, 
    link_with: [
        src_lib, 
        game_systems_lib, 
        game_systems_event_lib, 
        game_systems_input_lib, 
        game_systems_render_lib, 
        game_systems_resource_lib, 
        game_systems_scene_lib
    ]
)