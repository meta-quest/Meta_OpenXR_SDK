#pragma once

#if defined(ANDROID)
#include <EGL/egl.h>
#include <EGL/eglext.h>
#include <GLES3/gl3.h>
#include <GLES3/gl3ext.h>

#define XR_USE_GRAPHICS_API_OPENGL_ES 1
#define XR_USE_PLATFORM_ANDROID 1
#else
#include "unknwn.h"
#include "Render/GlWrapperWin32.h"
#define XR_USE_GRAPHICS_API_OPENGL 1
#define XR_USE_PLATFORM_WIN32 1
#endif // defined(ANDROID)

#include <openxr/openxr.h>
#include <meta_openxr_preview/openxr_oculus_helpers.h>
#include <openxr/openxr_platform.h>

void AppInput_init(App& app);
void AppInput_shutdown();
void AppInput_syncActions(App& app);

extern XrActionStateBoolean boolState;

extern bool leftControllerActive;
extern bool rightControllerActive;

extern XrSpace leftControllerAimSpace;
extern XrSpace rightControllerAimSpace;
extern XrSpace leftControllerGripSpace;
extern XrSpace rightControllerGripSpace;
