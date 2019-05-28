// Copyright (c) 2013-2016, Stoyan Nikolov
// All rights reserved.
// Voxels Library, please see LICENSE for licensing details.
#pragma once

#ifdef _WIN32

    #ifdef VOXELS_EXPORT
        #define VOXELS_API __declspec(dllexport)
    #else
        #define VOXELS_API __declspec(dllimport)
    #endif

    #define VOXELS_CDECL __cdecl

#else

    #ifdef VOXELS_EXPORT
        #define VOXELS_API __attribute__((visibility("default")))
    #else
        #define VOXELS_API
    #endif

    #define VOXELS_CDECL

#endif
