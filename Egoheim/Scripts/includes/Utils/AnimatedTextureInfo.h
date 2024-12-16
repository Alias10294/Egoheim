#ifndef ANIMATEDTEXTUREINFO_H
#define ANIMATEDTEXTUREINFO_H

#include <iostream>
#include <vector>

struct AnimatedTextureInfo
{
	const int nbFrames;
	const float* frameTimes;
	const bool autonomy = true;
};

#endif ANIMATEDTEXTUREINFO_H