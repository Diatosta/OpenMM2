cmake_minimum_required(VERSION 3.10 FATAL_ERROR)

add_subdirectory(ageaudio)
add_subdirectory(ai)
add_subdirectory(aud)
add_subdirectory(banger)
add_subdirectory(bank)
add_subdirectory(camera)
add_subdirectory(city)
add_subdirectory(core)
add_subdirectory(cranimation)
add_subdirectory(crbody)
add_subdirectory(crskeleton)
add_subdirectory(data)
add_subdirectory(dgragdoll)
add_subdirectory(directmusic)
add_subdirectory(djpeg)
add_subdirectory(effects)
add_subdirectory(gfx)
add_subdirectory(gizmo)
add_subdirectory(input)
add_subdirectory(level)
add_subdirectory(lights)
add_subdirectory(localize)
add_subdirectory(memory)
add_subdirectory(mmaudio)
add_subdirectory(mmcityinfo)
add_subdirectory(mmeffects)
add_subdirectory(mmgame)
add_subdirectory(mminput)
add_subdirectory(mmnetwork)
add_subdirectory(mmui)
add_subdirectory(mmwidget)
add_subdirectory(model)
add_subdirectory(node)
add_subdirectory(parse)
add_subdirectory(ped)
add_subdirectory(phbound)
add_subdirectory(phcollide)
add_subdirectory(phcore)
add_subdirectory(phinertia)
add_subdirectory(phys)
add_subdirectory(rgl)
add_subdirectory(vector)
add_subdirectory(vehicle)
add_subdirectory(x86)
add_subdirectory(zipfile)

add_library(hooking STATIC
    hooking.cpp
    hooking.h
)

target_link_libraries(hooking mem)

add_library(testgame STATIC
    testgame.cpp
    testgame.h
)

target_link_libraries(testgame
    hooking

    ageaudio
    ai
    aud
    banger
    bank
    camera
    city
    core
    cranimation
    crbody
    crskeleton
    data
    dgragdoll
    directmusic
    djpeg
    effects
    gfx
    gizmo
    input
    level
    lights
    localize
    memory
    mmaudio
    mmcityinfo
    mmeffects
    mmgame
    mminput
    mmnetwork
    mmui
    mmwidget
    model
    node
    parse
    ped
    phbound
    phcollide
    phcore
    phinertia
    phys
    rgl
    vector
    vehicle
    x86
    zipfile
)