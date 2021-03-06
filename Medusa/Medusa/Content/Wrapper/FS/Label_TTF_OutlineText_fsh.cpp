//This file was created by FileWrapper 1.0.0.0
//DO NOT EDIT
#include "MedusaPreCompiled.h"
#include "Core/IO/MemoryFileAutoRegister.h"
#pragma region Label_TTF_OutlineText.fsh
MEDUSA_CONTENT_BEGIN;
const static char _Label_TTF_OutlineText_fsh[] = "\
#ifndef GL_ES \n\
#define lowp\n\
#define mediump\n\
#define highp\n\
#else\n\
precision lowp float; \n\
#endif\n\
\n\
\n\
uniform sampler2D uTextureSampler;\n\
uniform highp vec4 uTextColor;\n\
uniform highp vec4 uOutlineColor;\n\
\n\
varying  mediump vec2	vTexCoord;\n\
varying lowp vec4 vColor;\n\
\n\
void main (void)\n\
{\n\
	lowp vec4 texColor=texture2D(uTextureSampler,vTexCoord);	//a:text r:outline\n\
	float textAlpha = texColor.a; \n\
    float outlineAlpha = texColor.r; \n\
\n\
	vec4 outlineColor=uOutlineColor*outlineAlpha;\n\
	vec4 textColor=uTextColor*textAlpha;\n\
\n\
	vec4 resultColor=textColor*textColor.a+outlineColor*outlineColor.a*(1.0-textColor.a);\n\
	resultColor.a=textColor.a+outlineColor.a*(1.0-textColor.a);\n\
	//resultColor.rgb/=resultColor.a;\n\
		\n\
	gl_FragColor =vColor*resultColor;\n\
}\n\
";
//const static MemoryFileAutoRegister mRegister_Label_TTF_OutlineText_fsh(FileIdRef("Label_TTF_OutlineText.fsh"),_Label_TTF_OutlineText_fsh);
static void Register_Label_TTF_OutlineText_fsh(){MemoryFileAutoRegister::Register(FileIdRef("Label_TTF_OutlineText.fsh"),_Label_TTF_OutlineText_fsh);}
MEDUSA_CONTENT_END;
#pragma endregion Label_TTF_OutlineText.fsh

