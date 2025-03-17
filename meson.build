project('Egoheim', 'cpp', default_options: ['cpp_std=c++20'])

# Dependencies
dep = []
sdl2 = dependency('sdl2', fallback: ['sdl2', 'sdl2_dep'])
dep += sdl2

nlohmann_json = dependency('nlohmann_json', fallback: ['nlohmann_json', 'nlohmann_json_dep'])
dep += nlohmann_json

sdl2_image = dependency('sdl2_image', fallback: ['sdl2_image', 'sdl2_image_dep'])
dep += sdl2_image

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